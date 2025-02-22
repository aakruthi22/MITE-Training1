#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int price;
} Product;

int compare(const void *a, const void *b) {
    Product *productA = (Product *)a;
    Product *productB = (Product *)b;
    return productA->price - productB->price;
}

int binarySearch(Product products[], int size, const char *name) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(products[mid].name, name);
        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

void displayCheapestAndMostExpensive(Product products[], int size) {
    if (size > 0) {
        printf("Cheapest Product: %s (Price: %d)\n", products[0].name, products[0].price);
        printf("Most Expensive Product: %s (Price: %d)\n", products[size - 1].name, products[size - 1].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int n;

    printf("Enter number of products: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter Product Name and Price for product %d: ", i + 1);
        scanf("%s %d", products[i].name, &products[i].price);
    }

    qsort(products, n, sizeof(Product), compare);

    printf("\nSorted by Price:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (Price: %d)\n", products[i].name, products[i].price);
    }

    displayCheapestAndMostExpensive(products, n);

    char product_name[50];
    printf("\nEnter Product Name to search: ");
    scanf("%s", product_name);
    int index = binarySearch(products, n, product_name);
    if (index != -1) {
        printf("Found: %s (Price: %d)\n", products[index].name, products[index].price);
    } else {
        printf("Product '%s' not found.\n", product_name);
    }

    return 0;
}
