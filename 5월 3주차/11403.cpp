#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, tmp;
	cin >> x;
	vector<vector<int>> data(x, vector<int>(x));
	vector<vector<int>> answer(x, vector<int>(x));
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			cin >> tmp;
			if (tmp == 1) {
				data[i][j] = tmp;
			}
		}
	}
	for (int i = 0; i < x; i++) {
		vector<bool> visited(x);
		stack<int> s;
		s.push(i);
		while (!s.empty()) {
			tmp = s.top();
			s.pop();
			for (int j = 0; j < x; j++) {
				if (data[tmp][j] == 1 && !visited[j]) {
					s.push(j);
					visited[j] = true;
					answer[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}