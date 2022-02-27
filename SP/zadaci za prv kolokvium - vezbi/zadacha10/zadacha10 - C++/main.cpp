#include <iostream>
#include <vector>
using namespace std;

int checker(int number, int number_org, int prev)
{
    if(number==0){ return number_org; }

    if(number/10>0){ if(((number%10 >= (number/10)%10)?1:0) == prev) { return 0; } }

    checker(number/10, number_org, ((number%10 >= (number/10)%10)?1:0));
}

int main()
{
    int number; cin>>number; vector<int> storage;

    while(!cin.fail())
    {
        cin>>number;

            if(number>=10){ int status = ((number%10 <= (number/10%10))?1:0);

            storage.push_back(checker(number,number,status)); }
    }


    for(unsigned int i=0; i<storage.size(); i++){ if(storage[i] !=0 ){ cout<<storage[i]; } }

    return 0;
}
