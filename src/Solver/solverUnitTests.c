#include<stdlib.h>

#include "../log.c/src/log.h"
#include "../log.c/src/log.c"

#include "CUnit/Basic.h"
#include "solver.c"

int init_suite(void) {
	return 0;
}

int clean_suite(void) {
	return 0;
}
void test_qsolve1(void) {
	solverObject * so1 = qsolve(10, 34, 0);

	if (so1->root1 == 0) {
		CU_ASSERT_EQUAL(so1->root1, 0);
	} else {
		CU_ASSERT_TRUE(fabs((so1->root1 - (0))/ (0)) < 0.0001);
	}
	if (so1->root2 == 0) {
		CU_ASSERT_EQUAL(so1->root2, -3.4);
	} else {
		CU_ASSERT_TRUE(fabs((so1->root2 - (-3.4))/ (-3.4)) < 0.0001);
	}
	CU_ASSERT_TRUE(so1->isReal);
}

void test_qsolve2(void) {
	solverObject * so2 = qsolve(1, 1, 1);

	if (so2->root1 == 0) {
		CU_ASSERT_EQUAL(so2->root1, 0);
	} else {
		CU_ASSERT_TRUE(fabs((so2->root1 - (0))/ (0)) < 0.0001);
	}
	if (so2->root2 == 0) {
		CU_ASSERT_EQUAL(so2->root2, 0);
	} else {
		CU_ASSERT_TRUE(fabs((so2->root2 - (0))/ (0)) < 0.0001);
	}
	CU_ASSERT_FALSE(so2->isReal);
}

void test_qsolve3(void) {
	solverObject * so3 = qsolve(4, 4, 1);
	if (so3->root1 == 0) {
		CU_ASSERT_EQUAL(so3->root1, 0);
	} else {
		CU_ASSERT_TRUE(fabs((so3->root1 - (-0.5))/ (-0.5)) < 0.0001);
	}
	if (so3->root2 == 0) {
		CU_ASSERT_EQUAL(so3->root2, -3.4);
	} else {
		CU_ASSERT_TRUE(fabs((so3->root2 - (-0.5))/ (-0.5)) < 0.0001);
	}
	CU_ASSERT_TRUE(so3->isReal);
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
	if ( (NULL == CU_add_test(pSuite, "test_qsolve1", test_qsolve1))
		|| (NULL == CU_add_test(pSuite, "test_qsolve2", test_qsolve2))
		|| (NULL == CU_add_test(pSuite, "test_qsolve3", test_qsolve3))
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
