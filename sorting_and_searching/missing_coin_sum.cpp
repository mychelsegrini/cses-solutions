#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> values(n);
    long long val;

    for(int k = 0; k < n; k++){
        cin >> val;
        values[k] = val;
    }

    sort(values.begin(), values.end());

    val = 0;

    for(int& i : values){
        if(i > val + 1){
            cout << val + 1;
            return 0;
        }
        val += i;
    }

    cout << val + 1;
}