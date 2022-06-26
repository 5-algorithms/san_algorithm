#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

class xyz {
public:
	int x;
	int y;
	int z;

	xyz(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

vector<vector<vector<int>>> mydata;
vector<vector<vector<bool>>> visited;
int x, y, z;
int dx[6] = { 0, 0, 0, 0, 1, -1 };
int dy[6] = { 0, 0, 1, -1, 0, 0 };
int dz[6] = { -1, 1, 0, 0, 0, 0 };

queue<xyz> find_not_visited_but_good() {
	queue<xyz> tmp;
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				if (!visited[i][j][k] && mydata[i][j][k] == 1) {
					tmp.push(xyz(k, j, i));
				}
			}
		}
	}
	return tmp;
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int tmp0, num_place = 0, num_good_tomato = 0, num_bad_tomato = 0, num_empty_space = 0;
	cin >> x >> y >> z;
	mydata.assign(z, vector<vector<int>>(y, vector<int>(x)));
	visited.assign(z, vector<vector<bool>>(y, vector<bool>(x)));
	for (int i = 0; i < z; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				cin >> tmp0;
				if (tmp0 == 1) {
					num_good_tomato += 1;
				}
				else if (tmp0 == -1) {
					num_empty_space += 1;
				}
				else {
					num_bad_tomato += 1;
				}
				mydata[i][j][k] = tmp0;
			}
		}
	}
	int answer = 0;
	bool wrong = false;
	queue<xyz> tmp = find_not_visited_but_good();
	while (num_bad_tomato != 0) {
		int current_bad_tomato = num_bad_tomato;
		int size = tmp.size();
		for (int i = 0; i < size; i++) {
			xyz tmp2 = tmp.front();
			tmp.pop();
			visited[tmp2.z][tmp2.y][tmp2.x] = true;
			for (int j = 0; j < 6; j++) {
				int tmpx = tmp2.x + dx[j];
				int tmpy = tmp2.y + dy[j];
				int tmpz = tmp2.z + dz[j];
				if (tmpx < 0 || tmpx >= x || tmpy < 0 || tmpy >= y || tmpz < 0 || tmpz >= z) {
					continue;
				}
				if (mydata[tmpz][tmpy][tmpx] == 0) {
					num_bad_tomato -= 1;
					mydata[tmpz][tmpy][tmpx] = 1;
					tmp.push(xyz(tmpx, tmpy, tmpz));
				}
			}
		}
		answer += 1;
		if (current_bad_tomato == num_bad_tomato) {
			wrong = true;
			break;
		}
	}
	if (wrong) {
		cout << -1;
	}
	else {
		cout << answer;
	}
	return 0;
}
