#include <stdio.h>

int main () {
	float a, b, c;
	printf("Input value of A:\n");
	if (scanf("%f", &a) != 1)
		fprintf(stderr, "Input not a float!\n");
	printf("Input value of B:\n");
	if (scanf("%f", &b) != 1)
		fprintf(stderr, "Input not a float!\n");
	printf("Input value of C:\n");
	if (scanf("%f", &c) != 1)
		fprintf(stderr, "Input not a float!\n");
	
	printf("%f %f %f\n", a, b, c);
}
