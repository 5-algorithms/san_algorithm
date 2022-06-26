#include <iostream>
#include <string>
using namespace std;

int graph[11][10];
int cnt;
int seq;
int r, c;
bool findSeq;
string str;
string ans;
void makeGraph(int num) {
	for (int i = 1; i <= 9; i++) {
		graph[1][i] = 1;
		cnt++;
	}
	for (int i = 1; i <= 9; i++) {
		graph[2][i] = i;
		cnt += i;
		if (!findSeq&&num <= cnt) {
			findSeq = true;
			r = 2;
			c = i;
			seq = cnt - num;
		}
	}
	for (int i = 3; i <= 10; i++) {
		for (int j = i - 1; j <= 9; j++) {
			for (int k = 1; k < j; k++) {
				graph[i][j] += graph[i - 1][k];
				cnt += graph[i - 1][k];
			}
			if (!findSeq&&num <= cnt) {
				findSeq = true;
				r = i;
				c = j;
				seq = cnt - num;
				//seq = num - (cnt - graph[i][j]);
			}
		}
	}
}

void combination() {
	if (str.length() == r) {
		if (seq-- == 0) {
			ans = str;
		}
		return;
	}
	for (int i = c; i >= 0; i--) {
		if (str[str.length() - 1] - '0' <= i)
			continue;
		str += (i + '0');
		combination();
		str.pop_back();
	}
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int num;
	
	cin >> num;

	if (num <= 10 ) {
		cout << num;
	}
	else if (num > cnt) {
		cout << -1;
	}
	else{
		makeGraph(num);

		str += c + '0';
		combination();

		cout << ans << '\n';
	}


	return 0;
}
 

