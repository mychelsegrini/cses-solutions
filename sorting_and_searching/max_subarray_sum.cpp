#include <iostream>
using namespace std;

int main(){
    int n;
    long long val;
    cin >> n;
    long long best = 1LL << 63;
    long long cur = 1LL << 63;

    for(int k = 0; k < n; k++){
        cin >> val;
        cur = (cur + val < val) ? val : cur + val;
        best = (best < cur) ? cur : best;
    }

    cout << best;
}