#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	void setStrings(string& str1, string& str2) {
		str_1 = str1;
		str_2 = str2;
		checkValidity();
	}

	int checkAlpha() {
		int same_cnt = getSameCnt(str_1, str_2);
		int diff_cnt_1 = getDiffCnt(str_1, str_2);
		if (same_cnt == 0) return 0;
		if (diff_cnt_1 == 0) return MAX_SCORE_ALPHA;
		return same_cnt * MAX_SCORE_ALPHA / 4;
	}

private:
	string str_1;
	string str_2;

	const int MAX_SCORE_ALPHA = 40;

	void checkValidity() {
		for (auto ch : str_1 + str_2) {
			if (ch >= 'A' && ch <= 'Z') continue;
			throw invalid_argument("Should be Alpha with Upper case!");
		}
	}

	int getSameCnt(string targetStr, string refStr) {
		int sameCnt = 0;
		for (auto ch : targetStr) {
			if (refStr.find(ch) != string::npos) sameCnt++;
		}
		return sameCnt;
	}

	int getDiffCnt(string targetStr, string refStr) {
		int diffCnt = 0;
		for (auto ch : targetStr) {
			if (refStr.find(ch) == string::npos) diffCnt++;
		}
		return diffCnt;
	}
};