// -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
#include <cassert>
#include <cmath>

#include <iostream>
#include <tuple>
#include <utility>

using namespace std;

// int: the smallest number `n' that (1+2+...+i) >= k (n > 0)
// int: sum of 1+2+...+n
using Param = tuple<int, int>;

Param find_lower_bound(int k) {
    if(k == 0)
        return make_tuple(1, 1);

    auto n = 0;
    auto acc = 0;
    while(acc < k) {
        acc += n;
        ++n;
    }
    return make_tuple(n - 1, acc);
}

int main() {
    int t = 0, k = 0;
    cin >> t;
    // cout << t << endl;

    while(t) {
        cin >> k;
        k = abs(k);
        // cout << k << endl;

        auto p = std::move(find_lower_bound(k));
        auto& n = get<0>(p);
        auto& sum = get<1>(p);
        if(k == sum)
            cout << n << endl;
        else {
            auto diff = sum - k;
            while(diff & 1) {
                ++n;
                sum += n;
                diff = sum - k;
            }
            cout << n << endl;
        }
        if(t - 1)
            cout << endl;
        --t;
    }
    return 0;
}
