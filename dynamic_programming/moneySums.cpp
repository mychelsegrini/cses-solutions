#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main(){
    int n;

    scanf("%d ", &n);

    int x[n];

    for(int k = 0; k < n; k++) scanf("%d", &x[k]);

    vector<int> sums;

    sums.push_back(x[0]);
    unordered_set<int> history;

    history.insert(x[0]);

    for(int k = 1; k < n; k++){
        for(int m = sums.size() - 1; m >= 0; m--){
            int num = x[k] + sums[m];
            if(!history.count(num)){
                history.insert(num);
                sums.push_back(num);
            }
        }

        if(!history.count(x[k])){
            history.insert(x[k]);
            sums.push_back(x[k]);
        }
    }


    sort(sums.begin(), sums.end());
    printf("%zu\n", sums.size());

    for(int k = 0; k < sums.size(); k++){
        printf("%d ", sums[k]);
    }
}