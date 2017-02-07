// -lm -lcrypt -O2 -std=c++11 -pipe -DONLINE_JUDGE
#include <iostream>
#include <string>

using namespace std;

int main()
{
        const string s("`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./");
        string line;
        while(std::getline(std::cin, line)) {
                for(const auto& i : line) {
                        auto rst = s.find(i, 0);
                        if(rst != string::npos)
                                cout << s[rst - 1];
                        else
                                cout << i;
                }
                cout << endl;
        }
        return 0;
}
