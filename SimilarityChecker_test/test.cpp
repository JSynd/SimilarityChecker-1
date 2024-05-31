#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

class SimilarityCheckerFixture : public testing::Test {
public:
	SimilarityChecker checker;

	int getLengthSimilarityScore(string str1, string str2) {
		checker.setTargetStrings(str1, str2);
		return checker.checkLength();
	}
};

TEST_F(SimilarityCheckerFixture, LengthScore_60) {
	EXPECT_EQ(getLengthSimilarityScore("ABC", "DEF"), 60);
}

TEST_F(SimilarityCheckerFixture, LengthScore_0) {
	EXPECT_EQ(getLengthSimilarityScore("A", "BB"), 0);
}