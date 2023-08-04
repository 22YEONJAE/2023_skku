#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

int n;
char room[501][501];
char resultRoom[501][501];
int walls_x[1000], walls_y[1000];
int cases[100000][5];
int ans[100000][5];
int length[100001];
int ccnt = 0, acnt = 0;
int l_max = 0, check = 0;

int findMaxV() {
    int temp;
    for(int i = ccnt; i>0; i--){
        for(int j=0; j < i; j++) {
            if(length[j]<length[j+1]){
                temp = length[j];
                length[j] = length[j+1];
                length[j+1] = temp;
            }
        }
  }

  return length[0];

}

void lengthtozero()
{
    for(int i = 0;  i<= 200; i ++) {
        length[i] = 0;
    }
}

void printRoom()
{
    for(int i = 0; i < 200; i ++) {
        for(int j = 0; j < 200; j++) {
            printf("%c ", room[i][j]);
        }
        printf("\n");
    }
}

int isWall_x(int x)
{
    for(int i = 0; i < 200; i ++) {
        if(walls_x[i] == x) return i;
    }
    return 0;
}

int isWall_y(int y)
{
    for(int i = 0; i < 200; i ++) {
        if(walls_y[i] == y) return i;
    }
    return 0;
}

void makeRoom()
{
    srand(time(NULL));

	for (int i = 0; i < 200; i++) { 
        walls_x[i] = rand()%200;
        walls_y[i] = rand()%200;
	}

    for(int i = 0; i < 200; i++) {
        for(int j = 0; j < 200; j++) {
            if( isWall_x(j) == isWall_y(i)) {
                room[j][i] = 'X';
                resultRoom[j][i] = 'X';
            }
            else {
                room[j][i] = '.';
                resultRoom[j][i] = '.';
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

    while(room[i][temp] != 'X' && temp != 200) {
        temp++;
    }

    cases[ccnt][2] = temp - j;

    // length 배열에 모든 길이 저장.
    length[ccnt] = temp - j;
    ccnt++;

}

void allCasesD(int i, int j)
{
    cases[ccnt][0] = i;
    cases[ccnt][1] = j;
    cases[ccnt][3] = 1;

    int temp = i;

    while(room[temp][j] != 'X' && temp != 200) {
        temp++;
    }

    cases[ccnt][2] = temp - i;
    length[ccnt] = temp - i;
    ccnt++;
}



int main() {
    makeRoom();
	printRoom();
	
    while(1) {
        for(int i = 0; i < 200; i++) {
            for(int j = 0 ; j < 200; j ++) {
                if(room[i][j] != 'X'){
                    check++;
                    allCasesR(i,j);
                    allCasesD(i,j);
                }
            }
        }

        if(check == 0) break;

        l_max = findMaxV();
        printf("%d ", l_max);


        for(int i = 0 ; i < ccnt ; i++) {
            if(cases[i][2]==l_max) {
                ans[acnt][0] = cases[i][0];
                ans[acnt][1] = cases[i][1];
                ans[acnt][2] = cases[i][2];
                ans[acnt++][3] = cases[i][3];
                if(cases[i][3] == 0) {

                    for(int j = cases[i][0], k = cases[i][1], t = 0; t < l_max; t++, k++) {
                        room[j][k] = 'X'; resultRoom[j][k] = 'O';
                        if(room[j-1][k] != 'X' && j != 0) room[j-1][k] = 'X';
                        if(room[j+1][k] != 'X' && j != 200 -1) room[j+1][k] = 'X';
                    }
                }
                else {
                    for(int j = cases[i][0], k = cases[i][1], t = 0; t < l_max; t++, j++) {
                        room[j][k] = 'X'; room[j][k] = 'X'; resultRoom[j][k] = 'O';
                        if(room[j][k-1] != 'X' && k != 0) room[j][k-1] = 'X';
                        if(room[j][k+1] != 'X' && k != 200 -1) room[j][k+1] = 'X';
                    }
                }

                break;
            }
        }

        l_max = 0;
        lengthtozero();
        ccnt = 0;
        check = 0;

    }

    
    printf("%d\n", acnt);
    for(int i = 0 ; i < acnt; i++) {
        printf("%d %d %d %d\n", ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
    }

    for(int i = 0 ; i < 200; i ++) {
        for(int j = 0 ; j < 200; j++) {
            printf("%c ", resultRoom[i][j]);
        }
        printf("\n");
    }








	return 0;
}