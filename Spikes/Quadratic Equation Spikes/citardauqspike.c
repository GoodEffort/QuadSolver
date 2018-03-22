#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, determinant;
	float root1, root2;
	
	printf("Enter a, b, and c:\n");
	scanf("%f %f %f", &a, &b, &c);
	
	determinant = (b * b) - (4 * a * c);
	
	if (0 > determinant) {
		printf("The equation has no real solution\n");
		return 0;
	}
	
	if (b > 0) {
		root2 = (-b - sqrt(determinant)) / (2 * a);
		root1 = (c / (a * root2));
		printf("The solutions are %.16f and %.16f\n", root1, root2);
	} 
	else if (b < 0) {
		root2 = (-b + sqrt(determinant)) / (2 * a);
		root1 = (c / (a * root2));
		printf("The solutions are %.16f and %.16f\n", root1, root2);
	}
}
