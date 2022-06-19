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

int n, m;
vector<pair<int, int>> house;
vector<pair<pair<int, int>, bool>> chicken;
vector<pair<int, int>> select_chicken;
int answer = 987654321;

void func(int x, int t) {
    if (x == m) {
        int sum = 0;
        for (int i = 0; i < house.size(); i++) {
            int my_min = 987654321;
            for (int j = 0; j < select_chicken.size(); j++) {
                my_min = min(my_min, abs(select_chicken[j].first - house[i].first) + abs(select_chicken[j].second - house[i].second));
            }
            sum += my_min;
        }
        answer = min(answer, sum);
        return;
    }
    for (int i = t; i < chicken.size(); i++) {
        if (!chicken[i].second) {
            chicken[i].second = true;
            select_chicken.push_back({ chicken[i].first.first, chicken[i].first.second });
            func(x + 1, i + 1);
            chicken[i].second = false;
            select_chicken.pop_back();
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                house.push_back({ i, j });
            }
            if (tmp == 2) {
                chicken.push_back({ { i, j }, false });
            }
        }
    }
    func(0, 0);
    cout << answer;
    return 0;
}