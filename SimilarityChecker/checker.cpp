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
		if (str_1.size() == str_2.size()) return 60;
		if (str_1.size() >= str_2.size() * 2) return 0;
		return -1;
	}
private:
	string str_1, str_2;
};