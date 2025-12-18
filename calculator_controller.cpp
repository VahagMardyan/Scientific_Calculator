#include "calculator_controller.h"
#include "ids.h"
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

// Input
void CalculatorController::inputDigit(CalculatorState& s, int digit) {
    if (s.new_input) {
        s.display = std::to_string(digit);
        s.new_input = false;
    } else {
        if (s.display == "0")
            s.display = std::to_string(digit);
        else
            s.display += std::to_string(digit);
    }
    s.input = std::stod(s.display);
}

void CalculatorController::inputDot(CalculatorState& s) {
    if (s.new_input) {
        s.display = "0.";
        s.new_input = false;
    } else if (s.display.find('.') == std::string::npos) {
        s.display += '.';
    }
    s.input = std::stod(s.display);
}

void CalculatorController::backspace(CalculatorState& s) {
    if (s.new_input || s.display.empty())
        return;

    s.display.pop_back();

    if (s.display.empty() || s.display == "-") {
        s.display = "0";
        s.new_input = true;
    }

    s.input = std::stod(s.display);
}

void CalculatorController::changeSign(CalculatorState& s) {
    if (s.display == "0")
        return;

    if (s.display[0] == '-')
        s.display.erase(0, 1);
    else
        s.display.insert(0, 1, '-');

    s.input = std::stod(s.display);
}

// Binary Operations

void CalculatorController::setOperation(CalculatorState& s, Operation op) {
    s.acc = s.input;
    s.op = op;
    s.new_input = true;
}

void CalculatorController::calculate(CalculatorState& s) {
    switch (s.op) {
    case Operation::ADD:
        s.result = calc.add(s.acc, s.input);
        break;
    case Operation::SUB:
        s.result = calc.sub(s.acc, s.input);
        break;
    case Operation::MUL:
        s.result = calc.mul(s.acc, s.input);
        break;
    case Operation::DIV:
        s.result = calc.div(s.acc, s.input);
        break;
    case Operation::MOD:
        s.result = calc.mod((int)s.acc, (int)s.input);
        break;
    case Operation::PERCENT:
        s.result = calc.percent(s.acc, s.input);
        break;
    case Operation::POW:
        s.result = calc.xPowY(s.acc, s.input);
        break;
    case Operation::NROOT:
        s.result = calc.x_nroot(s.acc, s.input);
        break;
    case Operation::LOGAB:
        s.result = calc.log_a_b(s.acc, s.input);
        break;

    case Operation::AND:
        s.result = calc.bit_and((int)s.acc, (int)s.input);
        break;
    case Operation::NAND:
        s.result = calc.bit_nand((int)s.acc, (int)s.input);
        break;
    case Operation::OR:
        s.result = calc.bit_or((int)s.acc, (int)s.input);
        break;
    case Operation::NOR:
        s.result = calc.bit_nor((int)s.acc, (int)s.input);
        break;
    case Operation::XOR:
        s.result = calc.bit_xor((int)s.acc, (int)s.input);
        break;
    case Operation::XNOR:
        s.result = calc.bit_xnor((int)s.acc, (int)s.input);
        break;

    case Operation::C:
        s.result = calc.nCr((int)s.acc, (int)s.input);
        break;
    case Operation::P:
        s.result = calc.nPr((int)s.acc, (int)s.input);
        break;

    default:
        return;
    }

    if(std::isnan(s.result) || std::isinf(s.result)) {
        s.error = true;
        s.errorMsg = "There's a math error. Please check your arguments again.";
    }

    s.input = s.result;
    syncDisplay(s);
    s.op = Operation::NONE;
    s.new_input = true;
}

// nary Operations (by ID)

void CalculatorController::applyUnary(CalculatorState& s, int btnId) {
    switch (btnId) {
    case BTN_SIN:
        s.input = calc.sin(s.input, s.deg_mode);
        break;
    case BTN_COS:
        s.input = calc.cos(s.input, s.deg_mode);
        break;
    case BTN_TAN:
        s.input = calc.tan(s.input, s.deg_mode);
        break;
    case BTN_ASIN:
        s.input = calc.asin(s.input, s.deg_mode);
        break;
    case BTN_ACOS:
        s.input = calc.acos(s.input, s.deg_mode);
        break;
    case BTN_ATAN:
        s.input = calc.atan(s.input, s.deg_mode);
        break;
    case BTN_D_R:
        s.input = calc.deg_to_rad(s.input);
        break;
    case BTN_R_D:
        s.input = calc.rad_to_deg(s.input);
        break;

    case BTN_LN:
        s.input = calc.log_e(s.input);
        break;
    case BTN_LOG_2_10:
        s.input = s.pow_mode ? calc.log_2(s.input) : calc.log_10(s.input);
        break;
    case BTN_X2_10:
        s.input = s.pow_mode ? calc.x_2(s.input) : calc.x_10(s.input);
        break;

    case BTN_INV:
        s.input = calc.inv(s.input);
        break;
    case BTN_ABS:
        s.input = calc.absolute(s.input);
        break;
    case BTN_FACT:
        s.input = calc.factorial((int)s.input);
        break;

    case BTN_SQRT:
        s.input = calc.x_2root(s.input);
        break;
    case BTN_CBRT:
        s.input = calc.x_3root(s.input);
        break;
    case BTN_EXP:
        s.input = calc.e_x(s.input);
        break;

    case BTN_NOT:
        s.input = calc.bit_not((int)s.input);
        break;
    default:
        return;
    }

    if(std::isnan(s.input) || std::isinf(s.input)) {
        s.error = true;
        s.errorMsg = "There's a math error. Please check your argument again.";
    }

    syncDisplay(s);
    s.new_input = true;
}

// Modes

void CalculatorController::toggleDegRad(CalculatorState& s) {
    s.deg_mode = !s.deg_mode;
}

void CalculatorController::togglePowMode(CalculatorState& s) {
    s.pow_mode = !s.pow_mode;
}

// Memory

void CalculatorController::memStore(CalculatorState& s) {
    s.memory = std::stod(s.display);
    s.new_input = true;
}

void CalculatorController::memRecall(CalculatorState& s) {
    s.input = s.memory;
    syncDisplay(s);
    s.new_input = true;
}

void CalculatorController::memClear(CalculatorState& s) {
    s.memory = 0.0;
}

// Base conversion

void CalculatorController::convertBase(CalculatorState& s, int newBase) {
        s.display = calc.convert_base(s.display, s.base, newBase);
        s.base = newBase;
        s.new_input = true;
}

// Clear

void CalculatorController::clearAll(CalculatorState& s) {
    double mem = s.memory;
    s = CalculatorState{};
    s.memory = mem;
}

// Display Sync

void CalculatorController::syncDisplay(CalculatorState& s) {
    std::ostringstream oss;
    oss << std::setprecision(15) << s.input;
    s.display = oss.str();
}
