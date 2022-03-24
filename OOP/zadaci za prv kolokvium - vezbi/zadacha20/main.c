#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Patient{ char full_name[100]; bool insurance; int num; };
typedef struct Patient Patient;

struct Family_Doctor{ char name_of_doctor[100]; int patients; double price; Patient arr[200]; };
typedef struct Family_Doctor Family_Doctor;

void print_most_succesful_doctor(Family_Doctor *f_d, int n)
{
    double max=0.00; int max_other=0, pos_i=0, total=0;

    for(int i=0; i<n; i++){ double sum=0; int insured=0, other=0;
        for(int j=0; j<f_d[i].patients; j++){
            !f_d[i].arr[j].insurance?(insured+=f_d[i].arr[j].num):(other+=f_d[i].arr[j].num); sum = f_d[i].price*insured; }
    sum==max?(insured+other>max_other?max_other=insured+other,total=insured+other,max=sum,pos_i=i:0):sum>max?total=insured+other,max=sum,pos_i=i:0; }

    printf("%s %.2lf %d\n", f_d[pos_i].name_of_doctor, max, total);
}

int main()
{
	int n; scanf("%d", &n); Family_Doctor m_d[n];

	for (int i=0; i<n; i++){ scanf("%s%d%lf", m_d[i].name_of_doctor, &m_d[i].patients, &m_d[i].price);
		for(int j=0; j<m_d[i].patients; j++){ scanf("%s%d%d",m_d[i].arr[j].full_name,&m_d[i].arr[j].insurance,&m_d[i].arr[j].num); } }

    print_most_succesful_doctor(m_d,n); return 0;
}
