#include "std_lib_facilities.h"
#include <algorithm>

const bool debug = false;

bool isPalindrome(string s)
{
    // Make string lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Loop through each character
    for (unsigned int i = 0; i < (s.length() / 2) + 1; ++i) {
        if (debug) cout << s[i] << " v " << s[s.length() - i - 1] << endl;
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }

    return true;
}

int main()
{
    cout << "Task 1:" << '\n';

    cout << "This should return true: " << (isPalindrome("Rats live on no evil star") ? "true" : "false") << '\n';

    cout << "This should return false: " << (isPalindrome("To be or not to be") ? "true" : "false") << '\n';

    cout << "Task 2:" << '\n';

    // True palindromes
    cout << "This should return true: " << (isPalindrome("catac") ? "true" : "false") << '\n';
    cout << "This should return true: " << (isPalindrome("palllllllllap") ? "true" : "false") << '\n';
    cout << "This should return true: " << (isPalindrome("dealaed") ? "true" : "false") << '\n';

    // False palindromes
    cout << "This should return false: " << (isPalindrome("This is not a palin drome") ? "true" : "false") << '\n';
    cout << "This should return false: " << (isPalindrome("This is definitely not a palin drome") ? "true" : "false") << '\n';
    cout << "This should return false: " << (isPalindrome("This is most certainly not a palin drome") ? "true" : "false") << '\n';

    keep_window_open();

    return 0;
}
