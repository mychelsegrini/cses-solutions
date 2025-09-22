// minimizingCoins.cpp

#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int main(){
    int n;
    int x;

    scanf("%d %d\n", &n, &x);
    
    int coins[n];
    for(int k = 0; k < n; k++){
        scanf("%d", &coins[k]);
    }

    vector<int> sum(x + 1);
    
    sum[0] = 0;

    for(int k = 1; k <= x; k++){
        sum[k] = INT_MAX;
        for(int c: coins){
            if(k - c >= 0 && sum[k - c] < INT_MAX) sum[k] = min(sum[k], sum[k - c] + 1);
        }
    }

    if(sum[x] == INT_MAX) {
        printf("%d", -1);
    } else {
        printf("%d", sum[x]);
    }   
}