#include <stdio.h>
void convertMetersToKilometers() {
    float meters, kilometers;
    printf("Enter the distance in meters: ");
    scanf("%f", &meters);
    kilometers = meters / 1000;
    printf("%.2f meters is equal to %.2f kilometers.\n", meters, kilometers);
}
void convertGramsToKilograms() {
    float grams, kilograms;
    printf("Enter the weight in grams: ");
    scanf("%f", &grams);
    kilograms = grams / 1000;
    printf("%.2f grams is equal to %.2f kilograms.\n", grams, kilograms);
}
int main() {
    int choice;
    printf("Unit Conversion Program\n");
    printf("1. Convert Meters to Kilometers\n");
    printf("2. Convert Grams to Kilograms\n");
    printf("3. Exit\n");
    do {
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:              convertMetersToKilometers();
                break;
            case 2:
                convertGramsToKilograms();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 3);
    return 0;
}
