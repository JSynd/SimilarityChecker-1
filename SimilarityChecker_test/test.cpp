#include "pch.h"
#include "../SimilarityChecker/checker.cpp"

class SimilarityCheckFixture : public testing::Test {
public:
	SimilarityChecker checker;

	void checkValidity(string str1, string str2) {
		try {
			checker.checkAlpha(str1, str2);
			FAIL();
		}
		catch (invalid_argument e) {
			// PASS
		}
	}
};

TEST_F(SimilarityCheckFixture, AlphaScore_UpperCaseOnly) {
	checkValidity("abc", "edf");
	checkValidity("ABC", "EDf");
	checkValidity("ABc", "EDF");
	checkValidity("ABc", "EDF");
}