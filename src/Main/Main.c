#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../headers/IO.h"
#include "../IO/IO.c"
#include "../headers/solver.h"
#include "../Solver/solver.c"
#include "../headers/output.h"
#include "../Output/output.c"
#include "../log.c/src/log.h"
#include "../log.c/src/log.c"




int main(int argc, char *argv[]) {
	FILE *fp;
	log_set_quiet(1);

	fp = fopen("log", "wb");
	log_set_fp(fp);

	log_trace("Starting logging in main");

	inputObject* io = getInputAndValidate();

	printf("A: %f, B: %f, C: %f\n", io->a, io->b, io->c);

  solverObject* so = qsolve(io->a, io->b, io->c);

  printOutput(so->root1,so->root2,so->isReal);

  fclose(fp);
  return 0;
}
