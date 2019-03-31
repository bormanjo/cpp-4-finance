//
// Created by J-C Borman on 3/31/2019.
//

#include "std_lib_facilities.h"
#include "date.h"

// Version 9.4.1 -------------------------------------------------------

void init_day(Date_9_4_1 &dd, int y, int m, int d){
    if(d <= 0 || m <= 0 || y <= 0){
        error("Attempting to initialize date with negative values");
    }

    if(d > 31 || m > 12){
        error("Attempting to initialize date with too large month or day values");
    }

    // Initialize date
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day(Date_9_4_1 &dd, int n){

    if(n < 0){
        error("cannot add negative days");
    }

    // Record the number of days to add
    int tot_d, add_m, add_y;

    // Increment months and years
    tot_d = n + dd.d;               // total days = existing + new days
    add_m = (tot_d / 31);           // total mon = existing + new months
    add_y = (add_m / 12);           // additional years = new years

    // Update values
    dd.d = tot_d - (add_m * 31);    // new day = total days - days of months added
    dd.m = (dd.m + add_m) - (add_y * 12);    // new mon = total months - months of years added
    dd.y += add_y;                  // new year = years added
}

// Version 9.4.2 -------------------------------------------------------

Date_9_4_2::Date_9_4_2(int y, int m, int d) {
    if(d <= 0 || m <= 0 || y <= 0){
        error("Attempting to initialize date with negative values");
    }

    if(d > 31 || m > 12){
        error("Attempting to initialize date with too large month or day values");
    }

    // Initialize date
    this->y = y;
    this->m = m;
    this->d = d;
}

void Date_9_4_2::add_day(int n) {
    if(n < 0){
        error("cannot add negative days");
    }

    // Record the number of days to add
    int tot_d, add_m, add_y;

    // Increment months and years
    tot_d = n + this->d;               // total days = existing + new days
    add_m = (tot_d / 31);    // total mon = existing + new months
    add_y = (add_m / 12);           // additional years = new years

    // Update values
    this->d = tot_d - (add_m * 31);    // new day = total days - days of months added
    this->m = (add_m + this->m) - (add_y * 12);    // new mon = total months - months of years added
    this->y += add_y;                  // new year = years added
}

// Version 9.4.3 -------------------------------------------------------

Date_9_4_3::Date_9_4_3(int y, int m, int d) {
    if(d <= 0 || m <= 0 || y <= 0){
        error("Attempting to initialize date with negative values");
    }

    if(d > 31 || m > 12){
        error("Attempting to initialize date with too large month or day values");
    }

    // Initialize date
    this->y = y;
    this->m = m;
    this->d = d;
}

void Date_9_4_3::add_day(int n) {
    if(n < 0){
        error("cannot add negative days");
    }

    // Record the number of days to add
    int tot_d, add_m, add_y;

    // Increment months and years
    tot_d = n + this->d;               // total days = existing + new days
    add_m = (tot_d / 31);    // total mon = existing + new months
    add_y = (add_m / 12);           // additional years = new years

    // Update values
    this->d = tot_d - (add_m * 31);    // new day = total days - days of months added
    this->m = (add_m + this->m) - (add_y * 12);    // new mon = total months - months of years added
    this->y += add_y;                  // new year = years added
}

// Version 9.7.1 -------------------------------------------------------

Date_9_7_1::Date_9_7_1(Year y, Month m, int d) {
    if(d <= 0){
        error("Attempting to initialize date with negative values");
    }

    if(d > 31){
        error("Attempting to initialize date with too large month or day values");
    }

    // Initialize date
    this->y = y;
    this->m = m;
    this->d = d;
}

Date_9_7_1::Date_9_7_1() {
    this->y = Year{2000};
    this->m = Month::jan;
    this->d = 1;
}

void Date_9_7_1::add_day(int n){
    if(n < 0){
        error("cannot add negative days");
    }

    // Record the number of days to add
    int tot_d, add_m, add_y;

    // Increment months and years
    tot_d = n + this->d;                        // total days = existing + new days
    add_m = (tot_d / 31);       // total mon = existing + new months
    add_y = (add_m / 12);                       // additional years = new years

    // Update values
    this->d = tot_d - (add_m * 31);             // new day = total days - days of months added
    this->m = Month((add_m + (int) this->m)- (add_y * 12));      // new mon = total months - months of years added
    this->y = Year(this->y.year() + add_y);     // new year = years added
}

// Version 9.7.4 -------------------------------------------------------

int Date_9_7_4::day() const {return this->d;}
Month Date_9_7_4::month() const {return this->m;}
int Date_9_7_4::year() const {return this->y;}

Date_9_7_4::Date_9_7_4(int y, Month m, int d) {
    if(d <= 0){
        error("Attempting to initialize date with negative values");
    }

    if(d > 31){
        error("Attempting to initialize date with too large month or day values");
    }

    // Initialize date
    this->y = y;
    this->m = m;
    this->d = d;
}

Date_9_7_4::Date_9_7_4() {
    this->y = 2000;
    this->m = Month::jan;
    this->d = 1;
}

void Date_9_7_4::add_year(int n) {
    this->y += n;
}

void Date_9_7_4::add_month(int n) {
    int tot_m, add_y;

    tot_m = (int) this->month() + n;
    add_y = tot_m / 12;

    // Update values
    this->m = Month(tot_m - (add_y * 12));

    // Add year
    this->add_year(add_y);
}

void Date_9_7_4::add_day(int n) {
    if(n < 0){
        error("cannot add negative days");
    }

    // Record the number of days to add
    int tot_d, add_m, add_y;

    // Increment months and years
    tot_d = n + this->d;                        // total days = existing + new days
    add_m = (tot_d / 31);       // total mon = existing + new months
    add_y = add_m / 12;                       // additional years = new years

    // Update values
    this->d = tot_d - (add_m * 31);             // new day = total days - days of months added

    // Add months:
    this->add_month(add_m - (add_y * 12));      // new mon = total months - months of years added

    // Add years
    this->add_year(add_y);     // new year = years added
}

// ostream operator << ------------------------------------------------

ostream & operator<<(::ostream &stream, const Date_9_4_1 &dd){
    stream << dd.d << "/" << dd.m << "/" << dd.y;
}

ostream & operator<<(::ostream &stream, const Date_9_4_2 &dd){
    stream << dd.d << "/" << dd.m << "/" << dd.y;
}

ostream & operator<<(::ostream &stream, const Date_9_4_3 &dd){
    stream << dd.d << "/" << dd.m << "/" << dd.y;
}

ostream & operator<< (ostream &stream, const Month &m){
    switch (m) {
        case Month::jan : stream << "January"; break;
        case Month::feb : stream << "February"; break;
        case Month::mar : stream << "March"; break;
        case Month::apr : stream << "April"; break;
        case Month::may : stream << "May"; break;
        case Month::jun : stream << "June"; break;
        case Month::july : stream << "July"; break;
        case Month::aug : stream << "August"; break;
        case Month::sep : stream << "September"; break;
        case Month::oct : stream << "October"; break;
        case Month::nov : stream << "November"; break;
        case Month::dec : stream << "December"; break;

    }
}

ostream & operator<< (::ostream &stream, const Year &y){
    stream << y.year();
}

ostream& operator<<(::ostream &stream, const Date_9_7_1 &dd) {
    stream << dd.d << "/" << dd.m << "/" << dd.y;
}

ostream& operator<<(::ostream &stream, const Date_9_7_4 &dd) {
    stream << dd.d << "/" << dd.m << "/" << dd.y;
}
