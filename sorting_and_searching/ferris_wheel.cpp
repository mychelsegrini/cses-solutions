#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, x;
    int val;
    int left = 0;

    cin >> n >> x;

    int right = n - 1;

    vector<int> weights(n);

    for(int k = 0; k < n; k++){
        cin >> val;
        weights[k] = val;
    }

    sort(weights.begin(), weights.end());

    int ans = 0;

    while(left < right){
        if(weights[right] + weights[left] <= x){
            left++;
        }
        right--;
        ans++;
    }

    if(left == right) ans++;

    cout << ans;
}