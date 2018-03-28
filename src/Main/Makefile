build:
	gcc -Wall -pedantic -o ../../dist/QuadSolver Main.c -lm -lcunit

run:
	cd ../../dist ; ./QuadSolver

test:
	cd ../Solver ; make unitTest
	cd ../IO ; make unitTest

clean:
	rm ./QuadSolver
