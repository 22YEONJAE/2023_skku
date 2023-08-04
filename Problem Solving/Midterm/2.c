#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[101];
int l[101];
int attemp[100000];


int main() {
    int N = 0;
    for(int i = 0; i < 100000; i++) {
        attemp[i] = 0;
    }
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d %d", &a[i], &l[i]);
        
    }
    //printf("%d\n", N);
    for(int i = 1; i <= N; i++) {
        for(int j = a[i] + 1; j < 100000 ; ) {
            for(int k = j; k < j + l[i]; k++) {
                attemp[k]++;
            }
            j+=l[i] + a[i];
        }
        // printf("%d\n", i);
        // printf("*");
        
    }


    for(int i = 1 ; i < 100000; i ++){
        //printf("%d  ", attemp[i]);
        if(attemp[i] == N) {
            printf("%d\n", i);
            return 0;
        }
    }



    return 0;
}