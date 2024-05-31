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

TEST_F(SimilarityCheckerFixture, LengthScore60) {
	int score = getLengthSimilarityScore("ABC", "DEF");
	EXPECT_EQ(score, 60);
}