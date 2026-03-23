/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QGridLayout *gridLayout;
    QPushButton *btn8;
    QPushButton *btnCos;
    QPushButton *btn6;
    QPushButton *btn3;
    QPushButton *btnPI;
    QPushButton *btnLn;
    QPushButton *btnNot;
    QPushButton *btnPercent;
    QPushButton *btnSin;
    QPushButton *btn7;
    QPushButton *btnMemR;
    QPushButton *btnAsin;
    QPushButton *btnDegToRad;
    QPushButton *btn5;
    QPushButton *btnMemC;
    QPushButton *btnDecToDms;
    QPushButton *btnSqrt;
    QPushButton *btnNand;
    QPushButton *btnF_hex;
    QPushButton *btn2;
    QPushButton *btnAdd;
    QPushButton *btnHex;
    QPushButton *btnPow;
    QPushButton *btnMod;
    QPushButton *btnLog2_10;
    QPushButton *btnDel;
    QPushButton *btnLogAB;
    QPushButton *btn_x2_x10;
    QPushButton *btnRadToDeg;
    QPushButton *btnA_hex;
    QPushButton *btnDegRad;
    QPushButton *btnDot;
    QPushButton *btnOr;
    QPushButton *btnE_hex;
    QPushButton *btnC;
    QPushButton *btnD_hex;
    QPushButton *btnTan;
    QPushButton *btnP;
    QPushButton *btnSign;
    QPushButton *btnColon;
    QPushButton *btnAcos;
    QPushButton *btnInv;
    QPushButton *btnNor;
    QPushButton *btnOct;
    QPushButton *btnE;
    QPushButton *btnExp;
    QPushButton *btnB_hex;
    QPushButton *btnXor;
    QPushButton *btnNroot;
    QPushButton *btnAbs;
    QPushButton *btnFact;
    QPushButton *btnBin;
    QPushButton *btnEq;
    QPushButton *btnCbrt;
    QPushButton *btn9;
    QPushButton *btnXnor;
    QPushButton *btnC_hex;
    QPushButton *btnAnd;
    QPushButton *btn0;
    QPushButton *btn1;
    QPushButton *btnAtan;
    QPushButton *btnSub;
    QPushButton *btnDec;
    QPushButton *btnMul;
    QPushButton *btn4;
    QPushButton *btnDiv;
    QPushButton *btnClear;
    QPushButton *btnMem;
    QPushButton *btnDmsToDec;
    QLineEdit *display;
    QPushButton *btnLink;
    QPushButton *btnPowMode;
    QMenuBar *menubar;
    QMenu *menuScientific_Calculator;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(738, 572);
        MainWindow->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        MainWindow->setMouseTracking(true);
        MainWindow->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(26, 34, 41);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        btn8 = new QPushButton(centralwidget);
        btn8->setObjectName("btn8");
        QFont font;
        font.setPointSize(12);
        btn8->setFont(font);
        btn8->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn8->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn8, 5, 1, 1, 1);

        btnCos = new QPushButton(centralwidget);
        btnCos->setObjectName("btnCos");
        btnCos->setFont(font);
        btnCos->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnCos->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 54, 87);"));

        gridLayout->addWidget(btnCos, 2, 1, 1, 1);

        btn6 = new QPushButton(centralwidget);
        btn6->setObjectName("btn6");
        btn6->setFont(font);
        btn6->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn6->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn6, 6, 2, 1, 1);

        btn3 = new QPushButton(centralwidget);
        btn3->setObjectName("btn3");
        btn3->setFont(font);
        btn3->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn3->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn3, 7, 2, 1, 1);

        btnPI = new QPushButton(centralwidget);
        btnPI->setObjectName("btnPI");
        btnPI->setFont(font);
        btnPI->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnPI->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 88, 111);"));

        gridLayout->addWidget(btnPI, 2, 7, 1, 1);

        btnLn = new QPushButton(centralwidget);
        btnLn->setObjectName("btnLn");
        btnLn->setFont(font);
        btnLn->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnLn->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 80);"));

        gridLayout->addWidget(btnLn, 4, 2, 1, 1);

        btnNot = new QPushButton(centralwidget);
        btnNot->setObjectName("btnNot");
        btnNot->setFont(font);
        btnNot->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnNot->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 121, 140);"));

        gridLayout->addWidget(btnNot, 10, 0, 1, 1);

        btnPercent = new QPushButton(centralwidget);
        btnPercent->setObjectName("btnPercent");
        btnPercent->setFont(font);
        btnPercent->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnPercent->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 127);"));

        gridLayout->addWidget(btnPercent, 6, 5, 1, 2);

        btnSin = new QPushButton(centralwidget);
        btnSin->setObjectName("btnSin");
        btnSin->setFont(font);
        btnSin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSin->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 54, 87);"));
        btnSin->setCheckable(false);

        gridLayout->addWidget(btnSin, 2, 0, 1, 1);

        btn7 = new QPushButton(centralwidget);
        btn7->setObjectName("btn7");
        btn7->setFont(font);
        btn7->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn7->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn7, 5, 0, 1, 1);

        btnMemR = new QPushButton(centralwidget);
        btnMemR->setObjectName("btnMemR");
        btnMemR->setFont(font);
        btnMemR->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnMemR->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 140, 140);"));

        gridLayout->addWidget(btnMemR, 5, 5, 1, 2);

        btnAsin = new QPushButton(centralwidget);
        btnAsin->setObjectName("btnAsin");
        btnAsin->setFont(font);
        btnAsin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAsin->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 54, 87);"));

        gridLayout->addWidget(btnAsin, 2, 3, 1, 1);

        btnDegToRad = new QPushButton(centralwidget);
        btnDegToRad->setObjectName("btnDegToRad");
        btnDegToRad->setFont(font);
        btnDegToRad->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDegToRad->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 54, 87);"));

        gridLayout->addWidget(btnDegToRad, 3, 1, 1, 1);

        btn5 = new QPushButton(centralwidget);
        btn5->setObjectName("btn5");
        btn5->setFont(font);
        btn5->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn5->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn5, 6, 1, 1, 1);

        btnMemC = new QPushButton(centralwidget);
        btnMemC->setObjectName("btnMemC");
        btnMemC->setFont(font);
        btnMemC->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnMemC->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 140, 140);"));

        gridLayout->addWidget(btnMemC, 5, 7, 1, 1);

        btnDecToDms = new QPushButton(centralwidget);
        btnDecToDms->setObjectName("btnDecToDms");
        btnDecToDms->setFont(font);
        btnDecToDms->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDecToDms->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 47, 83);"));

        gridLayout->addWidget(btnDecToDms, 9, 4, 1, 2);

        btnSqrt = new QPushButton(centralwidget);
        btnSqrt->setObjectName("btnSqrt");
        btnSqrt->setFont(font);
        btnSqrt->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSqrt->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 80);"));

        gridLayout->addWidget(btnSqrt, 4, 0, 1, 1);

        btnNand = new QPushButton(centralwidget);
        btnNand->setObjectName("btnNand");
        btnNand->setFont(font);
        btnNand->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnNand->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 121, 140);"));

        gridLayout->addWidget(btnNand, 10, 2, 1, 1);

        btnF_hex = new QPushButton(centralwidget);
        btnF_hex->setObjectName("btnF_hex");
        btnF_hex->setFont(font);
        btnF_hex->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnF_hex->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);\n"
