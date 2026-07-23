//Mr. Laaksonen was mean by designing a testcase that made hash sets get
//a ton of collisions. Then, the optimal way is by sorting and counting.

#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;
    int val;
    vector<int> values;

    for(int k = 0; k < n; k++){
        cin >> val;
        values.push_back(val);
    }

    val = 1;
    sort(values.begin(), values.end());
    for(int k = 1; k < values.size(); k++){
        if(values[k] != values[k - 1]) val++;
    }

    cout << val;
}