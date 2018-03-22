#include<stdio.h>
#include<string.h>
#include<math.h>

int main() {
	float a, b, c;
	float quadroot1, quadroot2, citroot1, citroot2;
	
	printf("Enter a, b, and c:\n");
	scanf("%f %f %f", &a, &b, &c);
	
	float d = b * b - 4 * a * c;
	float error[4] = {0, 0, 0, 0};
	
	if (d < 0) {
		printf("No solutions");
		return -1;
	}
	
	if (d == 0) {
		quadroot1 = -b / (2 * a);
		
		return 0;
	}
	else {
		quadroot1 = (-b + sqrt(d)) / (2 * a);
		quadroot2 = (-b - sqrt(d)) / (2 * a);
	}
	
	if (b > 0) {
		citroot2 = (-b - sqrt(d)) / (2 * a);
		citroot1 = (c / (a * citroot2));
	}
	else if (b < 0) {
		citroot2 = (-b + sqrt(d)) / (2 * a);
		citroot1 = (c / (a * citroot2));
	}
	
	error[0] = quadroot1 - citroot1;
	error[1] = quadroot2 - citroot2;
	error[2] = error[0] / citroot1;
	error[3] = error[1] / citroot2;
	
	printf("absolute error on root1: %f\n", error[0]);
	printf("absolute error on root2: %f\n", error[1]);
	printf("relative error on root1: %f\n", error[2]);
	printf("relative error on root2: %f\n", error[3]);
	
	return 0;
}
