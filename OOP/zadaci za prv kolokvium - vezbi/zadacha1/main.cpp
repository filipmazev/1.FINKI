#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

enum tip {pop, rap, rok};

class Song
{
private:
    char song_name[1024];
    int lenght; tip type;
public:
    Song() = default; Song(char n[1024], int l, tip t){ strcpy(song_name, n); lenght = l; type = t; } ~Song(){};
    void print(){ cout<<"\""<<song_name<<"\"-"<<lenght<<"min"<<endl; }
    int getLenght(){ return lenght; }
    tip getType(){ return type; }
};

class CD
{
private:
    vector<Song> arr;
    int song_amm, max_lenght;
public:
    CD() = default; CD(int max_l){ max_lenght = max_l; } ~CD(){};

    Song getSong(int i){ return arr[i]; }

    void addSong(Song s)
    {
        int total=0; for(int i=0; i<arr.size(); i++){ total+=arr[i].getLenght(); }
        if(arr.size()<10 && ((total+s.getLenght()) < max_lenght)){ arr.push_back(s); }
    }

    void printByType(tip type)
    {
        for(int i=0; i<arr.size(); i++){
            if((tip)arr[i].getType() == (tip)type){ getSong(i).print(); } }
    }

    int getSize(){ return (int)arr.size(); }
};

int main()
{
    int testCase; cin>>testCase; int n, length, what_type; char song_name[50];

	if(testCase == 1)
    {
        cout<<"===== Testiranje na klasata Pesna ======"<<endl;
        cin>>song_name>>length>>what_type;
        Song s(song_name,length,(tip)what_type);
		s.print();
    }

    else if(testCase == 2)
    {
        cout<<"===== Testiranje na klasata CD ======"<<endl;
		CD favourite(20); cin>>n;
			for (int i=0;i<n;i++)
			{
                cin>>song_name>>length>>what_type;
				Song s(song_name,length,(tip)what_type);
				favourite.addSong(s);
			}
        	for (int i=0; i<n; i++){ (favourite.getSong(i)).print(); }
	}

	else if(testCase == 3)
	{
        cout<<"===== Testiranje na metodot dodadiPesna() od klasata CD ======"<<endl;
		CD favourite(20); cin>>n;
			for (int i=0;i<n;i++)
			{
                cin>>song_name>>length>>what_type;
				Song s(song_name,length,(tip)what_type);
				favourite.addSong(s);
			}

        	for (int i=0; i<favourite.getSize(); i++){ (favourite.getSong(i)).print(); }
    }

    else if(testCase == 4)
    {
        cout<<"===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======"<<endl;
		CD favourite(20); cin>>n;
			for (int i=0;i<n;i++)
			{
                cin>>song_name>>length>>what_type;
				Song s(song_name,length,(tip)what_type);
				favourite.addSong(s);
			}
        cin>>what_type;
        favourite.printByType((tip)what_type);
    }

    else if(testCase == 5)
    {
        cout<<"===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======"<<endl;
		CD favourite(20); cin>>n;
			for (int i=0;i<n;i++)
			{
				cin>>song_name>>length>>what_type;
				Song s(song_name,length,(tip)what_type);
				favourite.addSong(s);
			}
        cin>>what_type;
        favourite.printByType((tip)what_type);
    }
}
