#include <iostream>
#include <vector>
using namespace std;

int checker(int number, int number_original, int status)
{
    if (number == 0){ return number_original; }

    if(number/10>0){ if(((number%10 < 5)?1:0) == status || number%10 == (number/10) % 10){ return 0; } }

    return checker(number/10, number_original, ((number%10 < 5)?1:0));
}

int main()
{
    int number; vector<int> storage;

    while(!cin.fail())
    {
        cin>>number;

        int status = (((number%10) >= 5)?1:0);

        if(number>10){ storage.push_back(checker(number,number,status)); }
    }

    for(unsigned int i=0; i<storage.size(); i++){ if( storage[i] != 0) { cout<<storage[i]<<endl; } }

    return 0;
}
