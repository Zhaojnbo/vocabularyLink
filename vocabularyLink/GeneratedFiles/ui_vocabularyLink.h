/********************************************************************************
** Form generated from reading UI file 'vocabularyLink.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOCABULARYLINK_H
#define UI_VOCABULARYLINK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_vocabularyLinkClass
{
public:
    QAction *btn_OpFile;
    QAction *Act_output;
    QAction *actionInput;
    QAction *actionOutput;
    QAction *Act_help;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QToolButton *toolButton_W;
    QToolButton *toolButton_C;
    QToolButton *toolButton_H;
    QToolButton *toolButton_T;
    QToolButton *toolButton_N;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QTextEdit *textEditIn;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QTextEdit *textEditOut;
    QPushButton *Btn_out;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *vocabularyLinkClass)
    {
        if (vocabularyLinkClass->objectName().isEmpty())
            vocabularyLinkClass->setObjectName(QString::fromUtf8("vocabularyLinkClass"));
        vocabularyLinkClass->resize(731, 489);
        btn_OpFile = new QAction(vocabularyLinkClass);
        btn_OpFile->setObjectName(QString::fromUtf8("btn_OpFile"));
        btn_OpFile->setCheckable(false);
        btn_OpFile->setChecked(false);
        Act_output = new QAction(vocabularyLinkClass);
        Act_output->setObjectName(QString::fromUtf8("Act_output"));
        actionInput = new QAction(vocabularyLinkClass);
        actionInput->setObjectName(QString::fromUtf8("actionInput"));
        actionOutput = new QAction(vocabularyLinkClass);
        actionOutput->setObjectName(QString::fromUtf8("actionOutput"));
        Act_help = new QAction(vocabularyLinkClass);
        Act_help->setObjectName(QString::fromUtf8("Act_help"));
        centralWidget = new QWidget(vocabularyLinkClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        toolButton_W = new QToolButton(centralWidget);
        toolButton_W->setObjectName(QString::fromUtf8("toolButton_W"));
        toolButton_W->setMinimumSize(QSize(50, 80));
        QFont font;
        font.setFamily(QString::fromUtf8("Algerian"));
        font.setPointSize(18);
        toolButton_W->setFont(font);

        verticalLayout->addWidget(toolButton_W);

        toolButton_C = new QToolButton(centralWidget);
        toolButton_C->setObjectName(QString::fromUtf8("toolButton_C"));
        toolButton_C->setMinimumSize(QSize(50, 80));
        toolButton_C->setFont(font);

        verticalLayout->addWidget(toolButton_C);

        toolButton_H = new QToolButton(centralWidget);
        toolButton_H->setObjectName(QString::fromUtf8("toolButton_H"));
        toolButton_H->setMinimumSize(QSize(50, 80));
        toolButton_H->setFont(font);

        verticalLayout->addWidget(toolButton_H);

        toolButton_T = new QToolButton(centralWidget);
        toolButton_T->setObjectName(QString::fromUtf8("toolButton_T"));
        toolButton_T->setMinimumSize(QSize(50, 80));
        toolButton_T->setFont(font);

        verticalLayout->addWidget(toolButton_T);

        toolButton_N = new QToolButton(centralWidget);
        toolButton_N->setObjectName(QString::fromUtf8("toolButton_N"));
        toolButton_N->setMinimumSize(QSize(50, 80));
        toolButton_N->setFont(font);

        verticalLayout->addWidget(toolButton_N);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(6777215, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Agency FB"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);

        verticalLayout_2->addWidget(label);

        textEditIn = new QTextEdit(centralWidget);
        textEditIn->setObjectName(QString::fromUtf8("textEditIn"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(14);
        textEditIn->setFont(font2);

        verticalLayout_2->addWidget(textEditIn);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 30));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout_2);

        textEditOut = new QTextEdit(centralWidget);
        textEditOut->setObjectName(QString::fromUtf8("textEditOut"));
        textEditOut->setFont(font2);

        verticalLayout_3->addWidget(textEditOut);


        horizontalLayout->addLayout(verticalLayout_3);

        Btn_out = new QPushButton(centralWidget);
        Btn_out->setObjectName(QString::fromUtf8("Btn_out"));

        horizontalLayout->addWidget(Btn_out);

        vocabularyLinkClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(vocabularyLinkClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 731, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menu_2);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        vocabularyLinkClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(vocabularyLinkClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        vocabularyLinkClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(vocabularyLinkClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        vocabularyLinkClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(btn_OpFile);
        menu->addAction(Act_output);
        menu_2->addAction(menu_3->menuAction());
        menu_3->addAction(actionInput);
        menu_3->addAction(actionOutput);
        menu_4->addAction(Act_help);

        retranslateUi(vocabularyLinkClass);

        QMetaObject::connectSlotsByName(vocabularyLinkClass);
    } // setupUi

    void retranslateUi(QMainWindow *vocabularyLinkClass)
    {
        vocabularyLinkClass->setWindowTitle(QApplication::translate("vocabularyLinkClass", "vocabularyLink", nullptr));
        btn_OpFile->setText(QApplication::translate("vocabularyLinkClass", "\346\211\223\345\274\200", nullptr));
        Act_output->setText(QApplication::translate("vocabularyLinkClass", "\345\257\274\345\207\272", nullptr));
        actionInput->setText(QApplication::translate("vocabularyLinkClass", "Input", nullptr));
        actionOutput->setText(QApplication::translate("vocabularyLinkClass", "Output", nullptr));
        Act_help->setText(QApplication::translate("vocabularyLinkClass", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
        toolButton_W->setText(QApplication::translate("vocabularyLinkClass", "W", nullptr));
        toolButton_C->setText(QApplication::translate("vocabularyLinkClass", "C", nullptr));
        toolButton_H->setText(QApplication::translate("vocabularyLinkClass", "H", nullptr));
        toolButton_T->setText(QApplication::translate("vocabularyLinkClass", "T", nullptr));
        toolButton_N->setText(QApplication::translate("vocabularyLinkClass", "N", nullptr));
        label->setText(QApplication::translate("vocabularyLinkClass", "Input", nullptr));
        label_2->setText(QApplication::translate("vocabularyLinkClass", "Output", nullptr));
        Btn_out->setText(QApplication::translate("vocabularyLinkClass", "\342\206\222", nullptr));
        menu->setTitle(QApplication::translate("vocabularyLinkClass", "\346\226\207\344\273\266", nullptr));
        menu_2->setTitle(QApplication::translate("vocabularyLinkClass", "\350\256\276\347\275\256", nullptr));
        menu_3->setTitle(QApplication::translate("vocabularyLinkClass", "\345\255\227\344\275\223", nullptr));
        menu_4->setTitle(QApplication::translate("vocabularyLinkClass", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class vocabularyLinkClass: public Ui_vocabularyLinkClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOCABULARYLINK_H
