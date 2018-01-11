#include <iostream>

using namespace std;

int main()
{
	char *str = "https://github.com/junyux";
	char *subStr = "github";

	int strLen = strlen(str);
	int subStrLen = strlen(subStr);

	for (int i = 0; i <= strLen - subStrLen; i++) {
		int j = 0;

		for (int k = i; j < strlen(subStr); j++, k++) {
			if (str[k] != subStr[j]) {
				break;
			}
		}

		if (j == strlen(subStr)) {
			cout << "equal" << endl;
			break;
		}
	}
}