"color: rgb(125,16,16);"));

        gridLayout->addWidget(btnF_hex, 11, 5, 1, 2);

        btn2 = new QPushButton(centralwidget);
        btn2->setObjectName("btn2");
        btn2->setFont(font);
        btn2->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn2->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn2, 7, 1, 1, 1);

        btnAdd = new QPushButton(centralwidget);
        btnAdd->setObjectName("btnAdd");
        btnAdd->setFont(font);
        btnAdd->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 37, 77);"));

        gridLayout->addWidget(btnAdd, 8, 3, 1, 1);

        btnHex = new QPushButton(centralwidget);
        btnHex->setObjectName("btnHex");
        btnHex->setFont(font);
        btnHex->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnHex->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);\n"
"color: rgb(125,16,16);"));

        gridLayout->addWidget(btnHex, 9, 3, 1, 1);

        btnPow = new QPushButton(centralwidget);
        btnPow->setObjectName("btnPow");
        btnPow->setFont(font);
        btnPow->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnPow->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 80);"));

        gridLayout->addWidget(btnPow, 3, 3, 1, 1);

        btnMod = new QPushButton(centralwidget);
        btnMod->setObjectName("btnMod");
        btnMod->setFont(font);
        btnMod->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnMod->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 127);"));

        gridLayout->addWidget(btnMod, 6, 7, 1, 1);

        btnLog2_10 = new QPushButton(centralwidget);
        btnLog2_10->setObjectName("btnLog2_10");
        btnLog2_10->setFont(font);
        btnLog2_10->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnLog2_10->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 80);"));

        gridLayout->addWidget(btnLog2_10, 4, 3, 1, 1);

        btnDel = new QPushButton(centralwidget);
        btnDel->setObjectName("btnDel");
        btnDel->setFont(font);
        btnDel->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDel->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 150, 110);"));

        gridLayout->addWidget(btnDel, 4, 7, 1, 1);

        btnLogAB = new QPushButton(centralwidget);
        btnLogAB->setObjectName("btnLogAB");
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(false);
        btnLogAB->setFont(font1);
        btnLogAB->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnLogAB->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 80);"));

        gridLayout->addWidget(btnLogAB, 4, 4, 1, 1);

        btn_x2_x10 = new QPushButton(centralwidget);
        btn_x2_x10->setObjectName("btn_x2_x10");
        btn_x2_x10->setFont(font);
        btn_x2_x10->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn_x2_x10->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 80);"));

        gridLayout->addWidget(btn_x2_x10, 3, 4, 1, 1);

        btnRadToDeg = new QPushButton(centralwidget);
        btnRadToDeg->setObjectName("btnRadToDeg");
        btnRadToDeg->setFont(font);
        btnRadToDeg->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnRadToDeg->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 54, 87);"));

        gridLayout->addWidget(btnRadToDeg, 3, 2, 1, 1);

        btnA_hex = new QPushButton(centralwidget);
        btnA_hex->setObjectName("btnA_hex");
        btnA_hex->setFont(font);
        btnA_hex->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnA_hex->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);\n"
