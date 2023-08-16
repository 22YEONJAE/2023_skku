# 체스판 다시 칠하기
# 브루트 포스
# 1018번
# 2023-08-12
# Silver 4

# 2차원 배열 선언 및 0으로 초기화
# COLUM : 가로 길이
# ROW : 세로 길이
# board = [[0 for i in range(COLUM)] for j in range(ROW)] 

# 파이썬에는 true ? a : b

f_line = input().split(' ')

row = int(f_line[0])
col = int(f_line[1])

board = [[0 for i in range(col)] for j in range(row)]
cnt = 3000

for i in range(row) :
    board[i] = list(input())

# for i in range(row) :
#     print(board[i])

for i in range(row-7) :
    for j in range(col-7) :
        temp1 = 0
        temp2 = 0

        # 처음 칸을 B로하는게 최소라고 가정
        for k in range(i, i + 8) :
            for p in range(j, j + 8) :
                if (k-i)%2 == 0 and (p-j) %2 == 1 and board[k][p] == 'B' : 
                    temp1 += 1
                elif (k-i)%2 == 0 and (p-j)%2 == 0 and board[k][p] == 'W' :
                    temp1 += 1
                elif (k-i)%2 == 1 and (p-j)%2 == 1 and board[k][p] == 'W' :
                    temp1 += 1
                elif (k-i)%2 == 1 and (p-j)%2 == 0 and board[k][p] == 'B' :
                    temp1 += 1

        # 처음 칸을 W로 하는게 최소라고 가정
        for k in range(i, i + 8) :
            for p in range(j, j+ 8) :
                if (k-i)%2 == 0 and (p-j)%2 == 1 and board[k][p] == 'W' : 
                    temp2 += 1
                elif (k-i)%2 == 0 and (p-j)%2 == 0 and board[k][p] == 'B' :
                    temp2 += 1
                elif (k-i)%2 == 1 and (p-j)%2 == 1 and board[k][p] == 'B' :
                    temp2 += 1
                elif (k-i)%2 == 1 and (p-j)%2 == 0 and board[k][p] == 'W' :
                    temp2 += 1
        if temp1 < cnt or temp2 < cnt :
            if temp1 <= temp2 :
                cnt = temp1
            else :
                cnt = temp2

print(cnt)

        



