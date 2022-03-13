#include <iostream>
#include <cstring>

enum Extension {pdf, txt, exe}; static const char *enum_to_str[] = {"pdf","txt","exe"};
char *get_enum_str(int enum_val) { char *str = new char[(size_t)(strlen(enum_to_str[enum_val])+1)]; strcpy(str,enum_to_str[enum_val]); return str; }

class File
{
private:
    char *file_name, *owner; int file_size; Extension type;
public:
    File(){}

    File(char *file_name, char *owner, int file_size, Extension type){
    this->file_name = new char[(size_t)(strlen(file_name)+1)]; strcpy(this->file_name,file_name);
    this->owner = new char[(size_t)(strlen(owner)+1)]; strcpy(this->owner,owner);
    this->file_size = file_size; this->type = type; }

    File(const File &f){
    this->file_name = new char[(size_t)(strlen(f.file_name)+1)]; strcpy(this->file_name,f.file_name);
    this->owner = new char[(size_t)(strlen(f.owner)+1)]; strcpy(this->owner,f.owner);
    this->file_size = f.file_size; this->type = f.type; }

    ~File(){}

    File &operator = (const File &f){
    this->file_name = new char[(size_t)(strlen(f.file_name)+1)]; strcpy(this->file_name,f.file_name);
    this->owner = new char[(size_t)(strlen(f.owner)+1)]; strcpy(this->owner,f.owner);
    this->file_size = f.file_size; this->type = f.type; return *this; }

    void print(){ std::cout<<"File name: "<<file_name<<"."<<get_enum_str(this->type)<<std::endl<<"File owner: "<<owner<<std::endl<<"File size: "<<file_size<<std::endl; }
    bool equalTypes(const File &f){ return ((strcmp(this->file_name,f.file_name) == 0) && (this->type == f.type)); }
    bool equals(const File &f){ return (equalTypes(f) && (strcmp(this->owner,f.owner) == 0)); }
};

class Folder
{
private:
    char *folder_name; int num=0; File *arr;
public:
    Folder(){ this->num=0; arr = nullptr; }
    Folder(char *folder_name){ this->folder_name = new char[(size_t)(strlen(folder_name)+1)]; strcpy(this->folder_name, folder_name); arr = new File[this->num]; }
    ~Folder(){ delete[] arr; }

    void add(const File &adder){
    File *tmp = new File[num+1]; for(int i=0; i<this->num; i++){ tmp[i] = this->arr[i]; }
    tmp[num++] = adder; delete[] this->arr; this->arr = tmp; }

    void del(File &sub){
        for(int i=0; i<this->num; i++){
            if(this->arr[i].equals(sub)){ --this->num;
                for(int j=i; j<this->num; j++){ this->arr[j] = this->arr[j+1]; } break; } } }

    void print(){ std::cout<<"Folder name: "<<folder_name<<std::endl; for(int i=0; i<num; i++){ arr[i].print(); } }
};

int main()
{
    char fileName[20], fileOwner[20]; int ext, fileSize, testCase; std::cin>>testCase;

	if (testCase == 1)
    {
		std::cout<<"======= FILE CONSTRUCTORS AND = OPERATOR ======="<<std::endl;

		std::cin>>fileName>>fileOwner>>fileSize>>ext;
		File created = File(fileName, fileOwner, fileSize, (Extension) ext); File copied = File(created); File assigned = created;

		std::cout<<"======= CREATED ======="<<std::endl;
		created.print(); std::cout<<std::endl;
        std::cout<<"======= COPIED ======="<<std::endl;
		copied.print(); std::cout<<std::endl;
        std::cout<<"======= ASSIGNED ======="<<std::endl;
		assigned.print();
	}

	else if (testCase == 2)
    {
		std::cout<<"======= FILE EQUALS & EQUALS TYPE ======="<<std::endl;

		std::cin>>fileName>>fileOwner>>fileSize>>ext;
		File first(fileName, fileOwner, fileSize, (Extension) ext); first.print();

		std::cin>>fileName>>fileOwner>>fileSize>>ext;
		File second(fileName, fileOwner, fileSize, (Extension) ext); second.print();

		std::cin>>fileName>>fileOwner>>fileSize>>ext;
		File third(fileName, fileOwner, fileSize, (Extension) ext); third.print();

		bool equals = first.equals(second);

		std::cout<<"FIRST EQUALS SECOND: ";
		if (equals) { std::cout<< "TRUE" <<std::endl; }
		else { std::cout<<"FALSE" <<std::endl; }

		equals = first.equals(third);
		std::cout<<"FIRST EQUALS THIRD: ";

		if (equals) { std::cout<<"TRUE"<<std::endl; }
		else { std::cout<<"FALSE"<<std::endl; }

		bool equalTypes = first.equalTypes(second);

		std::cout<<"FIRST EQUALS TYPE SECOND: ";
		if (equalTypes) { std::cout<<"TRUE"<<std::endl; }
		else { std::cout<<"FALSE"<<std::endl; }

		equalTypes = second.equals(third);
		std::cout<<"SECOND EQUALS TYPE THIRD: ";
		if (equalTypes) { std::cout<<"TRUE"<<std::endl; }
		else { std::cout<<"FALSE"<<std::endl; }
	}

	else if (testCase == 3)
    {
		std::cout<<"======= FOLDER CONSTRUCTOR ======="<<std::endl;
		std::cin>>fileName; Folder folder(fileName);folder.print();
	}

	else if (testCase == 4)
    {
		std::cout<<"======= ADD FILE IN FOLDER ======="<<std::endl;
		char name[20]; int iter;
		std::cin>>name>>iter; Folder folder(name);

		while (iter > 0) {
            std::cin>>fileName>>fileOwner>>fileSize>>ext;
			File file(fileName, fileOwner, fileSize, (Extension) ext); folder.add(file); iter--; }
		folder.print();
	}

	else
    {
		std::cout<<"======= REMOVE FILE FROM FOLDER ======="<<std::endl;
		char name[20]; int iter;
		std::cin>>name>>iter; Folder folder(name);

		while (iter > 0) {
            std::cin>>fileName>>fileOwner>>fileSize>>ext;
			File file(fileName, fileOwner, fileSize, (Extension) ext); folder.add(file); iter--; }

        std::cin>>fileName>>fileOwner>>fileSize>>ext;

		File file(fileName, fileOwner, fileSize, (Extension) ext);
		folder.del(file); folder.print();
	}

    return 0;
}