"color: rgb(125,16,16);"));

        gridLayout->addWidget(btnA_hex, 11, 0, 1, 1);

        btnDegRad = new QPushButton(centralwidget);
        btnDegRad->setObjectName("btnDegRad");
        btnDegRad->setFont(font);
        btnDegRad->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDegRad->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 54, 87);\n"
"color: rgb(166, 89, 36);"));

        gridLayout->addWidget(btnDegRad, 3, 0, 1, 1);

        btnDot = new QPushButton(centralwidget);
        btnDot->setObjectName("btnDot");
        btnDot->setFont(font);
        btnDot->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDot->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btnDot, 8, 1, 1, 1);

        btnOr = new QPushButton(centralwidget);
        btnOr->setObjectName("btnOr");
        btnOr->setFont(font);
        btnOr->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnOr->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 121, 140);"));

        gridLayout->addWidget(btnOr, 10, 3, 1, 1);

        btnE_hex = new QPushButton(centralwidget);
        btnE_hex->setObjectName("btnE_hex");
        btnE_hex->setFont(font);
        btnE_hex->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnE_hex->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);\n"
"color: rgb(125,16,16);"));

        gridLayout->addWidget(btnE_hex, 11, 4, 1, 1);

        btnC = new QPushButton(centralwidget);
        btnC->setObjectName("btnC");
        btnC->setFont(font);
        btnC->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnC->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 100, 135);"));

        gridLayout->addWidget(btnC, 8, 5, 1, 2);

        btnD_hex = new QPushButton(centralwidget);
        btnD_hex->setObjectName("btnD_hex");
        btnD_hex->setFont(font);
        btnD_hex->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnD_hex->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);\n"
