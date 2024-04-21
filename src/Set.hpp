/******************************************************************************************************
 * @file  Set.hpp
 * @brief Declaration of the Set class
 ******************************************************************************************************/

#pragma once

#include <vector>

#include "Complex.hpp"

/**
 * @class Set
 * @brief Represents a set of Complex numbers
 */
class Set {
public:
    /**
     * @brief Default constructor
     */
     Set();

    /**
     * @brief Constructor with parameters
     *
     * @param n The number of points in the set
     */
    Set(int n, double minX, double maxX, double minY, double maxY);

    /**
     * @brief Reallocates the 'points' vector with n random points
     *
     * @param n The number of points in the new set
     */
    void regenerate(int n, double minX, double maxX, double minY, double maxY);

    std::vector<Complex> points; ///< The set of points
};