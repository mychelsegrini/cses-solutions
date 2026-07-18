#include <unordered_set>
#include <iostream>
using namespace std;

int main(){
    unordered_set<int> missing;
    
    int n;
    cin >> n;
    for(int k = 1; k <= n; k++){
        missing.insert(k);
    }

    for(int k = 0; k < n - 1; k++){
        int m;
        cin >> m;
        missing.erase(m);
    }

    auto it = missing.begin();
    cout << *it;
}