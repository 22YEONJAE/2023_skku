# 영화감독 숌
# 브루트포스
# -> 발생할 수 있는 모든 경우를 무식하게 탐색한다는 뜻
# -> 알고리즘 생각 x
# 1436번
# Silver 5

Nth = int(input())
cnt = 0
i = 665

while cnt != Nth :
    # 6이 연속 세 번으로 나오는지 확인
    six_cnt  = 0
    i_list = list(str(i))
    for c in i_list :
        if c == '6' :
            six_cnt += 1
            if six_cnt == 3 :
                cnt += 1
        else :
            six_cnt = 0
    i += 1

print(i - 1)