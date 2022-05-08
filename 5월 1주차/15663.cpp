#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int x, y, tmp;
vector<int> mydata;
vector<vector<int>> mymap;
vector<bool> visited;
set<vector<int>> answer;

void dfs(int k, vector<int> list) {
	if (list.size() == y - 1) {
		vector<int> tmp = list;
		tmp.push_back(mydata[k]);
		answer.insert(tmp);
		return;
	}
	list.push_back(mydata[k]);
	for (int i = 0; i < x; i++) {
		if (mymap[k][i] == 1 && !visited[i]) {
			visited[i] = true;
			dfs(i, list);
			visited[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> x >> y;
	mymap.assign(x, vector<int>(x));
	for (int i = 0; i < x; i++) {
		cin >> tmp;
		mydata.push_back(tmp);
	}
	sort(mydata.begin(), mydata.end());
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			if (i == j)	continue;
			mymap[i][j] = 1;
			mymap[j][i] = 1;
		}
	}
	for (int i = 0; i < x; i++) {
		vector<int> tmp;
		visited.assign(x, false);
		visited[i] = true;
		dfs(i, tmp);
	}
	for (auto i = answer.begin(); i != answer.end(); i++) {
		for (int j = 0; j < y; j++) {
			cout << (*i)[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}