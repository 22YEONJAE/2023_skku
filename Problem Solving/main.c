#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996)

int n, m, box = 0;
char room[51][51];
int cases[25001][5];
int coordBox[2500][3];
int ccnt = 0;
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
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", room[i]);
    
    
    while(box != m) {
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
                if(cases[i][3] == 0) {
                    coordBox[box][0] = cases[i][0] ;
                    coordBox[box][1] = cases[i][1] + l_max/2; 
                    for(int j = cases[i][0], k = cases[i][1], t = 0; t < l_max; t++, k++) {
                        room[j][k] = 'X';
                        if(room[j-1][k] != 'X' && j != 0) room[j-1][k] = 'X';
                        if(room[j+1][k] != 'X' && j != n -1) room[j+1][k] = 'X';
                    }
                }
                else {
                    coordBox[box][0] = cases[i][0] + l_max/2;
                    coordBox[box][1] = cases[i][1];
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
        box++;
    }

    
    for(int i = 0; i < m; i ++) {
        printf("%d %d\n", coordBox[i][0], coordBox[i][1]);
    }
    


	return 0;
}