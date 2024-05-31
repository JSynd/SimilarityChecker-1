#include <string>
#include <stdexcept>

using namespace std;

class SimilarityChecker {
public:
	void setStrings(string& str1, string& str2) {
		str_1 = str1;
		str_2 = str2;
	}

	void checkAlpha(string& str1, string& str2) {
		for (auto ch : str1) {
			if (ch >= 'a' && ch <= 'z') throw invalid_argument("found lower case!");
		}
		for (auto ch : str2) {
			if (ch >= 'a' && ch <= 'z') throw invalid_argument("found lower case!");
		}
		throw invalid_argument("error!");
		return;
	}
private:
	string str_1;
	string str_2;
};