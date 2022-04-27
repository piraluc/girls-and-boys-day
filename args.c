#include<stdio.h>

int main(int argc, char *argv[]) {
	int x = argv[1];
	int y = argv[2];

	int z = x + y;

	printf("Hello %i\n", z);
	return 0;
}
