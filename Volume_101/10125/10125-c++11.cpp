// -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <utility>

using namespace std;


bool brute_force_search(vector<int>&& lhs, vector<int>&& choices, const int d)
{
        if(lhs.size() == 3)
                return accumulate(lhs.cbegin(), lhs.cend(), 0) == d;
        // Should I check this corner case?
        if(choices.size() + lhs.size() < 3)
                return false;
        for(auto i = choices.cbegin(); i != choices.cend(); ++i) {
                auto v(choices);
                auto new_lhs(lhs);

                v.erase(remove(v.begin(), v.end(), *i), v.end());
                new_lhs.emplace_back(*i);
                if(brute_force_search(move(new_lhs), move(v), d))
                        return true;
        }
        return false;
}

int main()
{
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
                bool found = false;
                for(auto i = s.crbegin(); i != s.crend(); ++i) {
                        auto d = *i;
                        auto v = s;
                        v.erase(remove(v.begin(), v.end(), d), v.end());
                        if(brute_force_search(vector<int>(), move(v), d)) {
                                cout << d << endl;
                                found = true;
                                break;
                        }
                        // for(auto const& i : v)
                        //         cout << i << " ";
                        // cout << endl;
                }
                if(!found)
                        cout << "no solution" << endl;
                cin >> number_of_elements;
        }
        return 0;
}
