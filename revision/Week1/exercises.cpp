#include <cmath>
#include <stdexcept>

namespace {
constexpr double pi = 3.14159265358979323846;
}

double formulaOne(double x) {
    if (x <= 0) {
        throw std::domain_error("formulaOne requires x > 0");
    }

    const double denominator = std::log(x) + x / 4.0;
    if (denominator == 0) {
        throw std::domain_error("formulaOne is undefined for this value of x");
    }

    const double radicand = (std::sin(x) - std::pow(x, 5)) / denominator;
    if (radicand < 0) {
        throw std::domain_error("formulaOne is undefined for this value of x");
    }

    return std::sqrt(radicand);
}

double formulaTwo(double a, double b, double c) {
    if (a == 0) {
        throw std::domain_error("formulaTwo requires a nonzero");
    }

    const double discriminant = b * b - 4.0 * a * c;
    if (discriminant < 0) {
        throw std::domain_error("formulaTwo has no real solution");
    }

    return (-b + std::sqrt(discriminant)) / (2.0 * a);
}

double formulaThree(double x, double m, double s) {
    if (s <= 0) {
        throw std::domain_error("formulaThree requires s > 0");
    }

    const double standardized = (x - m) / s;
    return std::exp(-0.5 * standardized * standardized)
        / std::sqrt(2.0 * pi * s);
}