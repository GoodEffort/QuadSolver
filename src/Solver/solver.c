#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#include<stdlib.h>

#include "../headers/solver.h"

// I used the code here to verify that I did this correctly
// meaning much if it is similar to code here:
// https://stackoverflow.com/questions/49096957/citardauq-formula-not-working-precisely

solverObject *qsolve(float a, float b, float c) {
	//float root1, root2, determinant;
	//bool isreal;
	float root1 = 0;
	float root2 = 0;
	bool isreal = false;

	float determinant = (b * b) - (4 * a * c);

	if (determinant < 0) {
		root1 = 0;
		root2 = 0;
		isreal = false;
	}
	else if (b > 0) {
		root2 = (-b - sqrt(determinant)) / (2 * a);
		root1 = (c / (a * root2));
		isreal = true;
	}
	else if (b < 0) {
		root2 = (-b + sqrt(determinant)) / (2 * a);
		root1 = (c / (a * root2));
		isreal = true;
	}

	solverObject *so;
	so = malloc(sizeof(solverObject));
	so->root1 = root1;
	so->root2 = root2;
	so->isReal = isreal;
	return so;
}
/*
int main() {
	solverObject * so1 = qsolve(10, 34, 0);
	solverObject * so2 = qsolve(1, 1, 1);
	solverObject * so3 = qsolve(4, 4, 1);

	printf("%f %f %d\n", so1->root1, so1->root2, so1->isReal);
	printf("%f %f %d\n", so2->root1, so2->root2, so2->isReal);
	printf("%f %f %d\n", so3->root1, so3->root2, so3->isReal);
}*/
