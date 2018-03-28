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
//#include "../Solver/solverUnitTests.c"



int main(int argc, char const *argv[]) {
	FILE *fp;
	log_set_quiet(1);
	if (argc > 0) {
		if (strcmp(argv[0], "-v")) {
			log_set_quiet(0);
		}
	}
	
	fp = fopen("log", "ab");
	log_set_fp(fp);
	
	log_trace("Starting logging in main");

	inputObject* io = getInputAndValidate();
	
	printf("A: %f, B: %f, C: %f\n", io->a, io->b, io->c);

  	solverObject* so = qsolve(io->a, io->b, io->c);

  	printOutput(so->root1,so->root2,so->isReal);
  	
  	fclose(fp);
  	return 0;
}
