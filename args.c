#include<stdio.h>

int main() {
    int number_1;
	int number_2;

    printf("Enter first number: ");

    // Reads and stores input for first number
    scanf("%d", &number_1);

	printf("Enter second number: ");

    // Reads and stores input for first number
    scanf("%d", &number_2);

	// Add the two numbers
	int result = number_1 + number_2;

	printf("Result of add is: %d \n", result);
	return 0;
}
