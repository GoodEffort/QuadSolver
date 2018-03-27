#ifndef IO_H_
#define IO_H_

typedef struct inputObject {
	float a;
	float b;
	float c;
} inputObject;

inputObject *getInputAndValidate();

#endif // IO_H_
