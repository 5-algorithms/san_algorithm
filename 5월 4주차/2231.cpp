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
    int answer = 1;
    while (true) {
        int tmp = answer;
        for (int i = 0; i < to_string(answer).length(); i++) {
            tmp += to_string(answer)[i] - 48;
        }
        if (tmp == x or answer == x) {
            break;
        }
        answer += 1;
    }
    if (answer == x) {
        printf("%d", 0);
    }
    else {
        printf("%d", answer);
    }
    return 0;
}