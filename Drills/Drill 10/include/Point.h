//
// Created by J-C Borman on 3/31/2019.
//

#ifndef DRILL_10_POINT_H
#define DRILL_10_POINT_H

#include "std_lib_facilities.h"

class Point{
private:
    int x, y;
public:
    Point();
    Point(int x, int y);

    friend ostream& operator<< (ostream& os, const Point &pt);

    friend ofstream& operator<< (ofstream& ofs, const Point &pt);

    friend istream& operator>> (istream& is, Point &pt);

    bool operator==(const Point &other);

    bool operator!=(const Point &other);
};
#endif //DRILL_10_POINT_H
