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

vector<int> mydata, mydata2, big, small;

int main(void)
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a, x, y, z;
    cin >> a;
    mydata.assign(3, 0);
    mydata2.assign(3, 0);
    big.assign(3, 0);
    small.assign(3, 0);
    for (int i = 0; i < a; i++) {
        cin >> x >> y >> z;
        if (i == 0) {
            mydata[0] = mydata2[0] = x;
            mydata[1] = mydata2[1] = y;
            mydata[2] = mydata2[2] = z;
            continue;
        }
        big[0] = x + max(mydata[0], mydata[1]);
        big[1] = y + *max_element(mydata.begin(), mydata.end());
        big[2] = z + max(mydata[2], mydata[1]);
        mydata = big;
        small[0] = x + min(mydata2[0], mydata2[1]);
        small[1] = y + *min_element(mydata2.begin(), mydata2.end());
        small[2] = z + min(mydata2[2], mydata2[1]);
        mydata2 = small;
    }
    cout << *max_element(mydata.begin(), mydata.end()) << " ";
    cout << *min_element(mydata2.begin(), mydata2.end());
    return 0;
}
