#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

int m;
vector<vector<int>> mydata;
vector<vector<bool>> visited;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
stack <pair<int, int>> s;
vector<int> answer;

pair<int, int> all_clear() {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            if (mydata[i][j] == 1 && !visited[i][j]) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

void dfs(int a, int b) {
    int x = a, y = b, count = 0;
    visited[x][y] = true;
    s.push({ x, y });
    count += 1;
    while (!s.empty()) {
        x = s.top().first;
        y = s.top().second;
        s.pop();
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= m || y + dy[i] >= m) {
                continue;
            }
            if (mydata[x + dx[i]][y + dy[i]] == 1 && !visited[x + dx[i]][y + dy[i]]) {
                visited[x + dx[i]][y + dy[i]] = true; 
                s.push({ x + dx[i], y + dy[i] });
                count += 1;
            }
        }
    }
    answer.push_back(count);
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string tmp;
    cin >> m;
    mydata.assign(m, vector<int>(m));
    visited.assign(m, vector<bool>(m));
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            mydata[i][j] = tmp[j] - '0';
        }
    }
    while (true) {
        pair<int, int> p = all_clear();
        if (p.first == -1 && p.second == -1) {
            break;
        }
        else {
            dfs(p.first, p.second);
        }
    }
    sort(answer.begin(), answer.end());
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}