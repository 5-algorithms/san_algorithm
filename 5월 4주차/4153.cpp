#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(void)
{
    while (true) {
        string input;
        int x, y, z;
        getline(cin, input);
        if (input == "0 0 0") {
            break;
        }
        stringstream ss(input);
        ss >> x;
        ss >> y;
        ss >> z;
        if (x * x + y * y == z * z || x * x + z * z == y * y || y * y + z * z == x * x) {
            printf("%s\n", "right");
        }
        else {
            printf("%s\n", "wrong");
        }
    }
    return 0;
}