#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<long long> x(t);
    vector<long long> y(t);
    long long n; //Reference coordinate for our anchor on the diagonal (n, n), which has a very predictable pattern.
    //If you look very closely, the differences between the numbers in the diagonal is the sequence of even numbers.
    //Then, value(n, n) = 1 + 2 + 4 + 6 + ... + 2*(n - 1)
    //This is the sum of an arithmetic progression of 2nd order, where a_{n + 1} - a_n = 2*n
    //Then, it must be a polynomial of the form a_n = An^2 + B*n + C
    //Let's solve it. a_{n + 1} - a_{n} = A*(n^2 + 2n + 1 - n^2) + B = 2*n
    //=> (A, B) = (1, -1)
    //Since a_1 = 1, C = 1 - 1 + 1 = 1.
    //Hence, the diagonal follows a_n = n^2 - n + 1.

    long long diag; //Value in the diagonal

    for(int k = 0; k < t; k++){
        cin >> y[k];
        cin >> x[k];
    }

    for(int k = 0; k < t; k++){
        if(x[k] <= y[k]){
            n = y[k];
            diag = n*n - n + 1;
            if(!(n % 2)){ //The spiral is increasing counterclockwise.
                cout << diag + (n - x[k]); 
            } else { //The spiral is increasing clockwise.
                cout << diag - (n - x[k]);
            }
        } else {
            n = x[k];
            diag = n*n - n + 1;
            if(!(n % 2)){
                cout << diag - (n - y[k]);
            } else {
                cout << diag + (n - y[k]);
            }
        }
        if(k < t - 1) cout << "\n";
    }
}