"color: rgb(125,16,16);"));

        gridLayout->addWidget(btnD_hex, 11, 3, 1, 1);

        btnTan = new QPushButton(centralwidget);
        btnTan->setObjectName("btnTan");
        QFont font2;
        font2.setPointSize(12);
        font2.setUnderline(false);
        btnTan->setFont(font2);
        btnTan->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnTan->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 54, 87);"));

        gridLayout->addWidget(btnTan, 2, 2, 1, 1);

        btnP = new QPushButton(centralwidget);
        btnP->setObjectName("btnP");
        btnP->setFont(font);
        btnP->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnP->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 100, 135);"));

        gridLayout->addWidget(btnP, 8, 7, 1, 1);

        btnSign = new QPushButton(centralwidget);
        btnSign->setObjectName("btnSign");
        btnSign->setFont(font);
        btnSign->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSign->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 37, 77);"));

        gridLayout->addWidget(btnSign, 6, 4, 1, 1);

        btnColon = new QPushButton(centralwidget);
        btnColon->setObjectName("btnColon");
        btnColon->setFont(font);
        btnColon->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnColon->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 47, 83);"));

        gridLayout->addWidget(btnColon, 7, 7, 1, 1);

        btnAcos = new QPushButton(centralwidget);
        btnAcos->setObjectName("btnAcos");
        btnAcos->setFont(font);
        btnAcos->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAcos->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 54, 87);"));

        gridLayout->addWidget(btnAcos, 2, 4, 1, 1);

        btnInv = new QPushButton(centralwidget);
        btnInv->setObjectName("btnInv");
        btnInv->setFont(font);
        btnInv->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnInv->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 127);"));

        gridLayout->addWidget(btnInv, 7, 4, 1, 1);

        btnNor = new QPushButton(centralwidget);
        btnNor->setObjectName("btnNor");
        btnNor->setFont(font);
        btnNor->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnNor->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 121, 140);"));

        gridLayout->addWidget(btnNor, 10, 4, 1, 1);

        btnOct = new QPushButton(centralwidget);
        btnOct->setObjectName("btnOct");
        btnOct->setFont(font);
        btnOct->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnOct->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);"));

        gridLayout->addWidget(btnOct, 9, 2, 1, 1);

        btnE = new QPushButton(centralwidget);
        btnE->setObjectName("btnE");
        btnE->setFont(font);
        btnE->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnE->setStyleSheet(QString::fromUtf8("background-color: rgb(66, 88, 111);"));

        gridLayout->addWidget(btnE, 3, 7, 1, 1);

        btnExp = new QPushButton(centralwidget);
        btnExp->setObjectName("btnExp");
        btnExp->setFont(font);
        btnExp->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnExp->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 80);"));

        gridLayout->addWidget(btnExp, 3, 5, 1, 2);

        btnB_hex = new QPushButton(centralwidget);
        btnB_hex->setObjectName("btnB_hex");
        btnB_hex->setFont(font);
        btnB_hex->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnB_hex->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);\n"
"color: rgb(125,16,16);"));

        gridLayout->addWidget(btnB_hex, 11, 1, 1, 1);

        btnXor = new QPushButton(centralwidget);
        btnXor->setObjectName("btnXor");
        btnXor->setFont(font);
        btnXor->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnXor->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 121, 140);"));

        gridLayout->addWidget(btnXor, 10, 5, 1, 2);

        btnNroot = new QPushButton(centralwidget);
        btnNroot->setObjectName("btnNroot");
        btnNroot->setFont(font);
        btnNroot->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnNroot->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 80);"));

        gridLayout->addWidget(btnNroot, 11, 7, 1, 1);

        btnAbs = new QPushButton(centralwidget);
        btnAbs->setObjectName("btnAbs");
        btnAbs->setFont(font);
        btnAbs->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAbs->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 85, 127);"));

        gridLayout->addWidget(btnAbs, 7, 5, 1, 2);

        btnFact = new QPushButton(centralwidget);
        btnFact->setObjectName("btnFact");
        btnFact->setFont(font);
        btnFact->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnFact->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 100, 135);"));

        gridLayout->addWidget(btnFact, 8, 4, 1, 1);

        btnBin = new QPushButton(centralwidget);
        btnBin->setObjectName("btnBin");
        btnBin->setFont(font);
        btnBin->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnBin->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);"));

        gridLayout->addWidget(btnBin, 9, 1, 1, 1);

        btnEq = new QPushButton(centralwidget);
        btnEq->setObjectName("btnEq");
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        btnEq->setFont(font3);
        btnEq->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnEq->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 60);\n"
