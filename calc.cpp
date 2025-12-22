#define _USE_MATH_DEFINES
#include "calc.h"
#include <cmath>
#include <algorithm>

double Scientific_Calculator::sin(double v, bool deg) const {
    if (deg) v = v * M_PI / 180.0;
    return std::sin(v);
}

double Scientific_Calculator::cos(double v, bool deg) const {
    if (deg) v = v * M_PI / 180.0;
    return std::cos(v);
}

double Scientific_Calculator::tan(double v, bool deg) const {
    if (deg) v = v * M_PI / 180.0;
    return std::tan(v);
}

double Scientific_Calculator::asin(double v, bool deg) const {
    double r = std::asin(v);
    return deg ? r * 180.0 / M_PI : r;
}

double Scientific_Calculator::acos(double v, bool deg) const {
    double r = std::acos(v);
    return deg ? r * 180.0 / M_PI : r;
}

double Scientific_Calculator::atan(double v, bool deg) const {
    double r = std::atan(v);
    return deg ? r * 180.0 / M_PI : r;
}

double Scientific_Calculator::deg_to_rad(double val) const {
    return val * M_PI / 180.0;
}

double Scientific_Calculator::rad_to_deg(double val) const {
    return val * 180.0 / M_PI;
}

double Scientific_Calculator::xPowY(double x, double y) const {
    return std::pow(x, y);
}

double Scientific_Calculator::x_2(double v) const { 
    return v * v; 
}

double Scientific_Calculator::x_10(double v) const {
    return std::pow(10, v);
}

double Scientific_Calculator::e_x(double v) const {
    return std::exp(v);
}

double Scientific_Calculator::x_2root(double v) const {
    if (v < 0) {
        return std::nan("");
    }
    return std::sqrt(v);
}

double Scientific_Calculator::x_3root(double v) const {
    return std::cbrt(v);
}

double Scientific_Calculator::x_nroot(double x, double n) const {
    if(n == 0) {
        return std::nan("");
    }
    else if (x < 0 && std::fmod(n,2.0) == 0) {
        return std::nan("");
    }
    return x >=0 ? std::pow(x, 1.0 / n) : -std::pow(-x, 1.0 / n);
}

double Scientific_Calculator::log_e(double v) const {
    return std::log(v);
}

double Scientific_Calculator::log_10(double v) const {
    return std::log10(v);
}

double Scientific_Calculator::log_2(double v) const {
    return std::log2(v);
}

double Scientific_Calculator::log_a_b(double a, double b) const {
    return std::log(b) / std::log(a);
}

double Scientific_Calculator::add(double a, double b) const { 
    return a + b; 
}

double Scientific_Calculator::sub(double a, double b) const { 
    return a - b; 
}

double Scientific_Calculator::mul(double a, double b) const { 
    return a * b; 
}


double Scientific_Calculator::div(double a, double b) const {
    return a / b;
}

int Scientific_Calculator::mod(int a, int b) const {
    return a % b;
}

double Scientific_Calculator::percent(double x, double p) const {
    return x * p / 100.0;
}

double Scientific_Calculator::inv(double x) const {
    return 1.0 / x;
}

double Scientific_Calculator::absolute(double a) const {
    return std::fabs(a);
}

double Scientific_Calculator::factorial(int n) const {
    if (n < 0) {
        return std::nan("");
    }
    double r = 1.0;
    for (int i = 2; i <= n; ++i) r *= i;
    return r;
}

double Scientific_Calculator::nCr(int n, int r) const {
    if (n < r || r < 0) {
        return std::nan("");
    };
    if (r > n - r) r = n - r;
    double res = 1;
    for (int i = 1; i <= r; ++i)
        res = res * (n - i + 1) / i;
    return res;
}

double Scientific_Calculator::nPr(int n, int r) const {
    if (n < r) {
        return std::nan("");
    }
    double res = 1;
    for (int i = 0; i < r; ++i) res *= (n - i);
    return res;
}

std::string Scientific_Calculator::int_to_base(
    long long num, int base_to, int bits, bool twos_complement) const {

    if (num == 0) return "0";

    const std::string digits = "0123456789ABCDEF";

    bool negative = (num < 0);
    unsigned long long u;

    if (negative && twos_complement && base_to != 10) {
        u = (1ULL << bits) + num; // this is the same as (1*2^bits)+num
    } else {
        u = negative ? static_cast<unsigned long long>(-num) : static_cast<unsigned long long>(num);
    }

    std::string result;
    while (u > 0) {
        result.push_back(digits[u % base_to]);
        u /= base_to;
    }

    std::reverse(result.begin(), result.end());

    if (negative && (base_to == 10 || !twos_complement)) {
        result.insert(result.begin(), '-');
    }

    return result;
}

std::string Scientific_Calculator::convert_base(
    const std::string& num_str, int base_from, int base_to, int bits, bool twos_complement) const {

    std::string s = num_str;
    if (s.empty())
        return "0";

    bool negative = false;

    if (s[0] == '-') {
        negative = true;
        s.erase(0, 1);
    }

    long long num = 0;

    try {
        if (base_from == 10) {
            num = std::stoll(s, nullptr, 10); // long long
        } else {
            unsigned long long raw = std::stoull(s, nullptr, base_from); // unsigned long long

            // two's complement input
            if (!negative && twos_complement && bits > 0 && (raw & (1ULL << (bits - 1)))) {
                num = static_cast<long long>(raw - (1ULL << bits));
            } else {
                num = static_cast<long long>(raw);
            }
        }
    }
    catch (...) {
        return "0";
    }

    if (negative) {
        num = -num;
    }

    return int_to_base(num, base_to, bits, twos_complement);
}

// // DMS <-> DEC
std::string Scientific_Calculator::to_sexagesimal(double d) const {
    bool neg = d < 0;
    d = std::fabs(d);
    int deg = static_cast<int>(d);
    int min = static_cast<int>((d - deg) * 60);
    double sec = ((d - deg) * 60 - min) * 60;
    return (neg ? "-" : "") +
           std::to_string(deg) + "° " +
           std::to_string(min) + "' " +
           std::to_string(sec) + "\"";
}

double Scientific_Calculator::from_sexagesimal(
    int d, int m, double s) const {
    double sign = d < 0 ? -1 : 1;
    return sign * (std::abs(d) + m / 60.0 + s / 3600.0);
}

int Scientific_Calculator::bit_not(int v) const {
    return ~v;
}

int Scientific_Calculator::bit_and(int a, int b) const {
    return a & b;
}

int Scientific_Calculator::bit_nand(int a, int b) const {
    return ~(a & b);
}

int Scientific_Calculator::bit_or(int a, int b) const {
    return a | b;
}

int Scientific_Calculator::bit_nor(int a, int b) const {
    return ~(a | b);
}

int Scientific_Calculator::bit_xor(int a, int b) const {
    return a ^ b;
}

int Scientific_Calculator::bit_xnor(int a, int b) const {
    return ~(a ^ b);
}

