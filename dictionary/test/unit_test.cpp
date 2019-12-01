#include "ArrayDictionary.h"
#include "gtest/gtest.h"

#define PRINT

TEST(dict, array_dict_basic) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(1, 2));
    ASSERT_EQ(hashTable.size(), 1);
    ASSERT_FALSE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(8, 4));
    ASSERT_EQ(hashTable.size(), 2);

    ASSERT_TRUE(hashTable.add(11, 4));
    ASSERT_EQ(hashTable.size(), 2);
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict, array_dict_add_overwrite) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 2));
    ASSERT_TRUE(hashTable.add(2, 4));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.size(), 1);
}

TEST(dict, array_dict_value_set_size) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.valueSetSize(5), 0);
    ASSERT_EQ(hashTable.valueSetSize(2), 2);
    ASSERT_EQ(hashTable.valueSetSize(3), 1);
}

TEST(dict, array_dict_add_get) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    int val = 0;
    ASSERT_TRUE(hashTable.get(2, val));
    ASSERT_EQ(val, 9);
    ASSERT_TRUE(hashTable.get(12, val));
    ASSERT_EQ(val, 8);
    ASSERT_TRUE(hashTable.get(3, val));
    ASSERT_EQ(val, 4);
    ASSERT_FALSE(hashTable.get(7, val));
    ASSERT_EQ(val, 4);
}

TEST(dict, contains) {
	
	// --------------- SET 1 TEST CASES ---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> setOneDict;
	
	// assertions for given test cases
	ASSERT_FALSE(setOneDict.contain(-1));
	ASSERT_FALSE(setOneDict.contain(0));
	ASSERT_FALSE(setOneDict.contain(1));
	
	// --------------- SET 2 TEST CASES ---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> setTwoDict(1);
	setTwoDict.add(0, 103);

	// assertions for given test cases
	ASSERT_FALSE(setTwoDict.contain(2));
	ASSERT_TRUE(setTwoDict.contain(0));

	// --------------- SET 3 TEST CASES ---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> setThreeDict(2);
	setThreeDict.add(0, 103);
	setThreeDict.add(1, 105);

	// assertions for given test cases
	ASSERT_TRUE(setThreeDict.contain(0));
	ASSERT_TRUE(setThreeDict.contain(1));
	ASSERT_FALSE(setThreeDict.contain(2));
	ASSERT_FALSE(setThreeDict.contain(3));

	// --------------- SET 4 TEST CASES ---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> setFourDict1(3);
	ArrayDictionary<int, int> setFourDict2(3);
	setFourDict1.add(0, 103);
	setFourDict1.add(1, 105);
	setFourDict2.add(0, 103);
	setFourDict2.add(1, 105);
	setFourDict2.add(2, 206);

	// assertions for given test cases
	ASSERT_FALSE(setFourDict1.contain(3));
	ASSERT_TRUE(setFourDict2.contain(1));

	// --------------- SET 5 TEST CASES ---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> setFiveDict(3);
	setFiveDict.add(0, 103);
	setFiveDict.add(1, 105);
	setFiveDict.add(2, 206);
	setFiveDict.add(4, 407);


	// assertions for given test cases
	ASSERT_TRUE(setFiveDict.contain(1));
	ASSERT_TRUE(setFiveDict.contain(4));
	ASSERT_FALSE(setFiveDict.contain(7));
	ASSERT_FALSE(setFiveDict.contain(8));
}

TEST(dict, remove) {
	// --------------- EMPTY DICT TEST---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> testOne;

	// assertions for given test cases
	ASSERT_FALSE(testOne.remove(-1));
	ASSERT_FALSE(testOne.remove(0));
	ASSERT_FALSE(testOne.remove(1));

	// --------------- KEY EXISTS, NO COLLISION DICT TEST---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> testTwo;
	testTwo.add(0, 103);

	// assertions for given test cases
	ASSERT_TRUE(testTwo.remove(0));
	ASSERT_TRUE(testTwo.isEmpty());

	// --------------- KEY DOES NOT EXIST, NO COLLISION DICT TEST---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> testThree;
	testThree.add(0, 103);

	// assertions for given test cases
	ASSERT_FALSE(testThree.remove(1));
	ASSERT_FALSE(testThree.isEmpty());

	// --------------- KEY EXISTS, COLLISION, KEY IN COLLISION DICT TEST---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> testFour;
	testFour.add(0, 103);
	testFour.add(0, 104);

	// assertions for given test cases
	ASSERT_TRUE(testFour.remove(0));
	ASSERT_TRUE(testFour.isEmpty());

	// --------------- KEY EXISTS, COLLISION DICT TEST---------------
	// dictionary intitializations and adds
	ArrayDictionary<int, int> testFive;
	testFive.add(0, 103);
	testFive.add(10, 104);

	// assertions for given test cases
	ASSERT_FALSE(testFive.remove(1));
	ASSERT_FALSE(testFive.isEmpty());
}
