#include "vocabularyLink.h"
#include "readFile.h"
#include "getresult.h"

vocabularyLink::vocabularyLink(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	w = false;
	c = false;
	h = -1;
	t = -1;
	n = -1;

	ui.verticalLayout->setSpacing(0);
	IniSignalSlots();
	InitButton();
	ui.textEditOut->setFocusPolicy(Qt::NoFocus);
}

vocabularyLink::~vocabularyLink() {
	for (int i = 0; i < 27; i++) {
		delete Act_T[i];
		delete Act_H[i];
	}
	delete Act_Unlimited;
	delete Act_setNum;
	delete menu_N;
}

void vocabularyLink::IniSignalSlots(){
	connect(ui.btn_OpFile, SIGNAL(triggered()), this, SLOT(onchkActionOp()));
	connect(ui.Act_output, SIGNAL(triggered()), this, SLOT(onchkActionOut()));
	connect(ui.toolButton_W, SIGNAL(clicked()), this, SLOT(onchkButtonW()));
	connect(ui.toolButton_C, SIGNAL(clicked()), this, SLOT(onchkButtonC()));
	connect(ui.Btn_out, SIGNAL(clicked()), this, SLOT(onclkoutput()));
	
	//connect(ui.Btn_setFontIn, SIGNAL(clicked()), this, SLOT(onchkButtonSetFontIn()));
	//connect(ui.Btn_setFontOut, SIGNAL(clicked()), this, SLOT(onchkButtonSetFontOut()));

	connect(ui.actionInput, SIGNAL(triggered()), this, SLOT(onchkButtonSetFontIn()));
	connect(ui.actionOutput, SIGNAL(triggered()), this, SLOT(onchkButtonSetFontOut()));
	connect(ui.Act_help, SIGNAL(triggered()), this, SLOT(ontriggeredhelp()));
}

void vocabularyLink::InitButton(){
	ui.toolButton_W->setCheckable(true);
	ui.toolButton_C->setCheckable(true);
	ui.toolButton_T->setCheckable(true);
	ui.toolButton_H->setCheckable(true);
	ui.toolButton_N->setCheckable(true);
	InitButton_H(ui.toolButton_H);
	InitButton_T(ui.toolButton_T);
	InitButton_N(ui.toolButton_N);
}

void vocabularyLink::InitButton_H(QToolButton * btn){
	QMenu *MyMenu = new QMenu();

	Act_H[0] = new QAction(tr("无限制"));
	MyMenu->addAction(Act_H[0]);
	connect(Act_H[0], SIGNAL(triggered()), this, SLOT(onchooseUnlimited_H()));
	for (i = 1; i <= 26; i++) {
		char c[1];
		c[0] = (char)('A' + i - 1);
		Act_H[i] = new QAction(tr(c));
		//Act_H[i]->setObjectName(tr(c));
		MyMenu->addAction(Act_H[i]);
		connect(Act_H[i], SIGNAL(triggered()), this, SLOT(onchooseAct_H()));
	}
	btn->setMenu(MyMenu);
	btn->setPopupMode(QToolButton::InstantPopup);
}

void vocabularyLink::InitButton_T(QToolButton * btn) {
	QMenu *MyMenu = new QMenu();

	Act_T[0] = new QAction(tr("无限制"));
	MyMenu->addAction(Act_T[0]);
	connect(Act_T[0], SIGNAL(triggered()), this, SLOT(onchooseUnlimited_T()));
	for (i = 1; i <= 26; i++) {
		char c[1];
		c[0] = (char)('A' + i - 1);
		Act_T[i] = new QAction(tr(c));
		//Act_T[i]->setObjectName(c);
		MyMenu->addAction(Act_T[i]);
		connect(Act_T[i], SIGNAL(triggered()), this, SLOT(onchooseAct_T()));
	}
	btn->setMenu(MyMenu);
	btn->setPopupMode(QToolButton::InstantPopup);
}

void vocabularyLink::InitButton_N(QToolButton * btn){
	menu_N = new QMenu();
	Act_Unlimited = new QAction(tr("无限制"));
	Act_setNum = new QAction(tr("输入num"));
	menu_N->addAction(Act_Unlimited);
	menu_N->addAction(Act_setNum);
	btn->setMenu(menu_N);
	btn->setPopupMode(QToolButton::InstantPopup);
	connect(Act_Unlimited, SIGNAL(triggered()), this, SLOT(onchooseAct_Unlimited()));
	connect(Act_setNum, SIGNAL(triggered()), this, SLOT(onchooseAct_setNum()));
}

void vocabularyLink::onchkButtonW(){
	if (ui.toolButton_W->isChecked()) {
		if (c == true) {
			ui.toolButton_W->setChecked(true);
			w = true;
			/*QString dlgTitle = "warning";
			QString strInfo = "最长单词与最长字母限制不能同时被选中！";
			QMessageBox::warning(this, dlgTitle, strInfo);*/
			ui.toolButton_C->setChecked(false);
			c = false;
		}
		/*else if (n != -1) {
			ui.toolButton_W->setChecked(false);
			QString dlgTitle = "warning";
			QString strInfo = "不能指定单词数目来寻找最长单词链！";
			QMessageBox::warning(this, dlgTitle, strInfo);
		}*/
		else w = true;
	}
	else w = false;
}

