/******************************************************************************************************
 * @file  Complex.cpp
 * @brief Implementation of the Complex class
 ******************************************************************************************************/

#include "Complex.hpp"

#include <random>

Complex::Complex() : x(), y() { }

Complex::Complex(double x, double y) : x(x), y(y) { }

Complex Complex::random(double min, double max) {
    std::random_device device;
    std::mt19937 generator(device());
    std::uniform_real_distribution<double> distribution(min, max);

    return Complex(distribution(generator), distribution(generator));
}

Complex Complex::random(double minX, double maxX, double minY, double maxY) {
    std::random_device device;
    std::mt19937 generator(device());

    std::uniform_real_distribution<double> distributionX(minX, maxX);
    std::uniform_real_distribution<double> distributionY(minY, maxY);

    return Complex(distributionX(generator), distributionY(generator));
}

double triangleArea(const Complex& A, const Complex& B, const Complex& C) {
    return 0.5 * std::abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

bool isInTriangle(const Complex& P, const Complex& A, const Complex& B, const Complex& C) {
    return triangleArea(A, B, C)
           == (triangleArea(P, B, C)
               + triangleArea(P, A, C)
               + triangleArea(P, A, B));
}