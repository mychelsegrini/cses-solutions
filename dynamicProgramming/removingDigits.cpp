#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);

    int counter = 0;

    while(n > 0){
        int d = 0;
        
        int num = n;
        int k = 1;
        while(true){
            int m = num % 10;
            if(m > d) d = m;
            num /= 10;
            if(num == 0) break;
            k++;
        }

        counter++;
        n -= d;
    }

    printf("%d", counter);
}