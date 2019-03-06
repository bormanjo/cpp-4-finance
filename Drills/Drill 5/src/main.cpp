#include "std_lib_facilities.h"

int main()
{
    try{
        // 1

        cout << "1 Success!\n";

        // 2

        cout << "2 Success!\n";

        // 3

        cout << "3 Success!" << "\n";

        // 4

        cout << "4 Success!" << '\n';

        // 5

        int res = 7;
        vector<int> v(10);

        v[5] = res;

        cout << "5 Success!\n";

        // 6

        vector<int> v1(10);
        v1[5] = 7;

        if (v1[5] == 7) cout << "6 Success!\n";

        // 7

        if(true) cout << "7 Success!\n"; else cout << "Fail!\n";

        // 8

        bool c = false;

        if(!c) cout << "8 Success!\n"; else cout << "Fail!\n";

        // 9

        string s = "ape";

        c = "fool" > s;

        if(c) cout << "9 Success!\n";

        // 10

        if (s != "fool") cout << "10 Success!\n";

        // 11

        if (s != "fool") cout << "11 Success!\n";

        // 12

        if (s != "fool") cout << "12 Success!\n";

        // 13

        vector<char> v2(5);

        for(int i = 0; i<v2.size(); ++i);

        cout << "13 Success!\n";

        // 14

        for(int i = 0; i<=v2.size(); ++i);

        cout << "14 Success!\n";

        // 15

        string s1 = "15 Success!\n";

        for(int i = 0; i<12; ++i) cout << s1[i];

        // 16

        if(true) cout << "16 Success!\n"; else cout << "Fail!\n";

        // 17

        int x = 2000;
        char c2 = x;

        if(c2 != 2000) cout << "17 Success!\n";

        // 18

        string s2 = "18 Success!\n";

        for(int i = 0; i < 12; ++i) cout << s2[i];

        // 19

        vector<char> v3(5);

        for(int i = 0; i <= v3.size(); ++i); cout << "19 Success!\n";

        // 20

        int i = 0;
        int j = 9;

        while (i < 10){
            ++j;
            i++;
        }

        if(j > i) cout << "20 Success!\n";

        // 21

        int x2 = 2;
        float d = 5/x2 ;

        if(floor(d) == floor(2.5)) cout << "21 Success!\n";

        // 22

        char s3[] = "22 Success!\n";

        for(int i = 0; i <= 12; ++i) cout << s3[i];

        // 23

        int i2 = 0;
        int j2 = 78;

        while(i < 10){
            ++j;
            ++i;
        }

        if (j > i) cout << "23 Success!\n";

        // 24

        int x3 = 4;
        double d2 = 5/(x3-2);

        if(floor(d2) == floor((x3 - 2)+0.5)) cout << "24 Success!\n";

        // 25

        cout << "25 Success!\n";

        keep_window_open();
        return 0;
    }
    catch (exception &e){
        cerr << "error: " << e.what() << endl;
        keep_window_open();
        return 1;
    }
    catch (...) {
        cerr << "Oops: unknown exception!" << endl;
        keep_window_open();
        return 2;
    }
}
