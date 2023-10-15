l = int(input())
n = int(input())

a = []
for i in range(n):
    a.append(int(input()))

ans = 0
i = 0
while(i < len(a)):
    if(a[i] == 1):
        ans += 1
        i += l - 1
    i += 1
#print(a)
print(ans)