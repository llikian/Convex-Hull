/******************************************************************************************************
 * @file  Hull.hpp
 * @brief Declaration of the Hull class
 ******************************************************************************************************/

#pragma once

#include "Complex.hpp"

#include <vector>

/**
 * @class Hull
 * @brief The convex hull of a set of points
 */
class Hull {
public:
    /**
     * @brief Default constructor
     */
    Hull();;

    /**
     * @brief Constructor with a certain set
     * @param set The set of points
     */
    Hull(const std::vector<Complex>& set);;

    /**
     * @brief Calculates the convex hull of the set using the quickhull alhorithm
     * @source https://en.wikipedia.org/wiki/Quickhull
     */
    void quickHull();

    /**
     * @brief Calculates the convex hull of the set
     *
     * @param set The new set of points
     */
    void getHull(const std::vector<Complex>& set);

    void findHull(const std::vector<Complex>& subset, const Complex& A, const Complex& B);

    std::vector<Complex> points;
    std::vector<Complex> hull;
};