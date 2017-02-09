// -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
#include <cctype> // isdigit, isalpha, ...
#include <iostream>
#include <string>

using namespace std;

bool is_mirror(const string& str, const char** reverse) {
    auto alpha = reverse[0], nums = reverse[1];
    const auto sz = str.size();
    const auto mid = sz / 2;

    for(auto i = 0; i < mid; ++i) {
        if(isalpha(str[i]) && str[str.size() - 1 - i] != alpha[str[i] - 'A'])
            return false;
        else if(isdigit(str[i]) && str[str.size() - 1 - i] != nums[str[i] - '0'])
            return false;
    }
    // also check for the middle of the string
    if(sz && (sz & 1)) {
        if(isalpha(str[mid]) && str[mid] != alpha[str[mid] - 'A'])
            return false;
        else if(isdigit(str[mid]) && str[mid] != nums[str[mid] - '0'])
            return false;
    }
    return true;
}

bool is_palindrome(const string& str) {
    const auto min = str.size() / 2;
    // cout << "min size: " << min << endl;

    for(auto i = 0; i != min; ++i) {
        if(str[i] != str[str.size() - 1 - i])
            return false;
    }
    return true;
}

int main() {
    // The digit 0 is not the valid charater
    const char* reverse[2] = { "A   3  HIL JM O   2TUVWXY5", " 1SE Z  8 " };
    string str;
    while(getline(std::cin, str)) {
        bool p = is_palindrome(str);
        bool m = is_mirror(str, reverse);
        if(!p && !m) {
            cout << str << " -- is not a palindrome." << endl;
        } else if(!p && m) {
            cout << str << " -- is a mirrored string." << endl;
        } else if(p && !m) {
            cout << str << " -- is a regular palindrome." << endl;
        } else {
            cout << str << " -- is a mirrored palindrome." << endl;
        }
        cout << endl;
    }
    return 0;
}
