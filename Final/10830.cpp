#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<vector<int>>> container;
vector<vector<int>> answer, answer2;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, tmp;
    long long b;
    cin >> a >> b;
    container.assign((int)log2(1000000000001), vector<vector<int>>(a, vector<int>(a)));
    answer.assign(a, vector<int>(a));
    answer2.assign(a, vector<int>(a));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cin >> tmp;
            container[0][i][j] = tmp % 1000;
        }
    }
    for (int i = 1; i < (int)log2(1000000000001); i++) {
        for (int j = 0; j < a; j++) {
            for (int k = 0; k < a; k++) {
                tmp = 0;
                for (int t = 0; t < a; t++) {
                    tmp += container[i - 1][j][t] * container[i - 1][t][k];
                    tmp %= 1000;
                }
                container[i][j][k] = tmp;
            }
        }
    }
    tmp = (int)log2(b);
    answer = container[tmp];
    b -= pow(2, tmp);
    while (b > 0) {
        tmp = (int)log2(b);
        b -= pow(2, tmp);
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < a; j++) {
                int tmp2 = 0;
                for (int t = 0; t < a; t++) {
                    tmp2 += answer[i][t] * container[tmp][t][j];
                    tmp2 %= 1000;
                }
                answer2[i][j] = tmp2;
            }
        }
        answer = answer2;
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
