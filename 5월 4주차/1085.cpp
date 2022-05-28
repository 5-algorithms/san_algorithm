#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main(void)
{
    int current_x, current_y, weight, height;
    cin >> current_x >> current_y >> weight >> height;
    int answer = min(weight - current_x, height - current_y);
    answer = min(current_x, answer);
    answer = min(current_y, answer);
    printf("%d", answer);
    return 0;
}