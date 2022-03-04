#include <iostream>
#include <cstring>
using namespace std;

class Film
{
private:
    char name[100], director[50], genre[50]; int year, num=0;
public:
    Film(){};
    Film(char n[100], char d[50],char g[50], int y){
    strcpy(name,n); strcpy(director,d); strcpy(genre,g); year = y; }
    ~Film(){};

    void print(Film *arr, int n, int y_comp){
        for(int i=0; i<n; i++){ if(arr[i].year == y_comp) {
        cout<<"Ime: "<<arr[i].name<<endl<<"Reziser: "<<arr[i].director<<endl<<"Zanr: "<<arr[i].genre<<endl<<"Godina: "<<arr[i].year<<endl;  } } }
};

int main()
{
 	int n; cin>>n; Film *arr = new Film[n];

 	for(int i=0; i<n; i++)
    {
 		char name[100], director[50], genre[50]; int year;
 		cin >>name>>director>>genre>>year;
        arr[i] = Film(name,director, genre, year);
 	}

 	int godina; cin>>godina; arr[0].print(arr, n, godina); delete[] arr;

 	return 0;
 }
