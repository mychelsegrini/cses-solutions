#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n;

    scanf("%d\n", &n);

    char grid[n][n];

    for(int k = 0; k < n; k++){
        for(int m = 0; m < n; m++){
            scanf(" %c", &grid[k][m]);
        }    
    }
   
    vector<vector<int>> paths(n, vector<int>(n));

    if(grid[0][0] != '*') paths[0][0] = 1;

    for(int k = 0; k < n; k++){
        for(int m = 0; m < n; m++){
            if(grid[k][m] == '*') continue;
            if(k > 0) paths[k][m] = (paths[k][m] +  paths[k - 1][m]) % static_cast<int>(pow(10, 9) + 7);
            if(m > 0) paths[k][m] = (paths[k][m] + paths[k][m - 1]) % static_cast<int>(pow(10, 9) + 7);
        }
    }

    printf("%d", paths[n - 1][n - 1]);
}