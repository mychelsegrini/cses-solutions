#include <iostream>
#include <vector>
using namespace std;

int main(){
    int min;
    int n, val;
    cin >> n;
    int rounds = 1;
    vector<int>pos(n, ~(1 << 31));

    for(int k = 0; k < n; k++){
        cin >> val;
        pos[val - 1] = k;
        
        if(val < n && pos[val] < k) rounds++;
    }

    cout << rounds;
}