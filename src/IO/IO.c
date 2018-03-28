#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "../headers/IO.h"
#include "../log.c/src/log.h"

inputObject* getInputAndValidate() {

	char buffer[512];
	char *token;
	char *err;
	int i = 0;
	float value;
	inputObject *io;
	io = malloc(sizeof(inputObject));



	printf("Input values for a b c: ");
	char *input = fgets(buffer ,512, stdin);
	if (NULL == input){
		log_error("Could not get input");
		exit(-1);
	}

	while ((token = strsep(&input, ", \"")) != NULL) {
		switch (i) {
			case 0:
			value = strtod(token, &err);
			if (err[0] != '\0') {
				log_error("Input A (%s) is not a valid number", err);
				exit(-1);
			}
			io->a = value;
			break;
			case 1:
			value = strtod(token, &err);
			if (err[0] != '\0') {
				log_error("Input B (%s) is not a valid number", err);
				exit(-1);
			}
			io->b = value;
			break;
			case 2:
			value = strtod(token, &err);
			if (err[0] != '\0' && err[0] != '\n') {
				log_error("Input C (%s) is not a valid number", err);
				exit(-1);
			}
			io->c = value;
			break;
		}
		i++;
	}
	if (i != 3) {
		printf("Three arguments were not found.\n");
		log_error("There are not 3 arguments\nNumber of arguments: %d",i);
		exit(-1);
	}


	// printf("Input value of A:\n");
	// if (scanf("%f", &a) != 1)
	// 	fprintf(stderr, "Input not a float!\n");
	// printf("Input value of B:\n");
	// if (scanf("%f", &b) != 1)
	// 	fprintf(stderr, "Input not a float!\n");
	// printf("Input value of C:\n");
	// if (scanf("%f", &c) != 1)
	// 	fprintf(stderr, "Input not a float!\n");


	return io;
}

// int main() {
// 	inputObject* io = getInputAndValidate();
// 	printf("%f %f %f\n", io->a, io->b, io->c);
// }