void vocabularyLink::onchkButtonC() {
	if (ui.toolButton_C->isChecked()) {
		if (w == true) { 
			ui.toolButton_C->setChecked(true); 
			c = true;
			/*QString dlgTitle = "warning";
			QString strInfo = "最长单词与最长字母限制不能同时被选中！";
			QMessageBox::warning(this, dlgTitle, strInfo);*/
			ui.toolButton_W->setChecked(false);
			w = false;
		}
		/*else if (n != -1) {
			ui.toolButton_C->setChecked(false);
			QString dlgTitle = "warning";
			QString strInfo = "不能指定单词数目来寻找最长单词链！";
			QMessageBox::warning(this, dlgTitle, strInfo);
		}*/
		else c = true;
	}
	else c = false;
}

void vocabularyLink::onchkButtonSetFontIn(){
	QFont iniFont = ui.textEditIn->font(); //获取文本框的字体
	bool   ok = false;
	QFont font = QFontDialog::getFont(&ok, iniFont); //选择字体
	if (ok) //选择有效
		ui.textEditIn->setFont(font);
}

void vocabularyLink::onchkButtonSetFontOut(){
	QFont iniFont = ui.textEditOut->font(); //获取文本框的字体
	bool   ok = false;
	QFont font = QFontDialog::getFont(&ok, iniFont); //选择字体
	if (ok) //选择有效
		ui.textEditOut->setFont(font);
}

void vocabularyLink::ontriggeredhelp() {
	QString dlgTitle = "使用说明";
	QString strInfo = "W按钮选中为查找包含最多单词的单词链\n"
		"C按钮选中为查找包含最多字母的单词链\n"
		"H选择是否对单词链的开头字母做限制\n"
		"T选择是否对单词链的结尾字母做限制\n"
		"N选择是否对单词链的单词个数做限制\n"
				;
	QMessageBox::information(this, dlgTitle, strInfo,
		QMessageBox::Ok, QMessageBox::NoButton);
}

void vocabularyLink::onclkoutput(){
	if (!w && !c) {
		QString dlgTitle = "错误";
		QString strInfo = QString("必须在单词数最长还是字母最长中选取一个！");
		QMessageBox::critical(this, dlgTitle, strInfo);
		ui.toolButton_W->setChecked(true);
		w = true;
		ui.toolButton_W->setFocus();
		return;
	}

	QString str = ui.textEditIn->toPlainText();

	//判断输入格式是否否正确
	QByteArray ba = str.toLatin1();
	int i = 0;
	int offset = 0;
	bool setflag = false;
	QTextCursor & tmpCursor = ui.textEditIn->textCursor();
	
	for (i = 0; i < ba.size(); i++) {
		if (!((ba.at(i) <= 90 && ba.at(i) >= 65) || (ba.at(i) <= 122 && ba.at(i) >= 97) || ba.at(i) == '\n' || ba.at(i) == ';' || ba.at(i) == ',')) {
			if(!setflag){
				QString dlgTitle = "错误";
				QString strInfo = QString("输入单词格式错误，单词只能由大小写字母构成，且只能以换行符，分号及半角逗号分隔！");
				QMessageBox::critical(this, dlgTitle, strInfo);
			}
			setflag = true; offset++;
			continue;
		}
		else if (setflag) break;
	}
	if (setflag) { 
		tmpCursor.setPosition(i-offset, QTextCursor::MoveAnchor);
		tmpCursor.setPosition(i, QTextCursor::KeepAnchor);
		ui.textEditIn->setTextCursor(tmpCursor); 
		ui.textEditIn->setFocus();
		return; 
	}

	if (n == -1 && h != -1 && t != -1) {
		QString dlgTitle = "错误";
		QString strInfo = QString("若不指定单词长度n，不能同时指定单词链头和单词链尾！");
		QMessageBox::critical(this, dlgTitle, strInfo);
		return;
	}

	QList <QString> lst = str.split(QRegExp("[,;\n^]"), QString::SkipEmptyParts);
	std::vector <std::string> words;
	for (const QString i : lst) {
		words.push_back(i.toStdString());
		//qDebug() << i;
	}
	
	QString strresult = QString::fromStdString(getresult(words, w, c ,h ,t ,n));
	if (strresult == "1") {
		QString dlgTitle = "错误";
		QString strInfo = QString("Two much input file！");
		QMessageBox::critical(this, dlgTitle, strInfo);
		return;
	}else if (strresult == "2") {
		QString dlgTitle = "错误";
		QString strInfo = QString("Not a valid character！");
		QMessageBox::critical(this, dlgTitle, strInfo);
		return;
	}else if (strresult == "3") {
		QString dlgTitle = "错误";
		QString strInfo = QString("Word number should be a positive integer！");
		QMessageBox::critical(this, dlgTitle, strInfo);
		return;
	}else if (strresult == "4") {
		QString dlgTitle = "错误";
		QString strInfo = QString("No input file！");
		QMessageBox::critical(this, dlgTitle, strInfo);
		return;
	}
	qDebug() << strresult;
	ui.textEditOut->setText(strresult);
	qDebug() << "W = " << w;
	qDebug() << "C = " << c;
	qDebug() << "H = " << (int)h;
	qDebug() << "T = " << (int)t;
	qDebug() << "N = " << n;
}


