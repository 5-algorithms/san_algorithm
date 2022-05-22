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
	int x;
	cin >> x;
	for (int i = 0; i < x; i++) {
		int a, b, c, d, tmp = 0, tmp2 = 0, gcd = 0;
		cin >> a >> b >> c >> d;
		for (int j = min(a, b); j >= 1; j--) {
			if (a % j == 0 && b % j == 0) {
				gcd = j;
				break;
			}
		}
		if (gcd == 1 || (max(c, d) - min(c, d)) % gcd == 0) {
			if (a > b) {
				if (b == d)	d = 0;
				while (true) {
					if ((a * tmp + c) % b == d) {
						break;
					}
					tmp += 1;
				}
				cout << a * tmp + c << "\n";
			}
			else if (a < b) {
				if (a == c)	c = 0;
				while (true) {
					if ((b * tmp + d) % a == c) {
						break;
					}
					tmp += 1;
				}
				cout << b * tmp + d << "\n";
			}
			else {
				if (c == d) {
					cout << c << "\n";
				}
				else {
					cout << -1 << "\n";
				}
			}
		}
		else {
			cout << -1 << "\n";
		}
	}
	return 0;
}