#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int x, tmp, answer = 0;
    cin >> x;
    vector<int> data;
    string s;
    for (int i = 0; i < x; i++) {
        cin >> tmp;
        data.push_back(tmp);
    }

    for (int i = 0; i < x; i++) {
        bool right = true;
        for (int j = 2; j <= sqrt(data[i]); j++) {
            if (data[i] % j == 0) {
                right = false;
                break;
            }
        }
        if (right && data[i] != 1) {
            answer += 1;
        }
    }
    printf("%d", answer);
    return 0;
}
