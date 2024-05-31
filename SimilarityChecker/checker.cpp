#include <string>
using namespace std;

class SimilarityChecker {
public:
	void setTargetStrings(string& str1, string& str2) {
		if (str1.size() >= str2.size()) {
			str_1 = str1;
			str_2 = str2;
		}
		else {
			str_1 = str2;
			str_2 = str1;
		}
	}

	int checkLength() {
		int len_1 = str_1.size(); 
		int len_2 = str_2.size();

		if (len_1 == len_2) return MAX_SCORE_LENGTH;
		if (len_1 >= len_2 * 2) return 0;
		
		int gap = len_1 - len_2;
		int penaltyScore = MAX_SCORE_LENGTH * gap / len_2;
		return MAX_SCORE_LENGTH - penaltyScore;
	}
private:
	string str_1, str_2;
	const int MAX_SCORE_LENGTH = 60;
};