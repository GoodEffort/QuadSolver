build:
	gcc -Wall -pedantic -o ../../dist/QuadSolver Main.c -lm -lcunit

run:
	./QuadSolver

test: solverUnitTests.c
	gcc -Wall -pedantic -o solverUnitTests solverUnitTests.c -lm -lcunit
	./solverUnitTests
	
clean:
	rm ./QuadSolver
