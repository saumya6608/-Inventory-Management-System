#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

struct product {
    char name[MAX_NAME_LENGTH];
    int stock;
    double price;
    int sales;
};

int num_products = 0;
struct product products[MAX_PRODUCTS];

void add_product() {
    if (num_products == MAX_PRODUCTS) {
        printf("Maximum number of products reached\n");
        return;
    }

    printf("Enter product name: ");
    scanf("%s", products[num_products].name);

    printf("Enter product stock: ");
    scanf("%d", &products[num_products].stock);

    printf("Enter product price: ");
    scanf("%lf", &products[num_products].price);

    products[num_products].sales = 0;

    num_products++;
}

void display_products() {
    printf("Products:\n");
    for (int i = 0; i < num_products; i++) {
        printf("%d. %s (Stock: %d, Price: $%.2lf, Sales: %d)\n", i+1, products[i].name, products[i].stock, products[i].price, products[i].sales);
    }
}

void sell_product() {
    int choice;
    printf("Which product would you like to sell? (Enter number): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > num_products) {
        printf("Invalid choice\n");
        return;
    }

    int quantity;
    printf("How many would you like to sell?: ");
    scanf("%d", &quantity);

    if (quantity > products[choice-1].stock) {
        printf("Not enough stock\n");
        return;
    }

    products[choice-1].stock -= quantity;
    products[choice-1].sales += quantity;

    printf("Sold %d %s\n", quantity, products[choice-1].name);
}

void generate_report() {
    double total_sales = 0;
    printf("Product Report:\n");
    for (int i = 0; i < num_products; i++) {
        double product_sales = products[i].sales * products[i].price;
        total_sales += product_sales;
        printf("%s (Stock: %d, Price: $%.2lf, Sales: %d, Revenue: $%.2lf)\n", products[i].name, products[i].stock, products[i].price, products[i].sales, product_sales);
    }
    printf("Total Revenue: $%.2lf\n", total_sales);
}

int main() {
    int choice;

    do {
        printf("\nInventory Management System\n");
        printf("1. Add product\n");
        printf("2. Display products\n");
        printf("3. Sell product\n");
        printf("4. Generate report\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_product();
                break;
            case 2:
                display_products();
                break;
            case 3:
                sell_product();
                break;
            case 4:
                generate_report();
                break;
            case 0:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
