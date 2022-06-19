#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

class node {
public:
	int data;
	int left;
	int right;

	node() {}

	node(char data, char left, char right) {
		this->data = data - 'A';
		if (left == '.') {
			this->left = -1;
		}
		else {
			this->left = left - 'A';
		}
		if (right == '.') {
			this->right = -1;
		}
		else {
			this->right = right - 'A';
		}
	}
};


int a;
char x, y, z;
vector<node> nodedata;

bool check(vector<bool> visited) {
	for (int i = 0; i < visited.size(); i++) {
		if (!visited[i]) {
			return false;
		}
	}
	return true;
}

void first(int index) {
	cout << (char)('A' + nodedata[index].data);
	if (nodedata[index].left != -1) {
		first(nodedata[index].left);
	}
	if (nodedata[index].right != -1) {
		first(nodedata[index].right);
	}
}

void second(int index) {
	if (nodedata[index].left != -1) {
		second(nodedata[index].left);
	}
	cout << (char)('A' + nodedata[index].data);
	if (nodedata[index].right != -1) {
		second(nodedata[index].right);
	}
}

void third(int index) {
	if (nodedata[index].left != -1) {
		third(nodedata[index].left);
	}
	if (nodedata[index].right != -1) {
		third(nodedata[index].right);
	}
	cout << (char)('A' + nodedata[index].data);
}

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> a;
	nodedata.assign(a, node());
	for (int i = 0; i < a; i++) {
		cin >> x >> y >> z;
		nodedata[x - 'A'] = node(x, y, z);
	}
	first(0);
	cout << "\n";
	second(0);
	cout << "\n";
	third(0);
	cout << "\n";
	return 0;
}