"color: rgb(138, 75, 35);"));

        gridLayout->addWidget(btnEq, 8, 2, 1, 1);

        btnCbrt = new QPushButton(centralwidget);
        btnCbrt->setObjectName("btnCbrt");
        btnCbrt->setFont(font);
        btnCbrt->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnCbrt->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 60, 80);"));

        gridLayout->addWidget(btnCbrt, 4, 1, 1, 1);

        btn9 = new QPushButton(centralwidget);
        btn9->setObjectName("btn9");
        btn9->setFont(font);
        btn9->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn9->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn9, 5, 2, 1, 1);

        btnXnor = new QPushButton(centralwidget);
        btnXnor->setObjectName("btnXnor");
        btnXnor->setFont(font);
        btnXnor->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnXnor->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 121, 140);"));

        gridLayout->addWidget(btnXnor, 10, 7, 1, 1);

        btnC_hex = new QPushButton(centralwidget);
        btnC_hex->setObjectName("btnC_hex");
        btnC_hex->setFont(font);
        btnC_hex->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnC_hex->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);\n"
"color: rgb(125,16,16);"));

        gridLayout->addWidget(btnC_hex, 11, 2, 1, 1);

        btnAnd = new QPushButton(centralwidget);
        btnAnd->setObjectName("btnAnd");
        btnAnd->setFont(font);
        btnAnd->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAnd->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 121, 140);"));

        gridLayout->addWidget(btnAnd, 10, 1, 1, 1);

        btn0 = new QPushButton(centralwidget);
        btn0->setObjectName("btn0");
        btn0->setFont(font);
        btn0->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn0->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn0, 8, 0, 1, 1);

        btn1 = new QPushButton(centralwidget);
        btn1->setObjectName("btn1");
        btn1->setFont(font);
        btn1->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn1->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn1, 7, 0, 1, 1);

        btnAtan = new QPushButton(centralwidget);
        btnAtan->setObjectName("btnAtan");
        btnAtan->setFont(font);
        btnAtan->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAtan->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 54, 87);"));

        gridLayout->addWidget(btnAtan, 2, 5, 1, 2);

        btnSub = new QPushButton(centralwidget);
        btnSub->setObjectName("btnSub");
        btnSub->setFont(font);
        btnSub->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSub->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 37, 77);"));

        gridLayout->addWidget(btnSub, 7, 3, 1, 1);

        btnDec = new QPushButton(centralwidget);
        btnDec->setObjectName("btnDec");
        btnDec->setFont(font);
        btnDec->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDec->setStyleSheet(QString::fromUtf8("background-color: rgb(0,76,153);"));

        gridLayout->addWidget(btnDec, 9, 0, 1, 1);

        btnMul = new QPushButton(centralwidget);
        btnMul->setObjectName("btnMul");
        btnMul->setFont(font);
        btnMul->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnMul->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 37, 77);"));

        gridLayout->addWidget(btnMul, 6, 3, 1, 1);

        btn4 = new QPushButton(centralwidget);
        btn4->setObjectName("btn4");
        btn4->setFont(font);
        btn4->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btn4->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 85);"));

        gridLayout->addWidget(btn4, 6, 0, 1, 1);

        btnDiv = new QPushButton(centralwidget);
        btnDiv->setObjectName("btnDiv");
        btnDiv->setFont(font);
        btnDiv->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDiv->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 37, 77);"));

        gridLayout->addWidget(btnDiv, 5, 3, 1, 1);

        btnClear = new QPushButton(centralwidget);
        btnClear->setObjectName("btnClear");
        btnClear->setFont(font);
        btnClear->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnClear->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 150, 110);"));

        gridLayout->addWidget(btnClear, 4, 5, 1, 2);

        btnMem = new QPushButton(centralwidget);
        btnMem->setObjectName("btnMem");
        btnMem->setFont(font);
        btnMem->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnMem->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 140, 140);"));

        gridLayout->addWidget(btnMem, 5, 4, 1, 1);

        btnDmsToDec = new QPushButton(centralwidget);
        btnDmsToDec->setObjectName("btnDmsToDec");
        btnDmsToDec->setFont(font);
        btnDmsToDec->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDmsToDec->setStyleSheet(QString::fromUtf8("background-color: rgb(31, 47, 83);"));

        gridLayout->addWidget(btnDmsToDec, 9, 6, 1, 2);

        display = new QLineEdit(centralwidget);
        display->setObjectName("display");
        QFont font4;
        font4.setBold(false);
        display->setFont(font4);
        display->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
        display->setStyleSheet(QString::fromUtf8("font-size: 18px;"));
        display->setReadOnly(true);

        gridLayout->addWidget(display, 0, 0, 1, 8);

        btnLink = new QPushButton(centralwidget);
        btnLink->setObjectName("btnLink");
        btnLink->setFont(font);
        btnLink->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnLink->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 90, 60);"));

        gridLayout->addWidget(btnLink, 0, 8, 1, 1);

        btnPowMode = new QPushButton(centralwidget);
        btnPowMode->setObjectName("btnPowMode");
        btnPowMode->setFont(font);
        btnPowMode->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnPowMode->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 90, 60);"));

        gridLayout->addWidget(btnPowMode, 2, 8, 1, 1);


        formLayout->setLayout(0, QFormLayout::ItemRole::LabelRole, gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 738, 25));
        menuScientific_Calculator = new QMenu(menubar);
        menuScientific_Calculator->setObjectName("menuScientific_Calculator");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(true);
        statusbar->setBaseSize(QSize(0, 0));
        statusbar->setFont(font3);
        statusbar->setAutoFillBackground(false);
        statusbar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuScientific_Calculator->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
