// Day 16 - Cafe Order Management System (formatted to match sample I/O)
#include <stdio.h>

int main() {
    int prices[5] = {50, 30, 80, 120, 60};
    char items[5][20] = {"Coffee", "Tea", "Sandwich", "Burger", "Pastry"};
    int totalQuantity[5] = {0,0,0,0,0};
    int numCustomers, i, j;
    int totalRevenue = 0;

    printf("========= Café Order Management System =========\n");
    printf("Menu:\n");
    for (i = 0; i < 5; i++) {
        printf("%d. %s - ₹%d\n", i + 1, items[i], prices[i]);
    }

    printf("\nEnter total number of customers: ");
    if (scanf("%d", &numCustomers) != 1) return 0;

    for (i = 1; i <= numCustomers; i++) {
        int numItems, itemNo, qty, customerBill = 0;
        printf("\n--- Customer %d ---\n", i);
        printf("Enter number of items: ");
        scanf("%d", &numItems);

        printf("Enter item number and quantity:\n");
        for (j = 0; j < numItems; j++) {
            scanf("%d %d", &itemNo, &qty);
            /* Echo the entered itemNo and qty so console session matches sample I/O */
            printf("%d %d\n", itemNo, qty);

            if (itemNo >= 1 && itemNo <= 5 && qty > 0) {
                customerBill += prices[itemNo - 1] * qty;
                totalQuantity[itemNo - 1] += qty;
            } else {
                /* If invalid item number or qty <= 0, ignore that entry (simple handling) */
            }
        }

        printf("Total Bill for Customer %d: ₹%d\n", i, customerBill);
        totalRevenue += customerBill;
    }

    /* compute totals and most/least ordered */
    int totalItems = 0;
    for (i = 0; i < 5; i++) totalItems += totalQuantity[i];

    int mostIndex = 0, leastIndex = 0;
    for (i = 1; i < 5; i++) {
        if (totalQuantity[i] > totalQuantity[mostIndex]) mostIndex = i;
        if (totalQuantity[i] < totalQuantity[leastIndex]) leastIndex = i;
    }

    printf("\n========= Café Summary =========\n");
    printf("Total Revenue: ₹%d\n", totalRevenue);
    printf("Total Items Sold: %d\n", totalItems);
    printf("Most Ordered Item: %s\n", items[mostIndex]);
    printf("Least Ordered Item: %s\n", items[leastIndex]);
    printf("===============================\n");

    return 0;
}