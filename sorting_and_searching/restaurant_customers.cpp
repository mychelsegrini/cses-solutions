#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n), leav(n);

    for(int k = 0; k < n; k++){
        cin >> arr[k] >> leav[k];
    }

    sort(arr.begin(), arr.end());
    sort(leav.begin(), leav.end());

    int a = 0;
    int l = 0;
    int cur = 0;
    int ans = 0;

    while(a < n){
        if(arr[a] < leav[l]){
            cur++;
            a++;
        } else if (arr[a] > leav[l]){
            ans = (ans < cur) ? cur : ans;
            cur--;
            l++;
        } else {
            a++;
            l++;
        }
    }
    
    ans = (ans < cur) ? cur : ans;

    cout << ans;
}