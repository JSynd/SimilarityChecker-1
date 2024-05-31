#include "pch.h"
#include "../SimilarityChecker/length_checker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
	LengthChecker checker;

	void checkScore(string str1, string str2, int expectScore) {
		checker.setTargetStrings(str1, str2);
		EXPECT_EQ(checker.checkLength(), expectScore);
	}
};

TEST_F(SimilarityCheckerFixture, LengthScore_60) {
	checkScore("ABC", "DEF", 60);
}

TEST_F(SimilarityCheckerFixture, LengthScore_0) {
	checkScore("A", "BB", 0);
	checkScore("BB", "A", 0);
}

TEST_F(SimilarityCheckerFixture, LengthScore_Partial) {
	checkScore("AAABB", "BBB", 20);
	checkScore("AAB", "AABBB", 20);
	checkScore("AA", "ABB", 30);
	checkScore("ABA", "AB", 30);
}

TEST_F(SimilarityCheckerFixture, LengthScore_Exception) {
	checkScore("AAABB", "", 0);
}