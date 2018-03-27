#ifndef OUTPUT_H_
#define OUTPUT_H_

typedef struct solverObject {
	float root1;
	float root2;
	bool isReal;
} solverObject;

solverObject *qsolve(float a, float b, float c);
#endif // OUTPUT_H_
