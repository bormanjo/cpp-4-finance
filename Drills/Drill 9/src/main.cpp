#include "std_lib_facilities.h"
#include "date.h"

int main()
{
    int yr = 1978, mon = 6, day = 25;

    cout << "Version 9.4.1" << endl;

    Date_9_4_1 today_1, tomorrow_1;

    init_day(today_1, yr, mon, day);

    tomorrow_1 = today_1;
    add_day(tomorrow_1, 1);

    cout << "\tToday: " << today_1 << endl;
    cout << "\tTomorrow: " << tomorrow_1 << endl;


    cout << "Version 9.4.2" << endl;

    Date_9_4_2 today_2(yr, mon, day);
    Date_9_4_2 tomorrow_2 = today_2;
    tomorrow_2.add_day(1);

    cout << "\tToday: " << today_2 << endl;
    cout << "\tTomorrow: " << tomorrow_2 << endl;


    cout << "Version 9.4.3" << endl;

    Date_9_4_3 today_3(yr, mon, day);
    Date_9_4_3 tomorrow_3 = today_3;
    tomorrow_3.add_day(1);

    cout << "\tToday: " << today_3 << endl;
    cout << "\tTomorrow: " << tomorrow_3 << endl;


    cout << "Version 9.7.1" << endl;

    Date_9_7_1 today_4(Year{yr}, Month::jun, day);
    Date_9_7_1 tomorrow_4 = today_4;
    tomorrow_4.add_day(1);

    cout << "\tToday: " << today_4 << endl;
    cout << "\tTomorrow: " << tomorrow_4 << endl;


    cout << "Version 9.7.4" << endl;

    Date_9_7_4 today_5(yr, Month::jun, day);
    Date_9_7_4 tomorrow_5 = today_5;
    tomorrow_5.add_day(1);

    cout << "\tToday: " << today_5 << endl;
    cout << "\tTomorrow: " << tomorrow_5 << endl;


    keep_window_open();
    return 0;
}
