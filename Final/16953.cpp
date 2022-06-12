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

int a, b;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a >> b;
	queue<pair<long long, int>> q;
	q.push({ a, 1 });
	while (true) {
		if (q.empty()) {
			cout << -1;
			break;
		}
		pair<long long, int> tmp = q.front();
		q.pop();
		if (tmp.first == (long long)b) {
			cout << tmp.second;
			break;
		}
		if (tmp.first * 2 <= (long long)b) {
			q.push({ tmp.first * 2, tmp.second + 1 });
		}
		if (stoll(to_string(tmp.first) + "1") <= (long long)b) {
			q.push({ stoi(to_string(tmp.first) + "1"), tmp.second + 1 });
		}
	}
	return 0;
}
