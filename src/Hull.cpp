/******************************************************************************************************
 * @file  Hull.cpp
 * @brief Implementation of the Hull class
 ******************************************************************************************************/

#include "Hull.hpp"

Hull::Hull() : points() { }

Hull::Hull(const std::vector<Complex>& set) : points(set) { }

void Hull::quickHull() {
    hull.clear();

    int leftmost = 0, rightmost = 0;
    for(int i = 0 ; i < points.size() ; ++i) {
        if(points[i].x < points[leftmost].x) {
            leftmost = i;
        }

        if(points[i].x > points[rightmost].x) {
            rightmost = i;
        }
    }

    const double a = (points[rightmost].y - points[leftmost].y) / (points[rightmost].x - points[leftmost].x);
    const double b = points[leftmost].y - a * points[leftmost].x;

    std::vector<Complex> top, bottom;
    for(const Complex& point: points) {
        if(point.x * a + b < point.y) {
            top.push_back(point);
        } else {
            bottom.push_back(point);
        }
    }

    hull.push_back(points[leftmost]);
    hull.push_back(points[rightmost]);

    findHull(top, points[leftmost], points[rightmost]);
    findHull(bottom, points[rightmost], points[leftmost]);
}

void Hull::getHull(const std::vector<Complex>& set) {
    points = set;
    quickHull();
}

std::vector<Complex> setOnRightOfLine(const std::vector<Complex>& set, const Complex& A, const Complex& B) {
    const double a = (B.y - A.y) / (B.x - A.x);
    const double b = A.y - a * A.x;

    std::vector<Complex> subset;

    if(A.x < B.x) {
        for(const Complex& point: set) {
            if(point.x * a + b < point.y) {
                subset.push_back(point);
            }
        }
    } else {
        for(const Complex& point: set) {
            if(point.x * a + b > point.y) {
                subset.push_back(point);
            }
        }
    }

    return subset;
}

void Hull::findHull(const std::vector<Complex>& subset, const Complex& A, const Complex& B) {
    if(subset.empty()) {
        return;
    }

    unsigned int farthest = 0;
    for(int i = 0 ; i < subset.size() ; ++i) {
        if(triangleArea(A, subset[i], B) > triangleArea(A, subset[farthest], B)) {
            farthest = i;
        }
    }

    const Complex& F = subset[farthest];

    int placement = 0;
    while(!(hull[placement].x == A.x && hull[placement].y == A.y)) {
        ++placement;
    }
    hull.insert(hull.begin() + placement, F);

    std::vector<Complex> outsideAFB;
    for(const Complex& point: subset) {
        if(!isInTriangle(point, A, F, B)) {
            outsideAFB.push_back(point);
        }
    }

    // Points on the right of the oriented line from A to F
    findHull(setOnRightOfLine(outsideAFB, A, F), A, F);

    // Points on the right of the oriented line from F to B
    findHull(setOnRightOfLine(outsideAFB, F, B), F, B);
}