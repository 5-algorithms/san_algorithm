#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int prefix(string s) {
    int answer = s.length() - 1;
    for (int predict_answer = s.length() - 1; predict_answer >= 0; predict_answer--) {
        bool correct = true;
        for (int index = 0; index < predict_answer; index++) {
            if (s[index] != s[s.length() - predict_answer + index]) {
                correct = false;
                break;
            }
        }
        answer = predict_answer;
        if (correct) {
            break;
        }
    }
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int n, len, tmp = 0, answer = 0;
    string s;
    cin >> n >> len >> s;

    while (tmp < len - 2 * n - 1) {
        bool is_answer = true;
        for (int i = 0; i < 2 * n + 1; i++) {
            if (i % 2 == 0) {
                if (s[tmp + i] != 'I') {
                    is_answer = false;
                    tmp += (i + 1);
                    break;
                }
            }
            else {
                if (s[tmp + i] != 'O') {
                    tmp += i;
                    is_answer = false;
                    break;
                }
            }
        }
        if (is_answer) {
            answer += 1;
            tmp += 2;
            while (true) {
                if (tmp + 2 * n >= len) {
                    break;
                }
                if (s[tmp + 2 * n - 1] == 'O' && s[tmp + 2 * n] == 'I') {
                    answer += 1;
                    tmp += 2;
                }
                else {
                    tmp += 2 * n - 1;
                    break;
                }
            }
        }
    }
    cout << answer;
    return 0;
}