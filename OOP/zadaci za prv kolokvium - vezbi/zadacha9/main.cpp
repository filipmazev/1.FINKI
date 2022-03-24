#include <iostream>

struct Laptop{ char manufacturer[100]; float screen_size_in; bool touch; int price; };

struct ITStore { char store_name[100], location[100]; Laptop l_arr[100]; int n; };

void print(ITStore *arr, int n)
{
    for(int i=0; i<n; i++){
    std::cout<<arr[i].store_name<<" "<<arr[i].location<<std::endl;
        for(int j=0; j<arr[i].n; j++){ float s_s = (arr[i].l_arr[j].screen_size_in-(int)arr[i].l_arr[j].screen_size_in)==0?(int)arr[i].l_arr[j].screen_size_in:arr[i].l_arr[j].screen_size_in;
        std::cout<<arr[i].l_arr[j].manufacturer<<" "<<s_s<<" "<<arr[i].l_arr[j].price<<std::endl; } }
}

void best_offer(ITStore *arr, int n)
{
    int minimum=2147483647, pos_i=0, pos_j=0; std::string message_1 = "Najeftina ponuda ima prodavnicata:", message_2 = "Najniskata cena iznesuva: ";
    for(int i=0; i<n; i++){
        for(int j=0; j<arr[i].n; j++){
            if(arr[i].l_arr[j].price<minimum && arr[i].l_arr[j].touch==1){ minimum = arr[i].l_arr[j].price; pos_i=i,pos_j=j; } } }
            std::cout<<message_1<<std::endl<<arr[pos_i].store_name<<" "<<arr[pos_i].location<<std::endl<<message_2<<arr[pos_i].l_arr[pos_j].price<<std::endl;
}

int main()
{
	int n; ITStore it_s_arr[100]; std::cin>>n;

    for (int i=0; i<n; i++){ std::cin>>it_s_arr[i].store_name>>it_s_arr[i].location>>it_s_arr[i].n;
        for (int j=0; j<it_s_arr[i].n; j++){ std::cin>>it_s_arr[i].l_arr[j].manufacturer>>it_s_arr[i].l_arr[j].screen_size_in>>it_s_arr[i].l_arr[j].touch>>it_s_arr[i].l_arr[j].price; } }

    print(it_s_arr,n); best_offer(it_s_arr,n); return 0;
}