#if QT_CONFIG(tooltip)
        btnCos->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>cos(x) (Alt+C)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCos->setText(QCoreApplication::translate("MainWindow", "cos", nullptr));
        btn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
#if QT_CONFIG(tooltip)
        btnPI->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>constant \317\200 (P)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPI->setText(QCoreApplication::translate("MainWindow", "\317\200", nullptr));
#if QT_CONFIG(tooltip)
        btnLn->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>log<span style=\" vertical-align:sub;\">e</span>(x) (l)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLn->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
#if QT_CONFIG(tooltip)
        btnNot->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Bitwise not (~)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNot->setText(QCoreApplication::translate("MainWindow", "NOT", nullptr));
#if QT_CONFIG(tooltip)
        btnPercent->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Percentage (%)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPercent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
#if QT_CONFIG(tooltip)
        btnSin->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>sin(x) (Alt+S)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSin->setText(QCoreApplication::translate("MainWindow", "sin", nullptr));
        btn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
#if QT_CONFIG(tooltip)
        btnMemR->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Memory recall (Ctrl + M)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMemR->setText(QCoreApplication::translate("MainWindow", "MR", nullptr));
#if QT_CONFIG(tooltip)
        btnAsin->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>asin(x)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAsin->setText(QCoreApplication::translate("MainWindow", "asin", nullptr));
#if QT_CONFIG(tooltip)
        btnDegToRad->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Convert degrees to radians (Alt+r)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDegToRad->setText(QCoreApplication::translate("MainWindow", "\302\260\342\206\222rad", nullptr));
        btn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
#if QT_CONFIG(tooltip)
        btnMemC->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Reset memory (Alt+M)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMemC->setText(QCoreApplication::translate("MainWindow", "MC", nullptr));
#if QT_CONFIG(tooltip)
        btnDecToDms->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Convert from decimal to DMS (g)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDecToDms->setText(QCoreApplication::translate("MainWindow", "DEC\342\206\222DMS", nullptr));
