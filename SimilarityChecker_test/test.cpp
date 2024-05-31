#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

class SimilarityCheckFixture : public testing::Test {
public:
	SimilarityChecker checker;

	void checkValidity(string str1, string str2) {
		try {
			checker.setStrings(str1, str2);
			checker.checkAlpha();
			FAIL();
		}
		catch (invalid_argument e) {
			// PASS
		}
	}
};

TEST_F(SimilarityCheckFixture, AlphaScore_InvalidInput_LowerCase) {
	checkValidity("abc", "edf");
	checkValidity("ABC", "EDf");
	checkValidity("ABc", "EDF");
	checkValidity("ABc", "EDF");
};

TEST_F(SimilarityCheckFixture, AlphaScore_InvalidInput_NonAlpha) {
	checkValidity("123", "EDF");
	checkValidity("ABC", "123");
	checkValidity("AB!", "DEF");
	checkValidity("ABC", "D(F");
	checkValidity("AB,", "D'F");
}

TEST_F(SimilarityCheckFixture, AlphaScore_ScoreMax) {
	checker.setStrings(string("ABC"), string("ABC"));
	EXPECT_EQ(checker.checkAlpha(), 40);

	checker.setStrings(string("ABC"), string("ABCBA"));
	EXPECT_EQ(checker.checkAlpha(), 40);

	checker.setStrings(string("ABCAB"), string("ABC"));
	EXPECT_EQ(checker.checkAlpha(), 40);

	checker.setStrings(string("A"), string("AAA"));
	EXPECT_EQ(checker.checkAlpha(), 40);
}