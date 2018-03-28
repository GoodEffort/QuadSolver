#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "../headers/IO.h"
#include "../log.c/src/log.h"

int getInputCalledCount = 0;
int validateCalledCount = 0;

char *getInput() {
	log_trace("getInput method called %d times", ++getInputCalledCount);
	
	char buffer[512];
	
	printf("Input values for a b c: ");
	char *input = fgets(buffer ,512, stdin);
	if (NULL == input){
		log_error("Could not get input");
		exit(-1);
	}
	return input;
}

inputObject *validate(char *input) {
	log_trace("validate method called %d times", ++validateCalledCount);
	
	char *token;
	char *err;
	int i = 0;
	float value;
	inputObject *io;
	io = malloc(sizeof(inputObject));
	
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

	return io;
}

inputObject* getInputAndValidate() {
	char *input = getInput();
	return validate(input);
}
