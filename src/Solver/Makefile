outputInstall: solver.c
	gcc -Wall -pedantic -o solver solver.c -lm
	
unitTest: solverUnitTests.c
	gcc -Wall -pedantic -o solverUnitTests solverUnitTests.c -lm -lcunit
	
clean:
	rm -f ./solver ./solverUnitTests
