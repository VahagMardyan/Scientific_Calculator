#pragma once
#define _USE_MATH_DEFINES
#include <QMainWindow>
#include <QString>
#include <QPushButton>
#include "calc.h"
#include "calculator_controller.h"
#include "calculator_state.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    void addShortcut(QPushButton*, const QString&);

    Scientific_Calculator calc;          // Core
    CalculatorController controller;     // Controller
    CalculatorState state;               // Current calculator state

    void updateDisplay();                // Updates QLineEdit display

    void connectButtons();               // Connect UI buttons to Controller/Core
};
