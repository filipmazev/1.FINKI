#include <stdio.h>
#include <stdlib.h>

struct Product
{
    char name[100];
    double price, quantity;
};

int main()
{
    int n; scanf("%d", &n);
    double total=0; struct Product Product_List_Item[n];

    for(int i=0; i<n; i++)
    {
        scanf("%s", Product_List_Item[i].name);
        scanf("%lf", &Product_List_Item[i].price);
        scanf("%lf", &Product_List_Item[i].quantity);
        total += Product_List_Item[i].quantity * Product_List_Item[i].price;
    }

    for(int i=0; i<n; i++)
    {
        printf("%d. %s\t", i+1, Product_List_Item[i].name);
        printf("%.2lf x ", Product_List_Item[i].price);
        printf("%.1lf = %.2lf\n", Product_List_Item[i].quantity, (Product_List_Item[i].price* Product_List_Item[i].quantity ));
    }

    printf("Total: %.2lf", total); return 0;

}
