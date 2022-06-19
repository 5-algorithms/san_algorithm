#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

int a, b, c, answer;
vector<pair<int, int>> air;
vector<vector<int>> info;
vector<vector<int>> info2;

void phase1() {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (info[i][j] > 0) {
                vector<pair<int, int>> togo;
                if (i - 1 >= 0 && info[i - 1][j] != -1) {
                    togo.push_back({ i - 1, j });
                }
                if (j + 1 < b) {
                    togo.push_back({ i, j + 1 });
                }
                if (i + 1 < a && info[i + 1][j] != -1) {
                    togo.push_back({ i + 1, j });
                }
                if (j - 1 >= 0 && info[i][j - 1] != -1) {
                    togo.push_back({ i, j - 1 });
                }
                info2[i][j] += info[i][j] - togo.size() * (int)(info[i][j] / 5);
                for (int k = 0; k < togo.size(); k++) {
                    info2[togo[k].first][togo[k].second] += (int)(info[i][j] / 5);
                }
            }
        }
    }
    info2[air[0].first][air[0].second] = -1;
    info2[air[1].first][air[1].second] = -1;
}

void phase2() {
    info2[air[0].first][1] = 0;
    info2[air[1].first][1] = 0;
    for (int i = 2; i < b; i++) {
        info2[air[0].first][i] = info[air[0].first][i - 1];
        info2[air[1].first][i] = info[air[1].first][i - 1];
    }
    for (int i = air[0].first - 1; i >= 0; i--) {
        info2[i][b - 1] = info[i + 1][b - 1];
        info2[i + 1][0] = info[i][0];
    }
    for (int i = air[1].first + 1; i < a; i++) {
        info2[i][b - 1] = info[i - 1][b - 1];
        info2[i - 1][0] = info[i][0];
    }
    for (int i = 0; i < b - 1; i++) {
        info2[0][i] = info[0][i + 1];
        info2[a - 1][i] = info[a - 1][i + 1];
    }
    info2[air[0].first][air[0].second] = -1;
    info2[air[1].first][air[1].second] = -1;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b >> c;
    info.assign(a, vector<int>(b));
    info2.assign(a, vector<int>(b));
    int tmp;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> tmp;
            if (tmp == -1) {
                air.push_back({ i, j });
                air.push_back({ i + 1, j });
            }
            info[i][j] = tmp;
        }
    }
    for (int i = 0; i < c; i++) {
        phase1();
        info = info2;
        phase2();
        info = info2;
        info2.assign(a, vector<int>(b, 0));
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            answer += info[i][j];
        }
    }
    cout << answer + 2; 
    return 0;
}