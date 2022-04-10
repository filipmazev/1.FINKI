#include <stdio.h>
#include <stdlib.h>

struct Product{ char code[20]; int price, availability; };
typedef struct Product Product;

struct Order{ char buyer_name[15]; Product arr[10]; int quantity[10], total_ordered; };
typedef struct Order Order;

void print_invoice(Order o)
{
    int sum=0; printf("Faktura za %s\n",o.buyer_name);

    for(int i=0; i<o.total_ordered; i++){
        for(int j=0; j<o.total_ordered-i-1; j++){
            if(strcmp(o.arr[j].code, o.arr[j+1].code) > 0){
                Product tmp = o.arr[j]; o.arr[j] = o.arr[j+1]; o.arr[j+1] = tmp; } } }

    for(int i=0; i<o.total_ordered; i++){
    if(o.quantity[i] > o.arr[i].availability) { printf("Fakturata ne moze da se izgotvi"); return 0; }
    else{ printf("%s %d %d %d\n", o.arr[i].code,o.arr[i].price, o.quantity[i], o.arr[i].price*o.quantity[i]); sum+=o.arr[i].price * o.quantity[i]; } }

    printf("Vkupnata suma na fakturata e %d", sum);
}

int main()
{
    Order o; scanf("%s%d", o.buyer_name, &o.total_ordered);

    for (int i=0; i<o.total_ordered; ++i){ scanf("%s%d%d",o.arr[i].code, &o.arr[i].price, &o.arr[i].availability); }
    for (int j=0; j<o.total_ordered; ++j){ scanf("%d", &o.quantity[j]); }

    print_invoice(o); return 0;
}
