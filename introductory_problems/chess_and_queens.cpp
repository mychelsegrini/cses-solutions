#include <unordered_set>
#include <string>
#include <iostream>
using namespace std;

void placeQueen(int& ans, int cur, int n, unordered_set<int>& reserved, unordered_set<int>& diag, unordered_set<int>& row, unordered_set<int>& col, unordered_set<int>& anti){
    if(n == 8){
        ans++;
        return;
    }

    for(int k = 0; k < 8; k++){
        if(!reserved.contains(8*cur + k) && !diag.contains(cur + k) && !row.contains(cur) 
        && !col.contains(k) && !anti.contains(cur - k)){
            diag.insert(cur + k);
            row.insert(cur);
            col.insert(k);
            anti.insert(cur - k);
            placeQueen(ans, cur + 1, n + 1, reserved, diag, row, col, anti);
            diag.erase(cur + k);
            row.erase(cur);
            col.erase(k);
            anti.erase(cur - k);
        }
    }
}

int main(){
    int ans = 0;
    string line;
    unordered_set<int> reserved;

    for(int k = 0; k < 8; k++){
        cin >> line;
        for(int m = 0; m < line.size(); m++){
            if(line[m] == '*') reserved.insert(8*k + m);
        }
    }

    unordered_set<int> diagonal;
    unordered_set<int> row;
    unordered_set<int> column;
    unordered_set<int> antidiagonal;

    placeQueen(ans, 0, 0, reserved, diagonal, row, column, antidiagonal);

    cout << ans;
}