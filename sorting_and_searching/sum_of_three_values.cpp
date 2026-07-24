//This is O(N^2 logN), but two pointers can achieve O(N^2).
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool findValue(int k, int m, vector<vector<int>>& a, int& x, int& n){
    int beg = m + 1;
    int end = n - 1;
    int mid;

    while(beg <= end){
        mid = (end - beg)/2 + beg;

        if(a[mid][0] < x - (a[k][0] + a[m][0])){
            beg = mid + 1;
        } else if (a[mid][0] > x - (a[k][0] + a[m][0])){
            end = mid - 1;
        } else {
            cout << a[k][1] << " " << a[m][1] << " " << a[mid][1];
            return true;
        }
    }

    return false;
}

bool comp (vector<int>& a, vector<int>& b){
    return a[0] < b[0];
}

int main(){
    int n, x, val;
    bool found;
    cin >> n >> x;

    vector<vector<int>> a(n, vector<int>(2));

    for(int k = 0; k < n; k++){
        cin >> val;
        a[k][0] = val;
        a[k][1] = k + 1;
    }
    
    sort(a.begin(), a.end(), comp);

    for(int k = 0; k < n; k++){
        for(int m = k + 1; m < n; m++){
            found = findValue(k, m, a, x, n);
            if(found) return 0;
        }
    }

    cout << "IMPOSSIBLE";
}