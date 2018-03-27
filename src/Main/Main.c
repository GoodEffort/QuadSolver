#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../headers/IO.h"
#include "../IO/IO.c"
#include "../headers/solver.h"
#include "../Solver/solver.c"
#include "../headers/output.h"
#include "../Output/output.c"
//#include "../Solver/solverUnitTests.c"



int main(int argc, char const *argv[]) {

	inputObject* io = getInputAndValidate();
	printf("A: %f, B: %f, C: %f\n", io->a, io->b, io->c);

  solverObject* so = qsolve(io->a, io->b, io->c);

  if(so->root2 == -3.400000) {
    printf("%f is equal\n", so->root2);
  } else {
    double percent = fabs((so->root2 - (-3.4))/ (-3.4));
    if (percent < 0.0001) {
      printf("%f is equal\n", percent);
    } else {
      printf("%f is not equal\n", percent);
    }

  }

  printOutput(so->root1,so->root2,so->isReal);
  return 0;
}
