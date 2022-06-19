#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
    int a;
    scanf("%d\n", &a);
    for (int i = 0; i < a; i++) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int r;
        string s;
        ss >> r;
        ss >> s;
        for (int j = 0; j < s.length(); j++) {
            for (int k = 0; k < r; k++) {
                printf("%c", s[j]);
            }
        }
        printf("\n");
     }
    return 0;
}