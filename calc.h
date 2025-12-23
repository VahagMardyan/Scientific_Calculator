#pragma once
#include <string>

class Scientific_Calculator {
public:
    // Trigonometry
    double sin(double val, bool deg) const;
    double cos(double val, bool deg) const;
    double tan(double val, bool deg) const;

    double asin(double val, bool deg) const;
    double acos(double val, bool deg) const;
    double atan(double val, bool deg) const;

    double deg_to_rad(double val) const;
    double rad_to_deg(double val) const;

    // Power & Roots
    double xPowY(double x, double y) const;
    double x_2(double val) const;
    double x_10(double val) const;
    double e_x(double val) const;

    double x_2root(double val) const;
    double x_3root(double val) const;
    double x_nroot(double x, double n) const;

    // Logarithms
    double log_e(double val) const;
    double log_10(double val) const;
    double log_2(double val) const;
    double log_a_b(double a, double b) const;

    // Arithmetic
    double add(double a, double b) const;
    double sub(double a, double b) const;
    double mul(double a, double b) const;
    double div(double a, double b) const;
    int    mod(int a, int b) const;
    double percent(double x, double p) const;
    double inv(double x) const;
    double absolute(double a) const;

    // Combinatorics
    double factorial(int n) const;
    double nCr(int n, int r) const;
    double nPr(int n, int r) const;

    // Base Conversion
    std::string convert_base(
        const std::string& value,
        int base_from,
        int base_to,
        int bits = 64,
        bool twos_complement = true
    ) const;

    // Sexagesimal
    std::string to_sexagesimal(double dec_degree) const;
    double from_sexagesimal(int deg, int min, double sec) const;

    // Bitwise
    int bit_not(int val) const;
    int bit_and(int a, int b) const;
    int bit_nand(int a, int b) const;
    int bit_or(int a, int b) const;
    int bit_nor(int a, int b) const;
    int bit_xor(int a, int b) const;
    int bit_xnor(int a, int b) const;

private:
    std::string int_to_base(long long num, int base_to, int bits, bool twos_complement) const;
};
