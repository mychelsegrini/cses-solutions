#include <cstdio>
#include <unordered_map>
#include <cmath>
#include <climits>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    // Some machinery
    unordered_map<int, int> num;
    num[0] = 0;

    for(int k = 0; k <= n; k++){
        for(int m = 1; m < 7; m++){
            if(k - m > 0) num[k]  = (num[k] + num[k - m]) % static_cast<int>(pow(10, 9) + 7);
            if(k - m == 0) num[k] = (num[k] + 1) % static_cast<int>(pow(10, 9) + 7);
        }
    }

    int ans = num[n];
    printf("%d", ans);
}