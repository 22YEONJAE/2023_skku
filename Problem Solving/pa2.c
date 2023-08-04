#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

int n;
char room[51][51];
int cases[25001][5];
int ans[1000][5];
int ccnt = 0, acnt = 0;
int l_max = 0, check = 0;

void allCasesR(int i, int j)
{
    cases[ccnt][0] = i;
    cases[ccnt][1] = j;
    cases[ccnt][3] = 0;

    int temp = j;

    while(room[i][temp] != 'X' && temp != n) {
        temp++;
    }

    cases[ccnt][2] = temp - j;
    if(temp - j > l_max) l_max = temp - j;
    ccnt++;

}

void allCasesD(int i, int j)
{
    cases[ccnt][0] = i;
    cases[ccnt][1] = j;
    cases[ccnt][3] = 1;

    int temp = i;

    while(room[temp][j] != 'X' && temp != n) {
        temp++;
    }

    cases[ccnt][2] = temp - i;
    if(temp - i > l_max) l_max = temp - i;
    ccnt++;
}



int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", room[i]);
	
    while(1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0 ; j < n; j ++) {
                if(room[i][j] != 'X'){
                    check++;
                    allCasesR(i,j);
                    allCasesD(i,j);
                }
            }
        }

        if(check == 0) break;


        for(int i = 0 ; i < ccnt ; i++) {
            if(cases[i][2]==l_max) {
                ans[acnt][0] = cases[i][0];
                ans[acnt][1] = cases[i][1];
                ans[acnt][2] = cases[i][2];
                ans[acnt++][3] = cases[i][3];
                if(cases[i][3] == 0) {

                    for(int j = cases[i][0], k = cases[i][1], t = 0; t < l_max; t++, k++) {
                        room[j][k] = 'X';
                        if(room[j-1][k] != 'X' && j != 0) room[j-1][k] = 'X';
                        if(room[j+1][k] != 'X' && j != n -1) room[j+1][k] = 'X';
                    }
                }
                else {
                    for(int j = cases[i][0], k = cases[i][1], t = 0; t < l_max; t++, j++) {
                        room[j][k] = 'X';
                        if(room[j][k-1] != 'X' && k != 0) room[j][k-1] = 'X';
                        if(room[j][k+1] != 'X' && k != n -1) room[j][k+1] = 'X';
                    }
                }

                break;
            }
        }

        l_max = 0;
        ccnt = 0;
        check = 0;

    }

    
    printf("%d\n", acnt);
    for(int i = 0 ; i < acnt; i++) {
        printf("%d %d %d %d\n", ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
    }



	return 0;
}