#include <stdio.h>

int arr[6000];
int N;
int count = 0;

int main() {
    scanf("%d", &N);

    for(int i = 0 ; i < N; i ++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1 ; i < N -1 ; i ++) {
        int left_sum = arr[i-1], lefti = i -1;
        int right_sum = arr[i+1], righti = i + 1;

        while(lefti >= 0 && righti < N) {
            if(left_sum == right_sum) {
                count++;
                break;
            }
            else if(left_sum > right_sum) {
                righti++;
                right_sum += arr[righti];
            }
            else if(left_sum < right_sum) {
                lefti--;
                left_sum += arr[lefti];
            }
        }
    }

    printf("%d", count);
}