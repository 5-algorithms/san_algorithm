#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

struct compare {
	bool operator()(pair<int, int> x, pair<int, int> y) {
		return x.second > y.second;
	}
};

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// 정보 입력
	int a, b, num;
	cin >> a >> b >> num;
	num -= 1;
	vector<map<int, int>> weight(a, map<int, int>());
	vector<bool> visited(a);
	vector<int> answer(a, 1000000);
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> q;
	int tmp1, tmp2, tmp3;
	for (int i = 0; i < b; i++) {
		cin >> tmp1 >> tmp2 >> tmp3;
		// 두 정점 사이에 여러 개의 간선이 존재할 수 있으므로, 더 작은 값이 나올때마다 갱신해야 한다.
		// 갱신이 용이하도록 map을 사용한다.
		if (weight[tmp1 - 1].find(tmp2 - 1) == weight[tmp1 - 1].end() || weight[tmp1 - 1][tmp2 - 1] > tmp3) {
			weight[tmp1 - 1][tmp2 - 1] = tmp3;
		}
	}

	answer[num] = 0;
	q.push({ num, 0 });
	while (true) {
		while (!q.empty() && q.top().second > answer[q.top().first]) {
			q.pop();
		}
		if (q.empty())	break;
		pair<int, int> tmp = q.top();
		q.pop();
		visited[tmp.first] = true;
		for (auto i = weight[tmp.first].begin(); i != weight[tmp.first].end(); i++) {
			if (visited[i->first])	continue;
			if (answer[i->first] > answer[tmp.first] + i->second) {
				answer[i->first] = answer[tmp.first] + i->second;
				q.push({ i->first, answer[i->first] });
			}
		}
	}
	for (int i = 0; i < a; i++) {
		if (answer[i] == 1000000) {
			cout << "INF" << "\n";
		}
		else {
			cout << answer[i] << "\n";
		}
	}
	return 0;
}
