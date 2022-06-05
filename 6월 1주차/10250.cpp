#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(void)
{
    int x;
    string input;
    scanf("%d", &x);
    for (int i = 0; i < x; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int x = c % a;
        int y;
        if (c % a == 0) {
            x = a;
            y = c / a;
        }
        else {
            y = c / a + 1;
        }
        if (y < 10) {
            cout << to_string(x) + "0" + to_string(y) << endl;
        }
        else {
            cout << to_string(x) + to_string(y) << endl;
        }
    }
    return 0;
}