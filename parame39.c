#include <stdio.h>

int main() {
    char *products[] = {"Rice", "Sugar", "Coffee"};
    float prices[] = {60.00, 75.00, 120.00};
    char *units[] = {"kg", "kg", "pack"};

    int choice, quantity;
    float subtotal, discount, finalAmount;
    float payment, change, shortage;

    printf("===== CONVENIENCE STORE =====\n");
    printf("1. Rice  - P60/kg\n");
    printf("2. Sugar - P75/kg\n");
    printf("3. Coffee - P120/pack\n");

    printf("Select a product (1-3): ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid product selection!\n");
        return 0;
    }

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    if (quantity <= 0) {
        printf("Invalid quantity!\n");
        return 0;
    }

    subtotal = prices[choice - 1] * quantity;

    if (subtotal >= 1000) {
        discount = subtotal * 0.10;
    } else {
        discount = 0;
    }

    finalAmount = subtotal - discount;

    printf("\n===== ORDER SUMMARY =====\n");
    printf("Product: %s\n", products[choice - 1]);
    printf("Quantity: %d %s\n", quantity, units[choice - 1]);
    printf("Subtotal: ₱%.2f\n", subtotal);
    printf("Discount: ₱%.2f\n", discount);
    printf("Final Amount: P%.2f\n", finalAmount);

    printf("Enter payment: ₱ ");
    scanf("%f", &payment);

    if (payment >= finalAmount) {
        change = payment - finalAmount;
        printf("Change: P%.2f\n", change);
    } else {
        shortage = finalAmount - payment;
        printf("Insufficient payment!\n");
        printf("Shortage: ₱%.2f\n", shortage);
    }

    printf("Thank you for shopping!\n");

    return 0;
}