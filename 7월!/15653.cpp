#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

int a, b;
vector<vector<bool>> visited;
vector<vector<int>> mydata;


void dfs(int num, vector<int> list) {
	list.push_back(num + 1);
	if (list.size() == b) {
		for (int i = 0; i < b; i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < a; i++) {
		if (mydata[num][i] == 1) {
			dfs(i, list);
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	vector<int> x;
	visited.assign(a, vector<bool>(a));
	mydata.assign(a, vector<int>(a));
	for (int i = 0; i < a; i++) {
		for (int j = i; j < a; j++) {
			mydata[i][j] = 1;
		}
	}
	for (int i = 0; i < a; i++) {
		dfs(i, x);
	}
	return 0;
}