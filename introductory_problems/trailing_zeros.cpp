//To count the number of trailing zeros, we need to count the number of factors of 10 in the multiplication.
//Call that c_{10} = min(c_{5}, c_{2}) =  c_{5}. Then, we can calculate that easily, since 5 is prime.
//If p is prime, c_{p} = floor(c/p) + floor(c/p^2) + floor(c/p^3) + ...
//That is true because every multiple of p has a factor of p, every multiple of p^2 has a factor of p
//(but we already counted one factor of p in each of them in the first term), and so on.


#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long fives = 0;
    long long num = 5;

    while(n / num){
        fives += n/num;
        num *= 5;
    }

    cout << fives;
}