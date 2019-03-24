#include "readFile.h"
#include <iostream>
void readFile(std::vector <std::string> &words, const std::string &path, bool & ok) {
	bool rst = false;
	QFile file(path.c_str());
	file.open(QIODevice::ReadOnly | QIODevice::ReadOnly);
	if (!file.isOpen()) {
		//qDebug() << "1";
		return;
	}
	QByteArray t = file.readAll();
	file.close();
	int i = 0;
	int c;
	bool flag = true;
	QString buffer = "";
	while (i < t.size() && (c = t.at(i++))) {
		if (c <= 90 && c >= 65) {
			c += 32;
			buffer += (char)c;
			rst = true;
			flag = true;
		}else if (c <= 122 && c >= 97) {
			buffer += (char)c;
			rst = true;
			flag = true;
		}else if (flag) {
			if (!rst) continue;
			words.push_back(buffer.toStdString());
			buffer = "";
			flag = false;
		}
	}
	//ШЅжи
	std::vector <std::string>::iterator iter = unique(words.begin(), words.end());
	words.erase(iter, words.end());
	ok = true;
}
