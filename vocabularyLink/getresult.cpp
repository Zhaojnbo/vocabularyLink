#define RETSIZE (1 << 26)

#include "getresult.h"
#include <iostream>

int doCalc(char *ret, std::vector <std::string> &words, const char *argv[]);

using namespace std;

std::string getresult(std::vector <std::string> &words, bool w, bool c, char h, char t, int n) {
	const char *argv[20] = { "1" };
	char buf[15], buf2[8], buf3[8];
	int i = 1;
	if (w) {
		argv[i++] = "-w";
		argv[i++] = "aa";
	}
	if (c) {
		argv[i++] = "-c";
		argv[i++] = "aa";
	}
	if (h != -1) {
		argv[i++] = "-h";
		sprintf(buf2, "%c", h);
		argv[i++] = buf2;
	}
	if (t != -1) {
		argv[i++] = "-t";
		sprintf(buf3, "%c", t);
		argv[i++] = buf3;
	}
	if (n != -1) {
		argv[i++] = "-n";
		sprintf(buf, "%d", n);
		argv[i++] = buf;
	}

	char *ret = static_cast<char *>(malloc(sizeof(char) * RETSIZE));

	try {
		doCalc(ret, words, argv);
	} catch (runtime_error err) {
		return err.what();
	}

	string str = ret;
	free(ret);
	return str;
}
//
//int main() {
//	vector<string> v;
//	cout << getresult(v, false, true, -1, -1, 21) << endl;
//}