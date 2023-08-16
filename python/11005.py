# 진법 변환 2 
# 일반 수학 1
# 11005 번
# 2023-08-11
# Bronze 1

line = input().split(' ')
decimal = int(line[0])
n = int(line[1])

#list 초기화
ans = []

while decimal > 0 :
    if decimal%n < 10 :
        # chr -> 아스키코드를 문자로 변환 / ord -> 문자를 아스키코드로 변환
        ans.append(chr(decimal%n + 48)) 
    else :
        ans.append(chr(decimal%n + 55))
    
    decimal = int(decimal / n)

ans.reverse()

# list를 문자열로 변환할 때
print(''.join(ans))
