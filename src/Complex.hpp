/******************************************************************************************************
 * @file  Complex.hpp
 * @brief Declaration of the Complex class
 ******************************************************************************************************/

#pragma once

#include <cmath>

/**
 * @class Complex
 * @brief Class representing a complex number
 */
class Complex {
public:
    /**
     * @brief Default constructor
     */
    Complex();

    /**
     * @brief Constructor with parameters
     *
     * @param x The real part
     * @param y The imaginary part
     */
    Complex(double x, double y);

    /**
     * @brief Generates a random complex number with both parts in the same range
     *
     * @param min The minimum value for x and y
     * @param max The maximum value for x and y
     *
     * @return A random complex number
     */
    static Complex random(double min, double max);

    /**
     * @brief Generates a random complex number
     *
     * @param minX The minimum value for x
     * @param maxX The maximum value for x
     * @param minY The minimum value for y
     * @param maxY The maximum value for y
     *
     * @return A random complex number
     */
    static Complex random(double minX, double maxX, double minY, double maxY);

    double x; ///< The real part
    double y; ///< The imaginary part
};

/**
 * @brief Calculates the are of a triangle
 *
 * @param A The first point of the triangle
 * @param B The second point of the triangle
 * @param C The third point of the triangle
 *
 * @return The area of the triangle ABC
 */
double triangleArea(const Complex& A, const Complex& B, const Complex& C);

/**
 * @brief Checks whether a point is inside a triangle
 *
 * @param P The point we want to check
 * @param A The first point of the triangle
 * @param B The second point of the triangle
 * @param C The third point of the triangle
 *
 * @return Whether P is inside the triangle ABC
 */
bool isInTriangle(const Complex& P, const Complex& A, const Complex& B, const Complex& C);