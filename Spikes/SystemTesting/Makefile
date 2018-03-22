raerrormake: SystemTesting.c
	gcc -Wall -pedantic -o systest SystemTesting.c -lm -lcunit
	$(MAKE) test

test:
	./systest < in > outtest
	cmp -s outtest out; \
	RETVAL=$$?; \
	if [ $$RETVAL -eq 0 ]; then \
		echo "Passed!"; \
		rm -f ./outtest; \
	else \
		echo "Failed!"; \
		$(MAKE) clean; \
	fi
	
clean:
	rm -f ./systest ./outtest
