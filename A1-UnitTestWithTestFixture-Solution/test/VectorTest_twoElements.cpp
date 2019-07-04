/*
 * vector_test.cpp
 *
 *  Created on: May 31, 2012
 *      Author: unit
 */

#include <vector>
#include <gtest/gtest.h>

using namespace std;

/*
 * Solution:
 * 1. Initialize vector with two elements in SetUp()
 * 2. Write tests on the basis of this test fixture
 */

class VectorTest_twoElements : public ::testing::Test {
public:
	static int const ELEMENT1 = 3;
	static int const ELEMENT2 = 4;
protected:
	vector<int> vect;

	virtual void SetUp() {
		vect.push_back(ELEMENT1);
		vect.push_back(ELEMENT2);
	}

	virtual void TearDown() {
		vect.clear();
	}
};

const int VectorTest_twoElements::ELEMENT1;
const int VectorTest_twoElements::ELEMENT2;

TEST_F(VectorTest_twoElements, pushback_oneElement_sizeIsThree) {
	const int ELEMENT = 1234;
	vect.push_back(ELEMENT);
	ASSERT_EQ(3, vect.size());
}

TEST_F(VectorTest_twoElements, popBack_removeOneElement_sizeIsTwo) {
	vect.pop_back();
	ASSERT_EQ(1, vect.size());
}

TEST_F(VectorTest_twoElements, size_isTwo) {
	int size = vect.size();
	ASSERT_EQ(2, size);
}

TEST_F(VectorTest_twoElements, empty_isFalse) {
	ASSERT_FALSE(vect.empty());
}

TEST_F(VectorTest_twoElements, clear_sizeIsZero) {
	vect.clear();
	ASSERT_EQ(0, vect.size());
}

TEST_F(VectorTest_twoElements, clear_emptyIsFalse) {
	vect.clear();
	ASSERT_TRUE(vect.empty());
}
