#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    string s;
    string ans;
    cin >> s;

    unordered_set<char> add;

    for(char& c: s){
        if(!add.contains(c)){
            add.insert(c);
        } else {
            ans.push_back(c);
            add.erase(c);
        }
    }

    if(add.size() > 1){
        cout << "NO SOLUTION";
    } else {
        int size = ans.size();
        if(add.size() == 1) ans.push_back(*(add.begin()));
        for(int k = size - 1; k >= 0; k--){
            ans.push_back(ans[k]);
        }
        cout << ans;
    }

}