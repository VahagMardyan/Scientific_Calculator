#include "calculator_controller.h"
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

// Input

void CalculatorController::inputSymbol(CalculatorState& s, char c) {
    if (s.new_input || s.display == "0") {
        s.display = std::string(1, c);
        s.new_input = false;
    } else {
        s.display += c;
    }

    if (s.base != 16) {
        if (!s.display.empty() &&
            (isdigit(s.display[0]) || s.display[0] == '+' || s.display[0] == '.')) {
            try {
                s.input = std::stod(s.display);
            } catch (...) {
                s.input = 0;
                s.error = true;
                s.errorMsg = "Invalid number";
            }
        }
    }
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
    if (s.display.empty())
        return;

    s.display.pop_back();

    if (s.display.empty() || s.display == "-") {
        s.display = "0";
        s.new_input = true;
    }

    if(s.base != 16) {
        try {
            s.input = std::stod(s.display);
        } catch(...) {
            s.input = 0;
            s.error = true;
            s.errorMsg = "Invalid number";
        }
    }
}

void CalculatorController::changeSign(CalculatorState& s) {
    if (s.display.empty() || s.display == "0")
        return;

    if (s.display[0] == '-')
        s.display.erase(0, 1);
    else
        s.display.insert(0, 1, '-');

    if (s.base != 16) {
        try {
            s.input = std::stod(s.display);
        } catch (...) {
            s.input = 0;
            s.error = true;
            s.errorMsg = "Invalid number";
        }
    }
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
        s.result = calc.mod(static_cast<int>(s.acc), static_cast<int>(s.input));
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
        s.result = calc.bit_and(static_cast<int>(s.acc), static_cast<int>(s.input));
        break;
    case Operation::NAND:
        s.result = calc.bit_nand(static_cast<int>(s.acc), static_cast<int>(s.input));
        break;
    case Operation::OR:
        s.result = calc.bit_or(static_cast<int>(s.acc), static_cast<int>(s.input));
        break;
    case Operation::NOR:
        s.result = calc.bit_nor(static_cast<int>(s.acc), static_cast<int>(s.input));
        break;
    case Operation::XOR:
        s.result = calc.bit_xor(static_cast<int>(s.acc), static_cast<int>(s.input));
        break;
    case Operation::XNOR:
        s.result = calc.bit_xnor(static_cast<int>(s.acc), static_cast<int>(s.input));
        break;

    case Operation::C:
        s.result = calc.nCr(static_cast<int>(s.acc), static_cast<int>(s.input));
        break;
    case Operation::P:
        s.result = calc.nPr(static_cast<int>(s.acc), static_cast<int>(s.input));
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

// Unary Operations

void CalculatorController::applyUnary(CalculatorState& s, Unar_ids btnId) {
    switch (btnId) {
    case Unar_ids::Sin:
        s.input = calc.sin(s.input, s.deg_mode);
        break;
    case Unar_ids::Cos:
        s.input = calc.cos(s.input, s.deg_mode);
        break;
    case Unar_ids::Tan:
        s.input = calc.tan(s.input, s.deg_mode);
        break;
    case Unar_ids::Asin:
        s.input = calc.asin(s.input, s.deg_mode);
        break;
    case Unar_ids::Acos:
        s.input = calc.acos(s.input, s.deg_mode);
        break;
    case Unar_ids::Atan:
        s.input = calc.atan(s.input, s.deg_mode);
        break;
    case Unar_ids::DegToRad:
        s.input = calc.deg_to_rad(s.input);
        break;
    case Unar_ids::RadToDeg:
        s.input = calc.rad_to_deg(s.input);
        break;

    case Unar_ids::Ln:
        s.input = calc.log_e(s.input);
        break;
    case Unar_ids::Log_2:
        s.input = calc.log_2(s.input);
        break;
    case Unar_ids::Log_10:
        s.input = calc.log_10(s.input);
        break;
    case Unar_ids::X2:
        s.input = calc.x_2(s.input);
        break;
    case Unar_ids::Pow_10X:
        s.input = calc.x_10(s.input);
        break;

    case Unar_ids::Inverse:
        s.input = calc.inv(s.input);
        break;
    case Unar_ids::Abs:
        s.input = calc.absolute(s.input);
        break;
    case Unar_ids::Factorial:
        s.input = calc.factorial(static_cast<int>(s.input));
        break;

    case Unar_ids::Sqrt:
        s.input = calc.x_2root(s.input);
        break;
    case Unar_ids::Cbrt:
        s.input = calc.x_3root(s.input);
        break;
    case Unar_ids::Exp:
        s.input = calc.e_x(s.input);
        break;

    case Unar_ids::BitNot:
        s.input = calc.bit_not(static_cast<int>(s.input));
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
    if(s.display.empty()) {
        s.memory = 0;
        return;
    }
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
    bool deg_rad_mode = s.deg_mode;
    bool pow_mode = s.pow_mode;
    s = CalculatorState{};
    s.memory = mem;
    s.deg_mode = deg_rad_mode;
    s.pow_mode = pow_mode;
}

// Display Sync

void CalculatorController::syncDisplay(CalculatorState& s) {
    std::ostringstream oss;
    oss << std::setprecision(15) << s.input;
    s.display = oss.str();
}

