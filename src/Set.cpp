/******************************************************************************************************
 * @file  Set.cpp
 * @brief Implementation of the Set class
 ******************************************************************************************************/

#include "Set.hpp"

Set::Set() : points() { }

Set::Set(int n, double minX, double maxX, double minY, double maxY) : points(n) {
    for(Complex& point: points) {
        point = Complex::random(minX, maxX, minY, maxY);
    }
}

void Set::regenerate(int n, double minX, double maxX, double minY, double maxY) {
    points.resize(n);

    for(Complex& point: points) {
        point = Complex::random(minX, maxX, minY, maxY);
    }
}