a = int(input())
b = int(input())
c = int(input())

ans = float('inf')
if(a * 4 < ans):
    ans = a * 4
if(b * 2 + 1 < ans):
    ans = b * 2 + 1
if(c * 4 + 2 < ans):
    ans = c * 4 + 2
print(ans)