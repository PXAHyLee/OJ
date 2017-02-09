// -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
#include <iostream>
#include <string> // std::getline

using namespace std;

// R"d(")d" ... C++11 raw string literal

int main() {
    string line;
    auto flip = 0;
    string quotes[2] = { string("``"), string("''") };
    while(std::getline(std::cin, line)) {
        for(const auto& i : line) {
            if(i == '\"') {
                cout << quotes[flip];
                flip = 1 - flip;
            } else {
                cout << i;
            }
        }
        cout << endl;
    }
    return 0;
}
