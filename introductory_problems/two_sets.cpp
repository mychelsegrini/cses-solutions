#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    if(n % 4 == 0){ //In this case, we can group an even number of pairs who sum to (n + 1)
        cout << "YES\n";
        cout << n/2 << "\n";
        for(int k = 0; k < n/4; k++){
            cout << 1 + k << " " << n - k;
            if(k < n/4 - 1) cout << " ";
        }
        cout << "\n" << n/2 << "\n";
        for(int k = n/4; k < n/2; k++){
            cout << 1 + k << " " << n - k;
            if(k < n/2 - 1) cout << " ";
        }
    } else if (n % 4 == 3){ //Since 3 = 1 + 2, this case is a "yes". For any other example that fits here,
        //we can construct the sets using sandwiches of 4 numbers. In general, k + (k + 3) = (k + 1) + (k + 2).
        cout << "YES\n";
        cout << n/2 + 1 << "\n";
        cout << 1 << " " << 2;
        int k = 4;
        while(k <= n){
            cout << " " << k;
            if(k % 4){
                k++;
            } else {
                k += 3;
            }
        }
        cout << "\n" << n/2 << "\n";
        cout << 3;
        k = 5;
        while(k < n){
            cout << " " << k;
            if(k % 4 == 1){
                k++;
            } else {
                k += 3;
            }
        }

    } else cout << "NO";
}