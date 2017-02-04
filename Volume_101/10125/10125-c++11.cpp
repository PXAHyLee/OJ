// -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <utility>

using namespace std;

bool brute_force_search(const vector<int>& s, int& ans) {
    for(auto i = s.crbegin(); i != s.crend(); ++i) {
        auto const d = *i;
        for(auto j = s.cbegin(); j != s.cend(); ++j) {
            auto const a = *j;
            if(d == a)
                continue;
            for(auto k = j + 1; k != s.cend(); ++k) {
                auto const b = *k;
                if(d == b)
                    continue;
                for(auto m = k + 1; m != s.cend(); ++m) {
                    auto const c = *m;
                    if(d == c)
                        continue;
                    if(d == a + b + c) {
                        ans = d;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    // 1 <= number_of_elements <= 1000
    int number_of_elements {};
    cin >> number_of_elements;
    while(number_of_elements) {
        vector<int> s;
        s.reserve(number_of_elements);
        while(number_of_elements) {
            int j;
            cin >> j;
            s.push_back(j);
            --number_of_elements;
        }
        sort(s.begin(), s.end());
        int d;
        if(brute_force_search(s, d))
            cout << d << endl;
        else
            cout << "no solution" << endl;
        cin >> number_of_elements;
    }
    return 0;
}
