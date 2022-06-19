#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

int m, n;
vector<vector<int>> mydata;
vector<vector<bool>> visited;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<pair<int, int>, int>> q;

int bfs() {
    int x = 0, y = 0;
    visited[x][y] = true;
    q.push({ { x, y }, 1 });
    while (true) {
        x = q.front().first.first;
        y = q.front().first.second;
        int k = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (x + dx[i] < 0 || y + dy[i] < 0 || x + dx[i] >= m || y + dy[i] >= n) {
                continue;
            }
            if (mydata[x + dx[i]][y + dy[i]] == 1 && !visited[x + dx[i]][y + dy[i]]) {
                if (x + dx[i] == m - 1 && y + dy[i] == n - 1) {
                    return k + 1;
                }
                visited[x + dx[i]][y + dy[i]] = true; 
                q.push({ { x + dx[i], y + dy[i] }, k + 1 });
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string tmp;
    cin >> m >> n;
    mydata.assign(m, vector<int>(n));
    visited.assign(m, vector<bool>(n));
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        for (int j = 0; j < n; j++) {
            mydata[i][j] = tmp[j] - '0';
        }
    }
    cout << bfs();
    return 0;
}