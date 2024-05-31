#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

TEST(SimilarityCheck, AlphaScore_UpperCaseOnly) {
	SimilarityChecker checker;
	EXPECT_THROW(checker.checkAlpha(string("abc"), string("edf")), invalid_argument);
	EXPECT_THROW(checker.checkAlpha(string("ABC"), string("EDf")), invalid_argument);
	EXPECT_THROW(checker.checkAlpha(string("ABc"), string("EDF")), invalid_argument);
}