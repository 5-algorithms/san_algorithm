#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <stack>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, sum = 0;
    cin >> x;
    stack<int> stack;
    for (int i = 0; i < x; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 0) {
            if (!stack.empty()) {
                stack.pop();
            }
        }
        else {
            stack.push(tmp);
        }
    }
    while (!stack.empty()) {
        sum += stack.top();
        stack.pop();
    }
    printf("%d", sum);
    return 0;
}
