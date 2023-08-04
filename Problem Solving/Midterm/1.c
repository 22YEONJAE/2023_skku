#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int sum[1001];
int cnt = 0;


int main() {
    int w, p, M;
    scanf("%d %d %d", &w, &p, &M);

    sum[cnt] = w * p;
    cnt++;

    for(int i = 0; i < M; i++) {
        int a = sum[cnt-1] + 10*p;
        int b = sum[cnt-1] + 5*w;

        if(a >= b) {
            sum[cnt] = a;
            cnt++;
            w = w+ 10;
        }
        else {
            sum[cnt] = b;
            cnt++;
            p = p + 5;
        }
    }

    int max = 0;

    for(int i = 1; i <= M; i++) {
        int temp = sum[i] * (M-i + 1);

        if(temp > max) max = temp;
    }

    printf("%d\n", max);
    



    return 0;
}