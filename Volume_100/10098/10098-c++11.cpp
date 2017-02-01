// -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

static constexpr inline bool is_last_line(int n)
{
        return n == 1;
}

static inline void generate_sorted_permutation(string& str)
{
        sort(str.begin(), str.end());
        do {
                cout << str << endl;
        } while(next_permutation(str.begin(), str.end()));
        cout << endl;
}

int main()
{
        int string_number {};
        cin >> string_number;

        while(string_number) {
                string cur;
                cin >> cur;
                generate_sorted_permutation(cur);
                string_number--;
        }
        return 0;
}
