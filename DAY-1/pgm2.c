#include <stdio.h>
#include <stdlib.h>

struct customer {
    char name[50];
    int id;
    float units;
};

int main()
{
    int i, n;
    float *basebill, *surcharge, *totalbill;
    struct customer *cust;

    printf("Enter total number of customers: ");
    scanf("%d", &n);
    cust = (struct customer *)malloc(n * sizeof(struct customer));
    basebill = (float *)malloc(n * sizeof(float));
    surcharge = (float *)malloc(n * sizeof(float));
    totalbill = (float *)malloc(n * sizeof(float));

    if (cust == NULL || basebill == NULL || surcharge == NULL || totalbill == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter customer name: ");
        scanf("%s", cust[i].name);

        printf("Enter %s id: ", cust[i].name);
        scanf("%d", &cust[i].id);

        printf("Enter %s units consumed: ", cust[i].name);
        scanf("%f", &cust[i].units);
    }

    for (i = 0; i < n; i++) {
        if (cust[i].units < 100) {
            basebill[i] = cust[i].units * 5;
        } else if (cust[i].units <=300) {
            basebill[i] = (100*5)+((cust[i].units-100) * 7);
        } else {
            basebill[i] = (100*5)+(200*7)+((cust[i].units-300)* 10);
        }

        totalbill[i] = basebill[i] + 100;
        surcharge[i] = 0;
        if (totalbill[i] > 1000) 
        {
            surcharge[i] = (totalbill[i] * 0.05);
           
        }

        printf("Customer name: %s\n Customer id: %d\n", cust[i].name, cust[i].id);
        printf("Units: %.2f\n Base bill: %.2f\n", cust[i].units, basebill[i]);
        printf("Total bill: %.2f\n Surcharges: %.2f\n", totalbill[i], surcharge[i]);
    }


    free(cust);
    free(basebill);
    free(surcharge);
    free(totalbill);

    return 0;
}
