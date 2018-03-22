#include<stdio.h>
#include<string.h>
#include "CUnit/Basic.h"
#include "newmath.c"

int init_suite(void) {
	return 0;
}

int clean_suite(void) {
	return 0;
}

void test_add(void) {
	CU_ASSERT_EQUAL(add(1,3), 4);
	CU_ASSERT_EQUAL(add(8,13), 21);
	CU_ASSERT_EQUAL(add(9,9), 18);
}

void test_multiply(void) {
	CU_ASSERT_EQUAL(multiply(1,3), 3);
	CU_ASSERT_EQUAL(multiply(8,13), 104);
	CU_ASSERT_EQUAL(multiply(9,9), 81);
}

int main(void) {
	CU_pSuite pSuite = NULL;
	
	/* initialize the CUnit test registry */
	if ( CUE_SUCCESS != CU_initialize_registry() )
		return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("newmath_test_suite", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	/* add the tests to the suite */
	if ( (NULL == CU_add_test(pSuite, "test_add", test_add)) ||
		(NULL == CU_add_test(pSuite, "test_multiply", test_multiply))
	) {
		CU_cleanup_registry();
		return CU_get_error();
	}
	
	// Run all tests using the basic interface
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	printf("\n");
	CU_basic_show_failures(CU_get_failure_list());
	printf("\n\n");
/*
	// Run all tests using the automated interface
	CU_automated_run_tests();
	CU_list_tests_to_file();

	// Run all tests using the console interface
	CU_console_run_tests();
*/
	/* Clean up registry and return */
	CU_cleanup_registry();
	return CU_get_error();
}
