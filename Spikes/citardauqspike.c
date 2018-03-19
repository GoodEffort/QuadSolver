#include <stdio.h>
#include <math.h>

int main() {
	double a,b,c,determinant;
	double root1, root2;
	
	printf("Introduce coefficients a b and c:\n");
	scanf("%1lf %1lf %1lf", &a, &b, &c);
	
	determinant = (b * b) - (4 * a * c);
	
	if (0 > determinant) {
		printf("The equation has no real solution\n");
		return 0;
	}
	
	if (b > 0) {
		root1 = (-b - sqrt(determinant)) / (2 * a);
		root2 = (c / (a * root1));
		printf("The solutions are %.16f and %.16f\n", root1, root2);
	} 
	else if (b < 0) {
		root1 = (-b + sqrt(determinant)) / (2 * a);
		root2 = (c / (a * root1));
		printf("The solutions are %.16f and %.16f\n", root1, root2);
	}
}
