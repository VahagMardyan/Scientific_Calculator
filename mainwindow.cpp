#define _USE_MATH_DEFINES
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QString>
#include <QDesktopServices>
#include <QUrl>
#include <QRegularExpression>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connect all buttons to Core/Controller
    connectButtons();

    // Initialize display
    updateDisplay();
}

MainWindow::~MainWindow() {
    delete ui;
}

// Helper
void MainWindow::updateDisplay() {
    if(state.error) {
        ui->display->setText(QString::fromStdString(state.errorMsg));
    } else {
        ui->display->setText(QString::fromStdString(state.display));
    }
}

// Connect Buttons
void MainWindow::connectButtons() {

    // Digits 0-9
    connect(ui->btn0, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 0);
        updateDisplay();
    });
    ui->btn0->setShortcut(QKeySequence("0"));

    connect(ui->btn1, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 1);
        updateDisplay();
    });
    ui->btn1->setShortcut(QKeySequence("1"));

    connect(ui->btn2, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 2);
        updateDisplay();
    });
    ui->btn2->setShortcut(QKeySequence("2"));

    connect(ui->btn3, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 3);
        updateDisplay();
    });
    ui->btn3->setShortcut(QKeySequence("3"));

    connect(ui->btn4, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 4);
        updateDisplay();
    });
    ui->btn4->setShortcut(QKeySequence("4"));

    connect(ui->btn5, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 5);
        updateDisplay();
    });
    ui->btn5->setShortcut(QKeySequence("5"));

    connect(ui->btn6, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 6);
        updateDisplay(); });
    ui->btn6->setShortcut(QKeySequence("6"));

    connect(ui->btn7, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 7);
        updateDisplay();
    });
    ui->btn7->setShortcut(QKeySequence("7"));

    connect(ui->btn8, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 8);
        updateDisplay();
    });
    ui->btn8->setShortcut(QKeySequence("8"));

    connect(ui->btn9, &QPushButton::clicked, this, [this](){
        controller.inputDigit(state, 9); updateDisplay();
    });
    ui->btn9->setShortcut(QKeySequence("9"));

    // Dot
    connect(ui->btnDot, &QPushButton::clicked, this, [this](){
        controller.inputDot(state); updateDisplay();
    });
    ui->btnDot->setShortcut(QKeySequence("."));

    // Operations
    connect(ui->btnAdd, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::ADD);
        state.acc = state.input;
        state.new_input = true;
        ui -> statusbar -> showMessage("Input second addend");
    });
    ui->btnAdd->setShortcut(QKeySequence("+"));

    connect(ui->btnSub, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::SUB);
        state.acc = state.input;
        state.new_input = true;
        ui -> statusbar -> showMessage("Input subtrahend");
    });
    ui->btnSub->setShortcut(QKeySequence("-"));

    connect(ui->btnMul, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::MUL);
        state.acc = state.input;
        state.new_input = true;
        ui -> statusbar -> showMessage("Input multiplicand");
    });
    ui->btnMul->setShortcut(QKeySequence("*"));

    connect(ui->btnDiv, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::DIV);
        state.acc = state.input;
        state.new_input = true;
        ui -> statusbar -> showMessage("Input divisor");
    });
    ui->btnDiv->setShortcut(QKeySequence("/"));

    // // Clear / Backspace / Sign
    connect(ui->btnClear, &QPushButton::clicked, this, [this](){
        controller.clearAll(state);
        updateDisplay();
        ui->statusbar->showMessage("");
    });
    ui->btnClear->setShortcut(QKeySequence("Escape"));
    connect(ui->btnDel, &QPushButton::clicked, this, [this](){
        controller.backspace(state);
        updateDisplay();
    });
    ui->btnDel->setShortcut(QKeySequence("Backspace"));
    connect(ui->btnSign, &QPushButton::clicked, this, [this](){
        controller.changeSign(state);
        updateDisplay();
    });
    ui->btnSign->setShortcut(QKeySequence("s"));

    // Equals
    connect(ui->btnEq, &QPushButton::clicked, this, [this](){
        controller.calculate(state);
        updateDisplay();
    });
    ui->btnEq->setShortcut(QKeySequence(Qt::Key_Return)); // Main enter

    // Unary / Trig
    connect(ui->btnSin, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_SIN);
        updateDisplay();
    });
    ui->btnSin->setShortcut(QKeySequence("Alt+S"));

    connect(ui->btnCos, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_COS);
        updateDisplay();
    });
    ui->btnCos->setShortcut(QKeySequence("Alt+C"));

    connect(ui->btnTan, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_TAN);
        updateDisplay();
    });
    ui->btnTan->setShortcut(QKeySequence("Alt+T"));

    connect(ui->btnAsin, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_ASIN);
        updateDisplay();
    });
    connect(ui->btnAcos, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_ACOS);
        updateDisplay();
    });
    connect(ui->btnAtan, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_ATAN);
        updateDisplay();
    });

    connect(ui->btnLn, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_LN);
        updateDisplay();
    });

    QAction* actLn = new QAction(this);
    actLn->setShortcut(QKeySequence("l"));
    connect(actLn, &QAction::triggered, this, [this](){
        ui->btnLn->click();
    });
    addAction(actLn);

    connect(ui->btnLog2_10, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_LOG_2_10);
        updateDisplay();
    });

    QAction* actLog2_10 = new QAction(this);
    actLog2_10->setShortcut(QKeySequence("Ctrl+L"));
    connect(actLog2_10, &QAction::triggered, this, [this]() {
        ui->btnLog2_10->click();
    });
    addAction(actLog2_10);

    connect(ui->btnLogAB, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::LOGAB);
        state.acc = state.input;
        state.new_input = true;
        ui -> statusbar -> showMessage("Input value for log(a,b)");
    });
    QAction* actLogAB = new QAction(this);
    actLogAB->setShortcut(QKeySequence("Alt+l"));
    connect(actLogAB, &QAction::triggered, this, [this]() {
        ui->btnLogAB->click();
    });
    addAction(actLogAB);

    connect(ui->btnSqrt, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, BTN_SQRT);
        updateDisplay();
    });
    QAction* actSqrt = new QAction(this);
    actSqrt -> setShortcut(QKeySequence("Ctrl+S"));
    connect(actSqrt, &QAction::triggered, this, [this]() {
        ui->btnSqrt->click();
    });
    addAction(actSqrt);

    connect(ui->btnCbrt, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, BTN_CBRT);
        updateDisplay();
    });

    connect(ui->btnExp, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, BTN_EXP);
        updateDisplay();
    });
    QAction* actExp = new QAction(this);
    actExp -> setShortcut(QKeySequence("x"));
    connect(actExp, &QAction::triggered, this, [this]() {
        ui->btnExp->click();
    });
    addAction(actExp);

    connect(ui->btn_x2_x10, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_X2_10);
        updateDisplay();
    });
    QAction* act_X2_X10 = new QAction(this);
    act_X2_X10 -> setShortcut(QKeySequence("z"));
    connect(act_X2_X10, &QAction::triggered, this, [this]() {
        ui->btn_x2_x10->click();
    });
    addAction(act_X2_X10);

    connect(ui->btnPow, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::POW);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Input power");
    });
    QAction* actPow = new QAction(this);
    actPow -> setShortcut(QKeySequence("^"));
    connect(actPow, &QAction::triggered, this, [this]() {
        ui->btnPow->click();
    });
    addAction(actPow);

    connect(ui->btnNroot, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::NROOT);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Input root");
    });
    QAction* actNroot = new QAction(this);
    actNroot -> setShortcut(QKeySequence("n"));
    connect(actNroot, &QAction::triggered, this, [this]() {
        ui->btnNroot->click();
    });
    addAction(actNroot);

    connect(ui->btnPercent, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::PERCENT);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Input percentage");
    });
    QAction* actPercent = new QAction(this);
    actPercent -> setShortcut(QKeySequence("%"));
    connect(actPercent, &QAction::triggered, this, [this]() {
        ui->btnPercent->click();
    });
    addAction(actPercent);

    connect(ui->btnMod, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::MOD);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Input modulo");
    });
    QAction* actMod = new QAction(this);
    actMod -> setShortcut(QKeySequence("Shift+M"));
    connect(actMod, &QAction::triggered, this, [this]() {
        ui->btnMod->click();
    });
    addAction(actMod);

    connect(ui->btnAbs, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, BTN_ABS);
        updateDisplay();
    });

    connect(ui->btnInv, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, BTN_INV);
        updateDisplay();
    });
    QAction* actInv = new QAction(this);
    actInv -> setShortcut(QKeySequence("i"));
    connect(actInv, &QAction::triggered, this, [this]() {
        ui->btnInv->click();
    });
    addAction(actInv);


    // Memory

    connect(ui->btnMem, &QPushButton::clicked, this, [this](){
        controller.memStore(state);
        ui->statusbar->showMessage("Stored in memory: " + QString::fromStdString(state.display));
    });
    QAction* actMem = new QAction(this);
    actMem->setShortcut(QKeySequence("m"));
    connect(actMem, &QAction::triggered, this, [this]() {
        ui->btnMem->click();
    });
    addAction(actMem);

    connect(ui->btnMemR, &QPushButton::clicked, this, [this](){
        controller.memRecall(state);
        ui->display->setText(QString::fromStdString(state.display));
        ui->statusbar->showMessage("Called from memory: " + QString::fromStdString(state.display));
    });
    QAction* actMemR = new QAction(this);
    actMemR->setShortcut(QKeySequence("Ctrl+M"));
    connect(actMemR, &QAction::triggered, this, [this]() {
        ui->btnMemR->click();
    });
    addAction(actMemR);

    connect(ui->btnMemC, &QPushButton::clicked, this, [this](){
        controller.memClear(state);
        ui->statusbar->showMessage("Memory erased");
    });
    QAction* actMemC = new QAction(this);
    actMemC->setShortcut(QKeySequence("Alt+M"));
    connect(actMemC, &QAction::triggered, this, [this]() {
        ui->btnMemC->click();
    });
    addAction(actMemC);

    // DEG / RAD toggle
    QAction* actDegRad = new QAction(this);
    actDegRad->setShortcut(QKeySequence("r"));

    connect(actDegRad, &QAction::triggered, this, [this](){
        controller.toggleDegRad(state);
        ui->btnDegRad->setText(state.deg_mode ? "DEG" : "RAD");
        ui->statusbar->showMessage(state.deg_mode ? "DEG mode" : "RAD mode");
        ui->btnDegRad->setToolTip(state.deg_mode ? "Change to radians mode (r)" : "Change to degrees mode (r)");
    });
    addAction(actDegRad);
    connect(ui->btnDegRad, &QPushButton::clicked, this, [=](){
        actDegRad->trigger();
    });

    connect(ui->btnDegToRad, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, BTN_D_R);
        updateDisplay();
    });
    QAction* actD_R = new QAction(this);
    actD_R -> setShortcut(QKeySequence("Alt+R"));
    connect(actD_R, &QAction::triggered, this, [this]() {
        ui->btnDegToRad->click();
    });
    addAction(actD_R);

    connect(ui->btnRadToDeg, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, BTN_R_D);
        updateDisplay();
    });
    QAction* actR_D = new QAction(this);
    actR_D -> setShortcut(QKeySequence("Alt+D"));
    connect(actR_D, &QAction::triggered, this, [this]() {
        ui->btnRadToDeg->click();
    });
    addAction(actR_D);

    connect(ui->btnE, &QPushButton::clicked, this, [this](){
        state.input = M_E;
        state.display = std::to_string(state.input);
        ui->display->setText(QString::number(state.input, 'g', 15));
    });
    QAction* actE = new QAction(this);
    actE -> setShortcut(QKeySequence("e"));
    connect(actE, &QAction::triggered, this, [this]() {
        ui->btnE->click();
    });
    addAction(actE);

    connect(ui->btnPI, &QPushButton::clicked, this, [this](){
        state.input = M_PI;
        state.display = std::to_string(state.input);
        ui->display->setText(QString::number(state.input, 'g', 15));
    });
    QAction* actPI = new QAction(this);
    actPI -> setShortcut(QKeySequence("Shift+P"));
    connect(actPI, &QAction::triggered, this, [this]() {
        ui->btnPI->click();
    });
    addAction(actPI);

    // POW mode toggle
    connect(ui->btnPowMode, &QPushButton::clicked, this, [this](){
        controller.togglePowMode(state);
        ui->btnLog2_10->setText(state.pow_mode ? "log₂" : "log₁₀");
        ui->btn_x2_x10->setText(state.pow_mode ? "x²" : "10^x");
        ui->btnPowMode->setText(state.pow_mode ? "x² -> 10^x" : "10^x -> x²");
        ui->statusbar->showMessage(state.pow_mode ? "X² mode" : "10^x mode");
        ui->btn_x2_x10->setToolTip(state.pow_mode ? "x² (z)" : "10^x");
        ui->btnLog2_10->setToolTip(state.pow_mode ? "2-base logarithm (Ctrl+L)" : "10-base logarithm (Ctrl+L)");
        ui->btnPowMode->setToolTip(state.pow_mode ? "Switch to 10^x mode (y)" : "Switch to x² mode (y)");
    });
    QAction* actPowMode = new QAction(this);
    actPowMode->setShortcut(QKeySequence("y"));
    connect(actPowMode, &QAction::triggered, this, [this](){
        ui->btnPowMode->click();
    });
    addAction(actPowMode);

    // // Bin, Oct, Dec and Hex
    connect(ui->btnBin, &QPushButton::clicked, this, [this](){
        controller.convertBase(state, 2);
        updateDisplay();
        ui->statusbar->showMessage("BIN mode");
    });
    QAction* actBin = new QAction(this);
    actBin -> setShortcut(QKeySequence("b"));
    connect(actBin, &QAction::triggered, this, [this](){
        ui->btnBin->click();
    });
    addAction(actBin);

    connect(ui->btnOct, &QPushButton::clicked, this, [this](){
        controller.convertBase(state, 8);
        updateDisplay();
        ui->statusbar->showMessage("OCT mode");
    });
    QAction* actOct = new QAction(this);
    actOct -> setShortcut(QKeySequence("o"));
    connect(actOct, &QAction::triggered, this, [this](){
        ui->btnOct->click();
    });
    addAction(actOct);

    connect(ui->btnDec, &QPushButton::clicked, this, [this](){
        controller.convertBase(state, 10);
        updateDisplay();
        ui->statusbar->showMessage("DEC mode");
    });
    QAction* actDec = new QAction(this);
    actDec -> setShortcut(QKeySequence("d"));
    connect(actDec, &QAction::triggered, this, [this](){
        ui->btnDec->click();
    });
    addAction(actDec);

    connect(ui->btnHex, &QPushButton::clicked, this, [this](){
        controller.convertBase(state, 16);
        updateDisplay();
        ui->statusbar->showMessage("HEX mode");
    });
    QAction* actHex = new QAction(this);
    actHex -> setShortcut(QKeySequence("h"));
    connect(actHex, &QAction::triggered, this, [this](){
        ui->btnHex->click();
    });
    addAction(actHex);

    connect(ui->btnA_hex, &QPushButton::clicked, this, [this]() {
        if(state.base == 16) {
            QString text = ui->display->text();
            text+="A";
            ui->display->setText(text);
            state.display = text.toStdString();
        } else {
            ui->statusbar->showMessage("Switch to HEX mode at first.");
        }
    });
    QAction* actBtnAhex = new QAction(this);
    actBtnAhex->setShortcut(QKeySequence("Shift+A"));
    connect(actBtnAhex, &QAction::triggered, this, [this]() {
        ui->btnA_hex->click();
    });
    addAction(actBtnAhex);

    connect(ui->btnB_hex, &QPushButton::clicked, this, [this]() {
        if(state.base == 16) {
            QString text = ui->display->text();
            text+="B";
            ui->display->setText(text);
            state.display = text.toStdString();
        } else {
            ui->statusbar->showMessage("Switch to HEX mode at first.");
        }
    });
    QAction* actBtnBhex = new QAction(this);
    actBtnBhex->setShortcut(QKeySequence("Shift+B"));
    connect(actBtnBhex, &QAction::triggered, this, [this]() {
        ui->btnB_hex->click();
    });
    addAction(actBtnBhex);

    connect(ui->btnC_hex, &QPushButton::clicked, this, [this]() {
        if(state.base == 16) {
            QString text = ui->display->text();
            text+="C";
            ui->display->setText(text);
            state.display = text.toStdString();
        } else {
            ui->statusbar->showMessage("Switch to HEX mode at first.");
        }
    });
    QAction* actBtnChex = new QAction(this);
    actBtnChex->setShortcut(QKeySequence("Shift+C"));
    connect(actBtnChex, &QAction::triggered, this, [this]() {
        ui->btnC_hex->click();
    });
    addAction(actBtnChex);

    connect(ui->btnD_hex, &QPushButton::clicked, this, [this]() {
        if(state.base == 16) {
            QString text = ui->display->text();
            text+="D";
            ui->display->setText(text);
            state.display = text.toStdString();
        } else {
            ui->statusbar->showMessage("Switch to HEX mode at first.");
        }
    });
    QAction* actBtnDhex = new QAction(this);
    actBtnDhex->setShortcut(QKeySequence("Shift+D"));
    connect(actBtnDhex, &QAction::triggered, this, [this]() {
        ui->btnD_hex->click();
    });
    addAction(actBtnDhex);

    connect(ui->btnE_hex, &QPushButton::clicked, this, [this]() {
        if(state.base == 16) {
            QString text = ui->display->text();
            text+="E";
            ui->display->setText(text);
            state.display = text.toStdString();
        } else {
            ui->statusbar->showMessage("Switch to HEX mode at first.");
        }
    });
    QAction* actBtnEhex = new QAction(this);
    actBtnEhex->setShortcut(QKeySequence("Shift+E"));
    connect(actBtnEhex, &QAction::triggered, this, [this]() {
        ui->btnE_hex->click();
    });
    addAction(actBtnEhex);

    connect(ui->btnF_hex, &QPushButton::clicked, this, [this]() {
        if(state.base == 16) {
            QString text = ui->display->text();
            text+="F";
            ui->display->setText(text);
            state.display = text.toStdString();
        } else {
            ui->statusbar->showMessage("Switch to HEX mode at first.");
        }
    });
    QAction* actBtnFhex = new QAction(this);
    actBtnFhex->setShortcut(QKeySequence("Shift+F"));
    connect(actBtnFhex, &QAction::triggered, this, [this]() {
        ui->btnF_hex->click();
    });
    addAction(actBtnFhex);

    // // DMS -> DEC and DEC -> DMS

    connect(ui->btnColon, &QPushButton::clicked, this, [this]() {
        QString text = ui->display->text();

        if (!text.endsWith(":")) {
            text += ":";
            ui->display->setText(text);
            state.display = text.toStdString();
        }
    });
    QAction* actColon = new QAction(this);
    actColon -> setShortcut(QKeySequence(":"));
    connect(actColon, &QAction::triggered, this, [this](){
        ui->btnColon->click();
    });
    addAction(actColon);

    connect(ui->btnDecToDms, &QPushButton::clicked, this, [this]() {
        double dec_deg = state.input;
        std::string result = calc.to_sexagesimal(dec_deg);

        // Update display
        ui->display->setText(QString::fromStdString(result));
        state.display = result;
        state.new_input = true;

        ui->statusbar->showMessage("DEC → DMS");
    });

    QAction* actDecToDms = new QAction(this);
    actDecToDms->setShortcut(QKeySequence("G"));
    connect(actDecToDms, &QAction::triggered, this, [this](){
        ui->btnDecToDms->click();
    });
    addAction(actDecToDms);

    connect(ui->btnDmsToDec, &QPushButton::clicked, this, [this]() {
        QString text = ui->display->text();
        QStringList tokens = text.split(QRegularExpression("[°′\"':\\s]+"), Qt::SkipEmptyParts);

        if (tokens.size() < 3) {
            ui->statusbar->showMessage("Invalid D:M:S format");
            return;
        }

        bool ok1, ok2, ok3;
        int D = tokens[0].toInt(&ok1);
        int M = tokens[1].toInt(&ok2);
        double S = tokens[2].toDouble(&ok3);

        if (!ok1 || !ok2 || !ok3) {
            ui->statusbar->showMessage("Invalid numbers in D:M:S");
            return;
        }

        double dec = calc.from_sexagesimal(D, M, S);
        state.input = dec;
        state.display = std::to_string(dec);
        ui->display->setText(QString::number(dec));
        ui->statusbar->showMessage("DMS → DEC");
    });

    QAction* actDmsToDec = new QAction(this);
    actDmsToDec->setShortcut(QKeySequence("Alt+G"));
    connect(actDmsToDec, &QAction::triggered, this, [this](){
        ui->btnDmsToDec->click();
    });
    addAction(actDmsToDec);

    // // Factorial, nCr, nPr
    connect(ui->btnFact, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, BTN_FACT);
        updateDisplay();
    });
    QAction* actFact = new QAction(this);
    actFact -> setShortcut(QKeySequence("!"));
    connect(actFact, &QAction::triggered, this, [this]() {
        ui->btnFact->click();
    });
    addAction(actFact);


    // // nCr
    connect(ui->btnC, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::C);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Enter second number for nCr");
    });
    QAction* actNcR = new QAction(this);
    actNcR->setShortcut(QKeySequence("c"));
    connect(actNcR, &QAction::triggered, this, [this](){
        ui->btnC->click();
    });
    addAction(actNcR);


    // // nPr
    connect(ui->btnP, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::P);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Enter second number for nPr");
    });
    QAction* actNpR = new QAction(this);
    actNpR->setShortcut(QKeySequence("p"));
    connect(actNpR, &QAction::triggered, this, [this](){
        ui->btnP->click();
    });
    addAction(actNpR);

    // not and nor etc
    connect(ui->btnNot, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, BTN_NOT);
        updateDisplay();
    });
    QAction* actNot = new QAction(this);
    actNot->setShortcut(QKeySequence("~"));
    connect(actNot, &QAction::triggered, this, [this](){
        ui->btnNot->click();
    });
    addAction(actNot);

    connect(ui->btnAnd, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::AND);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Enter second number for AND");
    });
    QAction* actAnd = new QAction(this);
    actAnd->setShortcut(QKeySequence("&"));
    connect(actAnd, &QAction::triggered, this, [this](){
        ui->btnAnd->click();
    });
    addAction(actAnd);

    connect(ui->btnNand, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::NAND);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Enter second number for NAND");
    });

    connect(ui->btnOr, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::OR);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Enter second number for OR");
    });
    QAction* actOr = new QAction(this);
    actOr->setShortcut(QKeySequence("|"));
    connect(actOr, &QAction::triggered, this, [this](){
        ui->btnOr->click();
    });
    addAction(actOr);

    connect(ui->btnNor, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::NOR);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Enter second number for NOR");
    });

    connect(ui->btnXor, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::XOR);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Enter second number for XOR");
    });
    QAction* actXor = new QAction(this);
    actXor->setShortcut(QKeySequence("$"));
    connect(actXor, &QAction::triggered, this, [this](){
        ui->btnXor->click();
    });
    addAction(actXor);

    connect(ui->btnXnor, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::XNOR);
        state.acc = state.input;
        state.new_input = true;
        ui->statusbar->showMessage("Enter second number for XNOR");
    });

    // User Manual
    connect(ui->btnLink, &QPushButton::clicked, this, [this]() {
        QDesktopServices::openUrl(QUrl("https://vahagmardyan.github.io/Synopsys_Course_Project_User_Manual/"));
        ui->statusbar->showMessage("Opening User Manual");
    });
    ui->btnLink->setShortcut(QKeySequence("F1"));
}

