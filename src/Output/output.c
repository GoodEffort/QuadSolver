#include<stdio.h>
#include<string.h>
#include <stdbool.h>

#include "../headers/output.h"

void printOutput(float root1, float root2, bool realAnswer) {
	if (realAnswer) {
		if (root1 != root2) {
			printf("The value of the first root is %f\n", root1);
			printf("The value of the second root is %f\n", root2);
		}
		else {
			printf("Both roots are the same and their value is %f\n", root1);
		}
	}
	else {
		printf("There is not a real solution to the problem\n");
	}
}

// int main() {
// 	printOutput(10, 2e3, true);
// 	printOutput(10, 10, true);
// 	printOutput(0, 0, false);
// }
