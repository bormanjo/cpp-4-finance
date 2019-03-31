//
// Created by J-C Borman on 3/31/2019.
//

#include "Point.h"
#include "std_lib_facilities.h"

Point::Point() {
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

ostream& operator<< (ostream& os, const Point &pt){
    os << "(" << pt.x << ", " << pt.y << ")";
}

ofstream& operator<< (ofstream& ofs, const Point &pt){
    ofs << pt.x << "\n" << pt.y << "\n";
}

istream& operator>> (istream& is, Point &pt){
    is >> pt.x >> pt.y;
    return is;
}

bool Point::operator==(const Point &other){
    if(x == other.x && y == other.y){
        return true;
    } else {
        return false;
    }
}

bool Point::operator!=(const Point &other) {
    return !(this->operator==(other));
}