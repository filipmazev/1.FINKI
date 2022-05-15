#include <iostream>
#include <string.h>

#define MAX_USERS 5
#define ERRORS 3

enum error { password_error, email_error, max_users_error };

class User {
protected:
    char* username{ nullptr }, * password{ nullptr }, * email{ nullptr };
public:
    User() {}

    User(char* username, char* password, char* email) {
        this->username = new char[strlen(username) + 1]; strcpy(this->username, username);
        this->password = new char[strlen(password) + 1]; strcpy(this->password, password);
        this->email = new char[strlen(email) + 1]; strcpy(this->email, email);
    }

    User(const User& u) {
        if (this != &u) {
            delete[] username;  this->username = new char[strlen(u.username) + 1]; strcpy(this->username, u.username);
            delete[] password;  this->password = new char[strlen(u.password) + 1]; strcpy(this->password, u.password);
            delete[] email; this->email = new char[strlen(u.email) + 1]; strcpy(this->email, u.email);
        }
    }

    ~User() {
        if (this->username != nullptr) { delete[] this->username; this->username = nullptr; }
        if (this->password != nullptr) { delete[] this->password; this->password = nullptr; }
        if (this->email != nullptr) { delete[] this->email; this->email = nullptr; }
    }

    inline virtual double popularity() = 0;
};

class FacebookUser : public User {
private:
    int friends_num{ int() }, likes_num{ int() }, comments_num{ int() };
public:
    FacebookUser() : User() {}

    FacebookUser(char* username, char* password, char* email, int friends_num, int likes_num, int comments_num) : User(username, password, email) {
        this->friends_num = friends_num; this->likes_num = likes_num; this->comments_num = comments_num;
    }

    FacebookUser(const FacebookUser& fb_user) : User(fb_user.username, fb_user.password, fb_user.email) {
        if (this != &fb_user) { this->friends_num = fb_user.friends_num; this->likes_num = fb_user.likes_num; this->comments_num = fb_user.comments_num; }
    }

    ~FacebookUser() {}

    inline double popularity() {
        return this->friends_num + (this->likes_num * 0.1) + (this->comments_num * 0.5);
    }
};

class TwitterUser : public User {
private:
    int followers_num{ int() }, tweets_num{ int() };
public:
    TwitterUser() : User() {}

    TwitterUser(char* username, char* password, char* email, int followers_num, int tweets_num) : User(username, password, email) {
        this->followers_num = followers_num; this->tweets_num = tweets_num;
    }

    TwitterUser(const TwitterUser& tw_user) : User(tw_user.username, tw_user.password, tw_user.email) {
        if (this != &tw_user) { this->followers_num = tw_user.followers_num; this->tweets_num = tw_user.tweets_num; }
    }

    ~TwitterUser() {}

    inline double popularity() {
        return this->followers_num + (this->tweets_num * 0.5);
    }
};

class SocialNetwork {
private:
    User** ptr_arr{ nullptr }; int num{ 0 }, max_users{ MAX_USERS };
public:
    SocialNetwork() {}

    inline SocialNetwork operator += (User* user) {
        User** tmp = new User * [this->num + 1];
        for (unsigned int i = 0; i < this->num; i++) { tmp[i] = this->ptr_arr[i]; }
        tmp[this->num++] = user; delete[] this->ptr_arr; this->ptr_arr = new User * [this->num]; this->ptr_arr = tmp;
        return *this;
    }

    inline double avgPopularity() noexcept {
        double sum = 0.00;  for (int i = 0; i < this->num; i++) {
            sum += this->ptr_arr[i]->popularity();
        }
        return sum / this->num;
    }

    inline void changeMaximumSize(int max_users) { this->max_users = max_users; }

    int getMaxUsers() { return this->max_users; }

    int getNum() { return this->num; }

};

class InvalidPassword {
public:
    void message(const char* str) { std::cout << str << std::endl; }
};

class InvalidEmail {
public:
    void message(const char* str) { std::cout << str << std::endl; }
};

class MaximumSizeLimit {
public:
    void message(int num) { std::cout << "You can't add more than " << num << " users." << std::endl; }
};

inline bool check_for_errors(char* password, char* email, int pos, int _max) noexcept {
    try {
        bool uppercase = false, lowercase = false, numeric = false, * error_arr = new bool[ERRORS]; int cnt_email = 0;

        for (int i = 0; i < ERRORS; i++) { error_arr[i] = false; }

        for (unsigned int i = 0; i < strlen(password); i++) {
            if (uppercase == false) { if (isalpha(password[i]) && isupper(password[i])) { uppercase = true; } }
            if (lowercase == false) { if (isalpha(password[i]) && islower(password[i])) { lowercase = true; } }
            if (numeric == false) { if (isalnum(password[i]) && !isalpha(password[i])) { numeric = true; } }
        }

        for (unsigned int i = 0; i < strlen(email); i++) { if (email[i] == '@') { cnt_email++; } }

        if ((uppercase == false) || (lowercase == false) || (numeric == false)) { error_arr[password_error] = true; }
        if (cnt_email != 1) { error_arr[email_error] = true; }
        if (pos > _max) { error_arr[max_users_error] = true; }

        if ((error_arr[password_error] == true) || (error_arr[email_error] == true) || (error_arr[max_users_error] == true)) { throw(error_arr); }

        else { return false; }
    }

    catch (bool* errors) {
        if (errors[password_error] == true) { InvalidPassword error; error.message("Password is too weak."); }
        if (errors[email_error] == true) { InvalidEmail error; error.message("Mail is not valid."); }
        if (errors[max_users_error] == true) { MaximumSizeLimit error; error.message(_max); }
        return true;
    }
}

int main() {
    SocialNetwork network = SocialNetwork(); int n, userType; char username[50], password[50], email[50]; std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cin >> username >> password >> email >> userType;

        if (userType == 1) {
            int friends, likes, comments; std::cin >> friends >> likes >> comments;

            if (check_for_errors(password, email, network.getNum() + 1, network.getMaxUsers()) == false) {
                User* u = new FacebookUser(username, password, email, friends, likes, comments); network += u;
            }
        }

        else {
            int followers, tweets; std::cin >> followers >> tweets;

            if (check_for_errors(password, email, network.getNum() + 1, network.getMaxUsers()) == false) {
                User* u = new TwitterUser(username, password, email, followers, tweets); network += u;
            }
        }
    }

    network.changeMaximumSize(6); int followers, tweets; std::cin >> username >> password >> email >> followers >> tweets;

    if (check_for_errors(password, email, network.getNum() + 1, network.getMaxUsers()) == false) {
        User* u = new TwitterUser(username, password, email, followers, tweets); network += u;
    }

    std::cout << network.avgPopularity(); return 0;
}