#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calc.h"
#include "calculator_controller.h"
#include "calculator_state.h"
#include "ids.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;

    Scientific_Calculator calc;          // Core
    CalculatorController controller;     // Controller
    CalculatorState state;               // Current calculator state

    void updateDisplay();                // Updates QLineEdit display

    void connectButtons();               // Connect UI buttons to Controller/Core

};

#endif // MAINWINDOW_H
