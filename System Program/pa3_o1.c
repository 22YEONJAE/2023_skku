#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

int n;
char room[1001][1001];
int walls_x[1000], walls_y[1000];
int cases[100000][5];
int ans[100000][5];
int ccnt = 0, acnt = 0;
int l_max = 0, check = 0;

int isWall_x(int x)
{
    for(int i = 0; i < 50; i ++) {
        if(walls_x[i] == x) return 1;
    }
    return 0;
}

int isWall_y(int y)
{
    for(int i = 0; i < 50; i ++) {
        if(walls_y[i] == y) return 1;
    }
    return 0;
}

void makeRoom()
{
    srand(time(NULL));

	for (int i = 0; i < 50; i++) { 
        walls_x[i] = rand()%1000;
        walls_y[i] = rand()%1000;

        room[walls_x[i]][walls_y[i]] = 'X';
	}

    for(int i = 0; i < 1000; i++) {
        for(int j = 0; j < 1000; j++) {
            if( room[i][j] != 'X' ) {
                room[i][j] = '.';
            }
        }
    }
}

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
	//scanf("%d", &n);
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