#include <algorithm>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
    int n, x;

    scanf("%d %d\n", &n, &x);

    int coins[n];

    for(int k = 0; k < n; k++) scanf("%d", &coins[k]);

    vector<int> comb(x + 1);
    
    comb[0] = 0;

    for(int k = 1; k <= x; k++){
        unordered_set<int> history;
        for(int c : coins){
            if(!history.count(k - c) && !history.count(c) && k > c){
                comb[k] += comb[k - c];
                history.insert(k - c);
                history.insert(c);
            }
            if(k == c) comb[k]++;
        }
    }
    
    printf("%d", comb[x]);
}