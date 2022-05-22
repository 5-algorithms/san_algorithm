#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

vector<pair<int, char>> heap;

int main(void)
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, tmp;
	pair<int, char> tmp2;
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> tmp;
		if (tmp == 0) {
			if (heap.empty()) {
				cout << 0 << "\n";
			}
			else {
				if (heap[0].second == '+') {
					cout << heap[0].first << "\n";
				}
				else {
					cout << heap[0].first * -1 << "\n";
				}
				heap[0] = heap[heap.size() - 1];
				heap.erase(heap.begin() + heap.size() - 1);
				int index = 0;
				int child = 2 * index + 1;
				while (child < heap.size()) {
					if (child + 1 < heap.size()) {
						if (heap[child].first > heap[child + 1].first) {
							child += 1;
						}
						else if (heap[child].first == heap[child + 1].first) {
							if (heap[child + 1].second == '-') {
								child += 1;
							}
						}
					}
					if (heap[index].first > heap[child].first) {
						pair<int, char> tmp = heap[index];
						heap[index] = heap[child];
						heap[child] = tmp;
					}
					else if (heap[index].first == heap[child].first) {
						if (heap[index].second == '+') {
							pair<int, char> tmp = heap[index];
							heap[index] = heap[child];
							heap[child] = tmp;
						}
						else {
							break;
						}
					}
					else {
						break;
					}
					index = child;
					child = 2 * index + 1;
				}
			}
		}
		else {
			if (tmp > 0) {
				heap.push_back({ tmp, '+' });
			}
			else {
				heap.push_back({ tmp * -1, '-' });
			}
			int index = heap.size() - 1;
			while (index > 0) {
				if (heap[index].first < heap[(index - 1) / 2].first) {
					tmp2 = heap[index];
					heap[index] = heap[(index - 1) / 2];
					heap[(index - 1) / 2] = tmp2;
					index = (index - 1) / 2;
				}
				else if (heap[index].first == heap[(index - 1) / 2].first && heap[index].second == '-') {
					tmp2 = heap[index];
					heap[index] = heap[(index - 1) / 2];
					heap[(index - 1) / 2] = tmp2;
					index = (index - 1) / 2;
				}
				else {
					break;
				}
			}
		}
	}
	return 0;
}