#include <string>
using namespace std;

class SimilarityChecker {
public:
	void setTargetStrings(string& str1, string& str2) {
		if (str1.size() >= str2.size()) {
			longer_str = str1;
			shorter_str = str2;
		}
		else {
			longer_str = str2;
			shorter_str = str1;
		}
	}

	int checkLength() {
		int len_1 = longer_str.size(); 
		int len_2 = shorter_str.size();

		if (len_1 == len_2) return MAX_SCORE_LENGTH;
		if (len_1 >= len_2 * 2) return 0;
		
		int gap = len_1 - len_2;
		int penaltyScore = MAX_SCORE_LENGTH * gap / len_2;
		return MAX_SCORE_LENGTH - penaltyScore;
	}
private:
	string longer_str, shorter_str;
	const int MAX_SCORE_LENGTH = 60;
};