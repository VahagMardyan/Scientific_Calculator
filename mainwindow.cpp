#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QRegularExpression>

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

void MainWindow::addShortcut(QPushButton* button, const QString& key) {
    QAction* act = new QAction(this);
    QKeySequence seq(key);
    act->setShortcut(seq);
    act->setShortcutContext(Qt::ApplicationShortcut);
    connect(act, &QAction::triggered, button, &QPushButton::click);
    addAction(act);
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
        ui -> statusbar -> showMessage("Input second addend");
    });
    ui->btnAdd->setShortcut(QKeySequence("+"));

    connect(ui->btnSub, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::SUB);
        ui -> statusbar -> showMessage("Input subtrahend");
    });
    ui->btnSub->setShortcut(QKeySequence("-"));

    connect(ui->btnMul, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::MUL);
        ui -> statusbar -> showMessage("Input multiplicand");
    });
    ui->btnMul->setShortcut(QKeySequence("*"));

    connect(ui->btnDiv, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::DIV);
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
    addShortcut(ui->btnEq, "Enter");

    // Unary / Trig
    connect(ui->btnSin, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, Unar_ids::Sin);
        updateDisplay();
    });
    ui->btnSin->setShortcut(QKeySequence("Alt+S"));

    connect(ui->btnCos, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, Unar_ids::Cos);
        updateDisplay();
    });
    ui->btnCos->setShortcut(QKeySequence("Alt+C"));

    connect(ui->btnTan, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, Unar_ids::Tan);
        updateDisplay();
    });
    ui->btnTan->setShortcut(QKeySequence("Alt+T"));

    connect(ui->btnAsin, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, Unar_ids::Asin);
        updateDisplay();
    });
    connect(ui->btnAcos, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, Unar_ids::Acos);
        updateDisplay();
    });
    connect(ui->btnAtan, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, Unar_ids::Atan);
        updateDisplay();
    });

    connect(ui->btnLn, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, Unar_ids::Ln);
        updateDisplay();
    });

    addShortcut(ui->btnLn, "l");

    connect(ui->btnLog2_10, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, state.pow_mode ? Unar_ids::Log_2 : Unar_ids::Log_10);
        updateDisplay();
    });

    addShortcut(ui->btnLog2_10, "Ctrl+L");

    connect(ui->btnLogAB, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::LOGAB);
        ui -> statusbar -> showMessage("Input value for log(a,b)");
    });
    addShortcut(ui->btnLogAB, "Alt+L");

    connect(ui->btnSqrt, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, Unar_ids::Sqrt);
        updateDisplay();
    });
    addShortcut(ui->btnSqrt, "Ctrl+S");

    connect(ui->btnCbrt, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, Unar_ids::Cbrt);
        updateDisplay();
    });

    connect(ui->btnExp, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, Unar_ids::Exp);
        updateDisplay();
    });
    addShortcut(ui->btnExp, "x");

    connect(ui->btn_x2_x10, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, state.pow_mode ? Unar_ids::X2 : Unar_ids::Pow_10X);
        updateDisplay();
    });
    addShortcut(ui->btn_x2_x10, "z");

    connect(ui->btnPow, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::POW);
        ui->statusbar->showMessage("Input power");
    });
    addShortcut(ui->btnPow, "^");

    connect(ui->btnNroot, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::NROOT);
        ui->statusbar->showMessage("Input root");
    });
    addShortcut(ui->btnNroot, "n");

    connect(ui->btnPercent, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::PERCENT);
        ui->statusbar->showMessage("Input percentage");
    });
    addShortcut(ui->btnPercent, "%");

    connect(ui->btnMod, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::MOD);
        ui->statusbar->showMessage("Input divisor for modulo");
    });
    addShortcut(ui->btnMod, "Shift+M");

    connect(ui->btnAbs, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, Unar_ids::Abs);
        updateDisplay();
    });

    connect(ui->btnInv, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, Unar_ids::Inverse);
        updateDisplay();
    });
    addShortcut(ui->btnInv, "i");

    // Memory

    connect(ui->btnMem, &QPushButton::clicked, this, [this](){
        controller.memStore(state);
        ui->statusbar->showMessage("Stored in memory: " + QString::fromStdString(state.display));
    });
    addShortcut(ui->btnMem, "m");

    connect(ui->btnMemR, &QPushButton::clicked, this, [this](){
        controller.memRecall(state);
        ui->display->setText(QString::fromStdString(state.display));
        ui->statusbar->showMessage("Called from memory: " + QString::fromStdString(state.display));
    });
    addShortcut(ui->btnMemR, "Ctrl+M");

    connect(ui->btnMemC, &QPushButton::clicked, this, [this](){
        controller.memClear(state);
        ui->statusbar->showMessage("Memory erased");
    });
    addShortcut(ui->btnMemC, "Alt+M");

    // DEG / RAD toggle
    connect(ui->btnDegRad, &QPushButton::clicked, this, [this](){
        controller.toggleDegRad(state);
        ui->btnDegRad->setText(state.deg_mode ? "DEG" : "RAD");
        ui->statusbar->showMessage(state.deg_mode ? "DEG mode" : "RAD mode");
        ui->btnDegRad->setToolTip(state.deg_mode ? "Change to radians mode (r)" : "Change to degrees mode (r)");
    });
    addShortcut(ui->btnDegRad, "r");

    connect(ui->btnDegToRad, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, Unar_ids::DegToRad);
        updateDisplay();
    });
    addShortcut(ui->btnDegToRad, "Alt+R");

    connect(ui->btnRadToDeg, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, Unar_ids::RadToDeg);
        updateDisplay();
    });
    addShortcut(ui->btnRadToDeg, "Alt+D");

    // // constants π, e
    connect(ui->btnE, &QPushButton::clicked, this, [this](){
        state.input = M_E;
        state.display = std::to_string(state.input);
        ui->display->setText(QString::number(state.input, 'g', 15));
    });
    addShortcut(ui->btnE, "e");

    connect(ui->btnPI, &QPushButton::clicked, this, [this](){
        state.input = M_PI;
        state.display = std::to_string(state.input);
        ui->display->setText(QString::number(state.input, 'g', 15));
    });
    addShortcut(ui->btnPI, "Shift+P");

    // POW mode toggle
    connect(ui->btnPowMode, &QPushButton::clicked, this, [this](){
        controller.togglePowMode(state);
        ui->btnLog2_10->setText(state.pow_mode ? "log₂" : "log₁₀");
        ui->btn_x2_x10->setText(state.pow_mode ? "x²" : "10^x");
        ui->btnPowMode->setText(state.pow_mode ? "x² → 10^x" : "10^x → x²");
        ui->statusbar->showMessage(state.pow_mode ? "x² mode" : "10^x mode");
        ui->btn_x2_x10->setToolTip(state.pow_mode ? "x² (z)" : "10^x (z)");
        ui->btnLog2_10->setToolTip(state.pow_mode ? "2-base logarithm (Ctrl+L)" : "10-base logarithm (Ctrl+L)");
        ui->btnPowMode->setToolTip(state.pow_mode ? "Switch to 10^x mode (y)" : "Switch to x² mode (y)");
    });
    addShortcut(ui->btnPowMode, "y");

    // // Bin, Oct, Dec and Hex
    connect(ui->btnBin, &QPushButton::clicked, this, [this](){
        controller.convertBase(state, 2);
        updateDisplay();
        ui->statusbar->showMessage("BIN mode");
    });
    addShortcut(ui->btnBin, "b");

    connect(ui->btnOct, &QPushButton::clicked, this, [this](){
        controller.convertBase(state, 8);
        updateDisplay();
        ui->statusbar->showMessage("OCT mode");
    });
    addShortcut(ui->btnOct, "o");

    connect(ui->btnDec, &QPushButton::clicked, this, [this](){
        controller.convertBase(state, 10);
        updateDisplay();
        ui->statusbar->showMessage("DEC mode");
    });
    addShortcut(ui->btnDec, "d");

    connect(ui->btnHex, &QPushButton::clicked, this, [this](){
        controller.convertBase(state, 16);
        updateDisplay();
        ui->statusbar->showMessage("HEX mode");
    });
    addShortcut(ui->btnHex, "h");

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
    addShortcut(ui->btnA_hex,"Shift+A");

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
    addShortcut(ui->btnB_hex,"Shift+B");

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
    addShortcut(ui->btnC_hex,"Shift+C");

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
    addShortcut(ui->btnD_hex,"Shift+D");

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
    addShortcut(ui->btnE_hex,"Shift+E");

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
    addShortcut(ui->btnF_hex,"Shift+F");

    // // DMS -> DEC and DEC -> DMS

    connect(ui->btnColon, &QPushButton::clicked, this, [this]() {
        QString text = ui->display->text();

        if (!text.endsWith(":")) {
            text += ":";
            ui->display->setText(text);
            state.display = text.toStdString();
        }
    });
    addShortcut(ui->btnColon, ":");

    connect(ui->btnDecToDms, &QPushButton::clicked, this, [this]() {
        double dec_deg = state.input;
        std::string result = calc.to_sexagesimal(dec_deg);

        // Update display
        ui->display->setText(QString::fromStdString(result));
        state.display = result;
        state.new_input = true;

        ui->statusbar->showMessage("DEC → DMS");
    });
    addShortcut(ui->btnDecToDms, "g");

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
    addShortcut(ui->btnDmsToDec, "Alt+G");

    // // Factorial, nCr, nPr
    connect(ui->btnFact, &QPushButton::clicked, this, [this](){
        controller.applyUnary(state, Unar_ids::Factorial);
        updateDisplay();
    });
    addShortcut(ui->btnFact, "!");

    // // nCr
    connect(ui->btnC, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::C);
        ui->statusbar->showMessage("Enter second number for nCr");
    });
    addShortcut(ui->btnC, "c");

    // // nPr
    connect(ui->btnP, &QPushButton::clicked, this, [this](){
        controller.setOperation(state, Operation::P);
        ui->statusbar->showMessage("Enter second number for nPr");
    });
    addShortcut(ui->btnP, "p");

    // not and nor etc
    connect(ui->btnNot, &QPushButton::clicked, this, [this]() {
        controller.applyUnary(state, Unar_ids::BitNot);
        updateDisplay();
    });
    addShortcut(ui->btnNot, "~");

    connect(ui->btnAnd, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::AND);
        ui->statusbar->showMessage("Enter second number for AND");
    });
    addShortcut(ui->btnAnd, "&");

    connect(ui->btnNand, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::NAND);
        ui->statusbar->showMessage("Enter second number for NAND");
    });

    connect(ui->btnOr, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::OR);
        ui->statusbar->showMessage("Enter second number for OR");
    });
    addShortcut(ui->btnOr, "|");

    connect(ui->btnNor, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::NOR);
        ui->statusbar->showMessage("Enter second number for NOR");
    });

    connect(ui->btnXor, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::XOR);
        ui->statusbar->showMessage("Enter second number for XOR");
    });
    addShortcut(ui->btnXor, "$");

    connect(ui->btnXnor, &QPushButton::clicked, this, [this]() {
        controller.setOperation(state, Operation::XNOR);
        ui->statusbar->showMessage("Enter second number for XNOR");
    });

    // User Manual
    connect(ui->btnLink, &QPushButton::clicked, this, [this]() {
        QDesktopServices::openUrl(QUrl("https://vahagmardyan.github.io/Synopsys_Course_Project_User_Manual/"));
        ui->statusbar->showMessage("Opening User Manual");
    });
    ui->btnLink->setShortcut(QKeySequence("F1"));
}

