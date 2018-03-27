#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "../headers/IO.h"

inputObject* getInputAndValidate() {
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

	inputObject *io;
	io = malloc(sizeof(inputObject));
	io->a = a;
	io->b = b;
	io->c = c;

	return io;
}

// int main() {
// 	inputObject* io = getInputAndValidate();
// 	printf("%f %f %f\n", io->a, io->b, io->c);
// }
