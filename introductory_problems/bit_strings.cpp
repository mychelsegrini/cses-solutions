//Remember that m = a mod M <=> a = b*M + m, given all numbers here are naturals.
//For this question, we may need that (a * b) mod M = ((a mod M) * (b mod M)) mod M.
//Let's prove this real quickly.
//Let x = a mod M and y = b mod M. If z = (a x b) mod M, then:
//a*b = c*M + z = (d*M + x)*(e*M + y) = d*e*M^2 + (d*y + e*x)*M + x*y
//In general, x*y = g*M + f <=> x*y mod M = f <=> ((a mod M)*(b mod M)) mod M = f
//Then, a*b = (d*e*M + (d*y + e*x + g))*M + f => (a*b) mod M = f
//=> (a*b) mod M = ((a mod M)*(b mod M)) mod M, q.e.d
//This solution will be linear time, but you could do it logarithmic by doing binary exponentiation.
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    unsigned long long ans = 1;
    long long mod = 1e9 + 7;

    while(n){
        if(n < 30){
            ans = ans << n;
            ans %= mod;
            n = 0;
        } else {
            ans = ans << 30;
            ans %= mod;
            n -= 30;
        }
    }

    cout << ans;
}