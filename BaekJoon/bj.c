#include <stdio.h>

char arr[1000001];

int cantore(int a, int th, int n)
{   
    if(th == 1) {
        printf("-");
        return 0;
    }
    

    

    cantore(a, th/3, n-1);
    for(int i = a + th/3; i < a + 2*(th/3); i++) {
        printf(" ");
    }
    cantore(a+2*(th/3), th/3, n-1);

    return 0;

}

int main() 
{
    int n;
    while(scanf("%d", &n) != EOF){
    

    int th = 1;

    for(int i = 0 ; i < n; i ++) {
        th *= 3;
    }
    for(int i = 0 ; i < th; i ++) {
        arr[i] = '-';
    }

    cantore(0, th, n);
    printf("\n");
    
    }


    



}