#if QT_CONFIG(tooltip)
        btnSqrt->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>square root (Ctrl+S)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSqrt->setText(QCoreApplication::translate("MainWindow", "\342\210\232", nullptr));
#if QT_CONFIG(tooltip)
        btnNand->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Bitwise NAND (Alt+&amp;)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNand->setText(QCoreApplication::translate("MainWindow", "NAND", nullptr));
#if QT_CONFIG(tooltip)
        btnF_hex->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Hex digit F (F=15)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnF_hex->setText(QCoreApplication::translate("MainWindow", "F", nullptr));
        btn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btnAdd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(tooltip)
        btnHex->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Convert to hexadecimal (h)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnHex->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
#if QT_CONFIG(tooltip)
        btnPow->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>x<span style=\" vertical-align:super;\">y</span> (^)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPow->setText(QCoreApplication::translate("MainWindow", "x\312\270", nullptr));
#if QT_CONFIG(tooltip)
        btnMod->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Remainder (M)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMod->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
#if QT_CONFIG(tooltip)
        btnLog2_10->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>log<span style=\" vertical-align:sub;\">2</span>(x) (Ctrl+L)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLog2_10->setText(QCoreApplication::translate("MainWindow", "log\342\202\202", nullptr));
#if QT_CONFIG(tooltip)
        btnDel->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Delete digit (backspace)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDel->setText(QCoreApplication::translate("MainWindow", "DEL", nullptr));
#if QT_CONFIG(tooltip)
        btnLogAB->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>log<span style=\" vertical-align:sub;\">a</span>b (Alt+L)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLogAB->setText(QCoreApplication::translate("MainWindow", "log\342\202\220b", nullptr));
#if QT_CONFIG(tooltip)
        btn_x2_x10->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>x\302\262 (z)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btn_x2_x10->setText(QCoreApplication::translate("MainWindow", "x\302\262", nullptr));
#if QT_CONFIG(tooltip)
        btnRadToDeg->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Convert radians to degrees (Alt+d)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnRadToDeg->setText(QCoreApplication::translate("MainWindow", "rad\342\206\222\302\260", nullptr));
#if QT_CONFIG(tooltip)
        btnA_hex->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Hex digit A (A=10)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnA_hex->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
#if QT_CONFIG(tooltip)
        btnDegRad->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to radians mode (r)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDegRad->setText(QCoreApplication::translate("MainWindow", "DEG", nullptr));
        btnDot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
#if QT_CONFIG(tooltip)
        btnOr->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Bitwise OR (|)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnOr->setText(QCoreApplication::translate("MainWindow", "OR", nullptr));
#if QT_CONFIG(tooltip)
        btnE_hex->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Hex digit D (E=14)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnE_hex->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
#if QT_CONFIG(tooltip)
        btnC->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Combinations (c)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnC->setText(QCoreApplication::translate("MainWindow", "nCr", nullptr));
#if QT_CONFIG(tooltip)
        btnD_hex->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Hex digit D (D=13)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        btnD_hex->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        btnD_hex->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
#if QT_CONFIG(tooltip)
        btnTan->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>tan(x) (Alt+T)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnTan->setText(QCoreApplication::translate("MainWindow", "tan", nullptr));
#if QT_CONFIG(tooltip)
        btnP->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Permutations (p)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnP->setText(QCoreApplication::translate("MainWindow", "nPr", nullptr));
#if QT_CONFIG(tooltip)
        btnSign->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Change sign (s)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnSign->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
#if QT_CONFIG(tooltip)
        btnColon->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Colon for DMS format (:)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnColon->setText(QCoreApplication::translate("MainWindow", ":", nullptr));
#if QT_CONFIG(tooltip)
        btnAcos->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>acos(x)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAcos->setText(QCoreApplication::translate("MainWindow", "acos", nullptr));
#if QT_CONFIG(tooltip)
        btnInv->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Reciprocal of x (i)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnInv->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
#if QT_CONFIG(tooltip)
        btnNor->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Bitwise NOR (Alt+|)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNor->setText(QCoreApplication::translate("MainWindow", "NOR", nullptr));
