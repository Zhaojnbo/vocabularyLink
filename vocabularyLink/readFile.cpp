#include "readFile.h"
#include <iostream>
void readFile(std::vector <std::string> &words, const std::string &path, bool & ok) {
	QFile file(path.c_str());
	file.open(QIODevice::ReadOnly | QIODevice::ReadOnly);
	if (!file.isOpen()) {
		qDebug() << "1";
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
			flag = true;
		}else if (c <= 122 && c >= 97) {
			buffer += (char)c;
			flag = true;
		}else if (flag) {
			words.push_back(buffer.toStdString());
			buffer = "";
			flag = false;
		}
	}
	qDebug() << "2";
	ok = true;
}
