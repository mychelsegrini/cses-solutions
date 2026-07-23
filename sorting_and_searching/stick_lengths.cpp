#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<int>sticks(n);
    long long median = 0LL;

    for(int k = 0; k < n; k++){
        cin >> sticks[k];
    }
    
    sort(sticks.begin(), sticks.end());
    median = sticks[sticks.size()/2];

    long long cost = 0;

    for(int& i : sticks){
        cost += (i - median < 0) ? median - i : i - median;
    }

    cout << cost;
}