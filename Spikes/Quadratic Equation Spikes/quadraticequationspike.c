#include<stdio.h>
#include<math.h>

int main() {
	double a, b, c;
	double d, root1, root2;
	
	printf("Enter a, b, and c: \n");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	d = b * b - 4 * a * c;
	
	if (d < 0) {
		printf("No real solution");
		
		return 0;
	}
	else if (d == 0) {
		printf("Roots are equal.\n");
		
		root1 = -b / (2 * a);
		
		printf("Root is %.16lf\n", root1);
		
		return 0;
	}
	else {
		printf("Roots are real numbers.\n");
		
		root1 = (-b + sqrt(d)) / (2 * a);
		root2 = (-b - sqrt(d)) / (2 * a);
		printf("Roots of quad eq are %.16lf and %.16lf\n", root1, root2);
	}
	
	return 0;
}
