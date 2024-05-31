#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

TEST(SimilarityChecker, LengthScore60) {
	SimilarityChecker checker;
	int score = checker.checkLength(string("ABC"), string("DEF"));
	EXPECT_EQ(score, 60);
}