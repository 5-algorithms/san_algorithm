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
    scanf("%d", &x);
    vector<int> list = {};
    int test = 1;
    int tmp = 1;
    while (test <= 1100000000) {
        list.push_back(test);
        test += tmp * 6;
        tmp += 1;
    }
    for (int i = 0; i < list.size(); i++) {
        if (x <= list[i]) {
            printf("%d", i + 1);
            break;
        }
    }
    return 0;
}