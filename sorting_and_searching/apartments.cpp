#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> apartments(m);
    vector<int> applicants(n);
    int val = 0;

    for(int a = 0; a < n; a++){
        cin >> val;
        applicants[a] = val;
    }

    for(int a = 0; a < m; a++){
        cin >> val;
        apartments[a] = val;
    }

    sort(apartments.begin(), apartments.end());
    sort(applicants.begin(), applicants.end());
    
    int counter = 0;
    int app = 0;
    val = 0;

    while(counter < apartments.size() && app < applicants.size()){
        if(apartments[counter] >= applicants[app] - k &&
        apartments[counter] <= applicants[app] + k){
            val++;
            app++;
            counter++;
        } else if (apartments[counter] > applicants[app] + k){
            app++;
        } else if (apartments[counter] < applicants[app] - k){
            counter++;
        }
    }

    cout << val;
}