// coinCombinations.cpp

#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n, x;

    scanf("%d %d\n", &n, &x);

    int coins[n];

    for(int k = 0; k < n; k++) scanf("%d", &coins[k]);

    vector<int> comb(x + 1);
    
    comb[0] = 0;

    for(int k = 1; k <= x; k++){
        for(int c: coins){
            if(k > c) comb[k] = (comb[k] + comb[k - c]) % static_cast<int>(pow(10, 9) + 7);
            if(k == c) comb[k] = (comb[k] + 1) % static_cast<int>(pow(10, 9) + 7);
        }
    }

    printf("%d", comb[x]);
}