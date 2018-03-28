#include<stdlib.h>

#include "../log.c/src/log.h"
#include "../log.c/src/log.c"

#include "CUnit/Basic.h"
#include "IO.c"

int init_suite(void) {
	return 0;
}

int clean_suite(void) {
	return 0;
}
void test_validate(void) {
	char input[] = "1 444.555 3e4";
	float expected_a = 1;
	float expected_b = 444.555;
	float expected_c = 3e4;
	inputObject *io = validate(input);
	CU_ASSERT_EQUAL(expected_a, io->a);
	CU_ASSERT_EQUAL(expected_b, io->b);
	CU_ASSERT_EQUAL(expected_c, io->c);
}

void test_validate1(void) {
	char input[] = "1 2 1";
	float expected_a = 1;
	float expected_b = 2;
	float expected_c = 1;
	inputObject *io = validate(input);
	CU_ASSERT_EQUAL(expected_a, io->a);
	CU_ASSERT_EQUAL(expected_b, io->b);
	CU_ASSERT_EQUAL(expected_c, io->c);
}
void test_validate2(void) {
	char input[] = "0.00002 22.456 12";
	float expected_a = 0.00002;
	float expected_b = 22.456;
	float expected_c = 12;
	inputObject *io = validate(input);
	CU_ASSERT_EQUAL(expected_a, io->a);
	CU_ASSERT_EQUAL(expected_b, io->b);
	CU_ASSERT_EQUAL(expected_c, io->c);
}

int main(void) {
	CU_pSuite pSuite = NULL;

	/* initialize the CUnit test registry */
	if ( CUE_SUCCESS != CU_initialize_registry() )
		return CU_get_error();

	/* add a suite to the registry */
	pSuite = CU_add_suite("validate_test_suite", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	/* add the tests to the suite */
	if ( (NULL == CU_add_test(pSuite, "test_validate", test_validate))
	|| (NULL == CU_add_test(pSuite, "test_validate1", test_validate1))
	|| (NULL == CU_add_test(pSuite, "test_validate2", test_validate2))
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

	/* Clean up registry and return */
	CU_cleanup_registry();
	return CU_get_error();
}
