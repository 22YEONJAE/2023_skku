#include <stdio.h>
#include <string.h>

int n;
int dp[1001];

int main() {
    scanf("%d", &n);
    dp[0] = 0;
    for(int i = 1 ; i <= n; i ++) {
        scanf("%d", &dp[i]);
    }

    int sum = dp[n];
    int ck = 0;
    int i = n;
    while(1)
    {   
        if(ck == 1) {
            sum += dp[i-2];
            i-=2;
            ck = 0;
        }
        else {
            if(dp[i-1] >= dp[i-2]){
                sum += dp[i-1];
                i -= 1;
                ck = 1;
            }
            else {
                sum += dp[i-2];
                i-=2;

            }
        }
        
        if(i <= 1) break;


    }

    printf("%d", sum);


}