#pragma once

#include <QtWidgets/QMainWindow>
#include <QAction>
#include <QPushButton>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <iostream>

#include <qdebug.h>
#include <QMessageBox>
#include <vector>
#include <string>

#include "ui_vocabularyLink.h"

#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8") 
#endif

class vocabularyLink : public QMainWindow
{
	Q_OBJECT

public:
	vocabularyLink(QWidget *parent = Q_NULLPTR);
	~vocabularyLink();

private:
	Ui::vocabularyLinkClass ui;

	int i;
	bool w;
	bool c;
	char h;
	char t;
	int n;

	QAction * Act_T[27];
	QAction * Act_H[27];
	QAction * Act_Unlimited;
	QAction * Act_setNum;

	QMenu * menu_N;

	void IniSignalSlots();
	void InitButton();
	void InitButton_H(QToolButton * btn);
	void InitButton_T(QToolButton * btn);
	void InitButton_N(QToolButton * btn);

private slots:
	void onchkActionOp();
	bool saveTextByIODevice(const QString & aFileName);
	void onchkActionOut();
	void onchkButtonW();
	void onchkButtonC();
	void onchkButtonSetFontIn();
	void onchkButtonSetFontOut();
	void ontriggeredhelp();
	void onclkoutput();

	void onchooseAct_H();
	void onchooseAct_T();
	void onchooseUnlimited_H();
	void onchooseUnlimited_T();
	void onchooseAct_Unlimited();
	void onchooseAct_setNum();
	
};
