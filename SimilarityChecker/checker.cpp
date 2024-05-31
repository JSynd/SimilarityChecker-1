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
		for (auto ch : str_1) {
			if (str_2.find(ch) == string::npos) return 0;
		}
		for (auto ch : str_1) {
			if (str_2.find(ch) == string::npos) return 0;
		}
		return MAX_SCORE_ALPHA;
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
};