void vocabularyLink::onchkActionOp() {
	QString curPath = QDir::currentPath();
	QString dlgTitle = "选择一个文件"; 
	QString filter = "文本文件(*.txt)"; 
	QString FileName = QFileDialog::getOpenFileName(this, dlgTitle, curPath, filter);
	//qDebug() << FileName << endl;
	if (FileName == "") return;
	std::vector <std::string> words;
	bool ok = false;
	readFile(words, FileName.toStdString(), ok);
	qDebug() << ok;
	if (!ok) {
		QString dlgTitle = "错误";
		QString strInfo = QString("文件 ") + FileName + " 打开失败";
		QMessageBox::critical(this, dlgTitle, strInfo);
	}
	else if(words.size() == 0) {
		QString dlgTitle = "错误";
		QString strInfo = QString("文件 ") + FileName + " 单词数量为0";
		QMessageBox::critical(this, dlgTitle, strInfo);
	}else{
		QString str = "";
		for (int i = 0; i < words.size(); i++) {
			str += QString(words[i].c_str());
			str += QString("\n");
		}
		ui.textEditIn->setText(str);
	}
}

bool vocabularyLink::saveTextByIODevice(const QString &aFileName)
{ //用IODevice方式保存文本文件
	QFile aFile(aFileName);
	//aFile.setFileName(aFileName);
	if (!aFile.open(QIODevice::WriteOnly | QIODevice::Text))
		return false;
	QString str = ui.textEditOut->toPlainText();//整个内容作为字符串
	QByteArray  strBytes = str.toUtf8();//转换为字节数组
	//QByteArray  strBytes=str.toLocal8Bit();
	aFile.write(strBytes, strBytes.length());  //写入文件
	aFile.close();
	//ui.->setCurrentIndex(0);
	return true;
}

void vocabularyLink::onchkActionOut() {
	QString curPath = QDir::currentPath();//获取系统当前目录
	QString dlgTitle = "另存为一个文件"; //对话框标题
	QString filter = "文本文件(*.txt);;所有文件(*.*)"; //文件过滤器
	QString aFileName = QFileDialog::getSaveFileName(this, dlgTitle, curPath, filter);
	if (aFileName.isEmpty())
		return;
	saveTextByIODevice(aFileName);
}

void vocabularyLink::onchooseAct_T() {
	QAction *act = qobject_cast<QAction*>(sender());
	for (int i = 0; i < 27; i++) {
		if (Act_T[i] == act) t = 'A' + i - 1;
	}
	ui.toolButton_T->setText(QString("T:") + QString(t));
	ui.toolButton_T->setChecked(true);
}

void vocabularyLink::onchooseAct_H() {
	QAction *act = qobject_cast<QAction*>(sender());
	for (int i = 0; i < 27; i++) {
		if (Act_H[i] == act) h = 'A' + i - 1;
	}
	ui.toolButton_H->setText(QString("H:") + QString(h));
	ui.toolButton_H->setChecked(true);
}

void vocabularyLink::onchooseUnlimited_T() {
	t = -1;
	ui.toolButton_T->setText(QString("T"));
	ui.toolButton_T->setChecked(false);
}

void vocabularyLink::onchooseAct_Unlimited(){
	n = -1;
	ui.toolButton_N->setText("N");
	ui.toolButton_N->setChecked(false);
}

void vocabularyLink::onchooseAct_setNum(){
	if (w == false || c == false) {
		QString dlgTitle = "输入整数";
		QString txtLabel = "设置最长单词链限制";
		int defaultValue = -1;
		int minValue = 1, maxValue = 50, stepValue = 1;
		bool ok = false;
		int inputValue = QInputDialog::getInt(this, dlgTitle, txtLabel,
			defaultValue, minValue, maxValue, stepValue, &ok);
		n = inputValue;
		if (ok) {
			QString value = QString::number(inputValue);
			ui.toolButton_N->setText(value);
			ui.toolButton_N->setChecked(true);
		}
	}
	else {
		ui.toolButton_N->setChecked(false);
		QString dlgTitle = "warning";
		QString strInfo = "最长单词与最长字母限制不能同时被选中！";
		QMessageBox::warning(this, dlgTitle, strInfo);
	}
}

void vocabularyLink::onchooseUnlimited_H() {
	h = -1;
	ui.toolButton_H->setText(QString("H"));
	ui.toolButton_H->setChecked(false);
}