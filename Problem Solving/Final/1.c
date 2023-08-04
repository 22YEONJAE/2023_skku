#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int t = 10;
int sum = 0;


int main() {
    int n;
    scanf("%d", &n);
    int c = n;
    int cnt = 0;
    while(c != 0)
    {
        c /= 10;
        cnt++;
        
    }

    
    
    c = n;
    for(int i = 0 ; i < cnt; i ++) {
        sum = sum*10 + c%t;

        c /= t;
    }

    printf("%d", sum + n);

    

    return 0;
}