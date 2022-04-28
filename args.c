#include<stdio.h>

int main(int argc, char *argv[]) {
	// Convert the two arguments from characters to numbers
	int x = (long)argv[1];
	int y = (long)argv[2];

	// Add the two numbers
	int z = x + y;

	printf("Hello %i\n", z);
	return 0;
}
