#pragma once
#include "string"

enum class Operation {
    NONE, 
    ADD, SUB, MUL, DIV, MOD, PERCENT,
    LOGAB, POW, C, P, 
    AND, NAND, OR, NOR, 
    XOR, XNOR, NROOT, 
};

struct CalculatorState {
    double acc = 0.0;
    double input = 0.0;
    double result = 0;
    
    Operation op = Operation::NONE;
    
    bool new_input = true;
    bool deg_mode = true;
    bool pow_mode = true;
    bool error = false;
    std::string errorMsg;

    int base = 10;
    double memory = 0;

    std::string display;
};

