#include <iostream>
#include <cstring>

enum type {pop, rap, rok};

class Song
{
private:
    char *song_name; int lenght; type song_type;
public:
    Song(){ song_name = nullptr; };
    Song(char *s_n, int l, type s_t){
    song_name = new char[(size_t)(strlen(s_n)+1)]; strcpy(song_name,s_n); lenght = l; song_type = s_t; }
    ~Song(){};

    void print(){ std::cout<<"\""<<song_name<<"\"-"<<lenght<<"min"<<std::endl; }
    int getLenght(){ return lenght; } type getType(){ return song_type; }
};

class CD
{
private:
    Song arr[10]; int song_amm, max_lenght;
public:
    CD() = default; CD(int max_l){ max_lenght = max_l; song_amm=0; } ~CD(){};

    Song getSong(int i){ return arr[i]; }

    void addSong(Song s){
        int total=0; for(int i=0; i<song_amm; i++){ total+=arr[i].getLenght(); }
        if(song_amm<10 && ((total+s.getLenght()) < max_lenght)){ arr[song_amm++] = s; } }

    void printByType(type t){
    for(int i=0; i<song_amm; i++){ if((type)arr[i].getType() == (type)t){ arr[i].print(); } } }

    int getSize(){ return song_amm; }
};

int main()
{
    int testCase; std::cin>>testCase; int n, length, what_type; char song_name[50];

	if(testCase == 1)
    {
        std::cout<<"===== Testiranje na klasata Pesna ======"<<std::endl;
        std::cin>>song_name>>length>>what_type;
        Song s(song_name,length,(type)what_type);
		s.print();
    }

    else if(testCase == 2)
    {
        std::cout<<"===== Testiranje na klasata CD ======"<<std::endl;
		CD favourite(20); std::cin>>n;
			for (int i=0;i<n;i++)
			{
                std::cin>>song_name>>length>>what_type;
				Song s(song_name,length,(type)what_type);
				favourite.addSong(s);
			}
        	for (int i=0; i<n; i++){ (favourite.getSong(i)).print(); }
	}

	else if(testCase == 3)
	{
        std::cout<<"===== Testiranje na metodot dodadiPesna() od klasata CD ======"<<std::endl;
		CD favourite(20); std::cin>>n;
			for (int i=0;i<n;i++)
			{
                std::cin>>song_name>>length>>what_type;
				Song s(song_name,length,(type)what_type);
				favourite.addSong(s);
			}

        	for (int i=0; i<favourite.getSize(); i++){ (favourite.getSong(i)).print(); }
    }

    else if(testCase == 4)
    {
        std::cout<<"===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======"<<std::endl;
		CD favourite(20); std::cin>>n;
			for (int i=0;i<n;i++)
			{
                std::cin>>song_name>>length>>what_type;
				Song s(song_name,length,(type)what_type);
				favourite.addSong(s);
			}
        std::cin>>what_type;
        favourite.printByType((type)what_type);
    }

    else if(testCase == 5)
    {
        std::cout<<"===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======"<<std::endl;
		CD favourite(20); std::cin>>n;
			for (int i=0;i<n;i++)
			{
				std::cin>>song_name>>length>>what_type;
				Song s(song_name,length,(type)what_type);
				favourite.addSong(s);
			}
        std::cin>>what_type;
        favourite.printByType((type)what_type);
    }
}
