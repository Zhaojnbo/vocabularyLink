#ifndef READFILE_H
#define READFILE_H

#include <cctype>
#include <fstream>
#include <string>
#include <vector>
#include <exception>
#include <QFile>
#include <QMessageBox>
#include <qdebug.h>

extern void readFile(std::vector <std::string> &words, const std::string &path, bool & ok);

#endif // READFILE_H
