#include <stdio.h>
#include <string.h>

int cow(int n, int m, int c)
{
    if((n % 2 == 0 || m %2 == 0) || (n == 1 && m == 1)) return c;

    cow(n/2, m/2 , c+ 1);
    // int ld = cow(n/2, m/2 , c+ 1);
    // int ru = cow(n/2, m/2 , c+ 1);
    // int rd = cow(n/2, m/2 , c+ 1);
}


int main() {
    int N, M;  
    scanf("%d %d", &N, &M);

    int a = cow(N, M, 0);
    int f = 1;
    int sum = 0;
    for(int i = 1 ; i <= a; i++) {
        sum += f;
        f*=4;
    }

    printf("%d", sum);



}