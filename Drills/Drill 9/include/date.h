//
// Created by J-C Borman on 3/31/2019.
//

#ifndef DRILL_9_DATE_H
#define DRILL_9_DATE_H

// Version 9.4.1

struct Date_9_4_1 {
    int y;
    int m;
    int d;
    friend ostream& operator<<(::ostream &stream, const Date_9_4_1 &dd);
};

void init_day(Date_9_4_1 &dd, int y, int m, int d);
void add_day(Date_9_4_1 &dd, int n);

// Version 9.4.2

struct Date_9_4_2 {
    int y, m, d;
    Date_9_4_2(int y, int m, int d);
    void add_day(int n);

    friend ostream& operator<<(::ostream &stream, const Date_9_4_2 &dd);
};

// Version 9.4.3

class Date_9_4_3 {
    int y, m, d;
public:
    Date_9_4_3(int y, int m, int d);
    void add_day(int n);
    int month() {return m;}
    int day() { return m;}
    int year() {return y;}

    friend ostream& operator<<(::ostream &stream, const Date_9_4_3 &dd);
};

// Version 9.7.1

enum class Month {
    jan=1, feb, mar, apr, may, jun, july, aug, sep, oct, nov, dec
};

class Year {
    static const int min = 1800;
    static const int max = 2200;
private:
    int y;
public:
    class Invalid {};
    Year(){y = min;}
    explicit Year(const int x) : y{x} {if(x < min || max <= x) throw Invalid{};}
    int year() const {return y;}

    friend ostream& operator<<(::ostream &stream, const Year &y);
};

class Date_9_7_1{
public:
    Date_9_7_1(Year y, Month m, int d);
    Date_9_7_1();

    void add_day(int n);

    friend ostream& operator<<(::ostream &stream, const Date_9_7_1 &dd);
private:
    Year y;
    Month m;
    int d;
};

// Version 9.7.4

class Date_9_7_4{
public:
    int day() const;
    Month month() const;
    int year() const;

    Date_9_7_4(int y, Month m, int d);
    Date_9_7_4();

    void add_day(int n);
    void add_month(int n);
    void add_year(int n);

    friend ostream& operator<<(::ostream &stream, const Date_9_7_4 &dd);

private:
    int y;
    Month m;
    int d;
};


#endif //DRILL_9_DATE_H
