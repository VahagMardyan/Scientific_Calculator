#pragma once
#include "calculator_state.h"
#include "unar_ids.h"
#include "calc.h"

class CalculatorController {
public:
    // input
    void inputDigit(CalculatorState&, int);
    void inputDot(CalculatorState&);
    void backspace(CalculatorState&);
    void changeSign(CalculatorState&);

    // binary ops
    void setOperation(CalculatorState&, Operation);
    void calculate(CalculatorState&);

    // unary ops (by button id)
    void applyUnary(CalculatorState&, Unar_ids);

    // modes
    void toggleDegRad(CalculatorState&);
    void togglePowMode(CalculatorState&);

    // memory
    void memClear(CalculatorState&);
    void memStore(CalculatorState&);
    void memRecall(CalculatorState&);

    // base
    void convertBase(CalculatorState&, int);

    void clearAll(CalculatorState&);

private:
    Scientific_Calculator calc;
    void syncDisplay(CalculatorState&);
};
