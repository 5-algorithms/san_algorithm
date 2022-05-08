#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

int a, b;
vector<bool> visited;
vector<vector<int>> mydata;
vector<int> input;

void dfs(int num, vector<int> list) {
	visited[num] = true;
	list.push_back(num);
	if (list.size() == b) {
		for (int i = 0; i < b; i++) {
			cout << input[list[i]] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < a; i++) {
		if (mydata[num][i] == 1 && !visited[i]) {
			dfs(i, list);
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	vector<int> x;
	mydata.assign(a, vector<int>(a));
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			if (i == j)	continue;
			mydata[i][j] = 1;
		}
	}
	for (int i = 0; i < a; i++) {
		visited.assign(a, false);
		dfs(i, x);
	}
	return 0;
}