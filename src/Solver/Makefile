outputInstall: solver.c
	gcc -Wall -pedantic -o solver solver.c -lm
	
unitTest: solverUnitTests.c
	gcc -Wall -pedantic -o ../../dist/solverUnitTests solverUnitTests.c -lm -lcunit
	../../dist/solverUnitTests
	
clean:
	rm -f ./solver ./solverUnitTests
