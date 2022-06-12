#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

map<long long, long long> mydata;

long long func(long long x) {
    if (x == 0) {
        return 0;
    }
    if (x == 1) {
        return 1;
    }
    if (x == 2) {
        return 1;
    }
    if (x % 2 == 0) {
        long long a, b, c;
        if (mydata[x / 2] == 0) {
            a = func(x / 2) % 1000000007;
            mydata[x / 2] = a;
        }
        else {
            a = mydata[x / 2];
        }
        if (mydata[x / 2 - 1] == 0) {
            b = func(x / 2 - 1) % 1000000007;
            mydata[x / 2 - 1] = b;
        }
        else {
            b = mydata[x / 2 - 1];
        }
        if (mydata[x / 2 + 1] == 0) {
            c = func(x / 2 + 1) % 1000000007;
            mydata[x / 2 + 1] = c;
        }
        else {
            c = mydata[x / 2 + 1];
        }
        return (a * (b + c)) % 1000000007;
    }
    else {
        long long a, b;
        if (mydata[(x + 1) / 2] == 0) {
            a = func((x + 1) / 2) % 1000000007;
            mydata[(x + 1) / 2] = a;
        }
        else {
            a = mydata[(x + 1) / 2];
        }
        if (mydata[(x - 1) / 2] == 0) {
            b = func((x - 1) / 2) % 1000000007;
            mydata[(x - 1) / 2] = b;
        }
        else {
            b = mydata[(x - 1) / 2];
        }
        return ((a * a) % 1000000007 + (b * b) % 1000000007) % 1000000007;
    }
}

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long a;
    cin >> a;
    cout << func(a);
    return 0;
}