#if QT_CONFIG(tooltip)
        btnOct->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Convert to octal (o)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnOct->setText(QCoreApplication::translate("MainWindow", "OCT", nullptr));
#if QT_CONFIG(tooltip)
        btnE->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>constant e (e)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnE->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
#if QT_CONFIG(tooltip)
        btnExp->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>e<span style=\" vertical-align:super;\">x</span> (x)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnExp->setText(QCoreApplication::translate("MainWindow", "exp", nullptr));
#if QT_CONFIG(tooltip)
        btnB_hex->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Hex digit B (B=11)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnB_hex->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
#if QT_CONFIG(tooltip)
        btnXor->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Bitwise XOR ($)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnXor->setText(QCoreApplication::translate("MainWindow", "XOR", nullptr));
#if QT_CONFIG(tooltip)
        btnNroot->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>n-th root (n)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnNroot->setText(QCoreApplication::translate("MainWindow", "\342\201\277\342\210\232", nullptr));
#if QT_CONFIG(tooltip)
        btnAbs->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Absolute value (a)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAbs->setText(QCoreApplication::translate("MainWindow", "abs", nullptr));
#if QT_CONFIG(tooltip)
        btnFact->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Factorial (!)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnFact->setText(QCoreApplication::translate("MainWindow", "n!", nullptr));
#if QT_CONFIG(tooltip)
        btnBin->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Convert to binary (b)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnBin->setText(QCoreApplication::translate("MainWindow", "BIN", nullptr));
#if QT_CONFIG(tooltip)
        btnEq->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Compute (Enter)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnEq->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
#if QT_CONFIG(tooltip)
        btnCbrt->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Cube root (Ctrl+C)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCbrt->setText(QCoreApplication::translate("MainWindow", "\302\263\342\210\232", nullptr));
        btn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
#if QT_CONFIG(tooltip)
        btnXnor->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Bitwise XNOR (Alt+$)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        btnXnor->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p>background-color: rgb(20, 121, 140);</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        btnXnor->setText(QCoreApplication::translate("MainWindow", "XNOR", nullptr));
#if QT_CONFIG(tooltip)
        btnC_hex->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Hex digit C (C=12)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnC_hex->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
#if QT_CONFIG(tooltip)
        btnAnd->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Bitwise AND (&amp;)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAnd->setText(QCoreApplication::translate("MainWindow", "AND", nullptr));
        btn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
#if QT_CONFIG(tooltip)
        btnAtan->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>atan(x)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAtan->setText(QCoreApplication::translate("MainWindow", "atan", nullptr));
        btnSub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
#if QT_CONFIG(tooltip)
        btnDec->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Convert to decimal (d)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDec->setText(QCoreApplication::translate("MainWindow", "DEC", nullptr));
        btnMul->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        btn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btnDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
#if QT_CONFIG(tooltip)
        btnClear->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Clear screen (esc)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnClear->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
#if QT_CONFIG(tooltip)
        btnMem->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Store to memory (m)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMem->setText(QCoreApplication::translate("MainWindow", "M", nullptr));
#if QT_CONFIG(tooltip)
        btnDmsToDec->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Convert from DMS to decimal (Alt+G)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDmsToDec->setText(QCoreApplication::translate("MainWindow", "DMS\342\206\222DEC", nullptr));
        display->setPlaceholderText(QCoreApplication::translate("MainWindow", "Input a number:", nullptr));
#if QT_CONFIG(tooltip)
        btnLink->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Open user manual (F1)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnLink->setText(QCoreApplication::translate("MainWindow", "HELP", nullptr));
#if QT_CONFIG(tooltip)
        btnPowMode->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>Switch to 10<span style=\" vertical-align:super;\">x </span>mode (y)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        btnPowMode->setText(QCoreApplication::translate("MainWindow", "x\302\262  \342\206\222 10\313\243", nullptr));
        menuScientific_Calculator->setTitle(QCoreApplication::translate("MainWindow", "Scientific Calculator", nullptr));
#if QT_CONFIG(tooltip)
        statusbar->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        statusbar->setWhatsThis(QString());
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
