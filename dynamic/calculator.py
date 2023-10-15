n = int(input())

a = [0] * (n + 1)
b = [0] * (n + 1)
for i in range(2, n + 1):
    a[i] = a[i - 1] + 1
    b[i] = 0
    if(i % 2 == 0 and a[i // 2] + 1 < a[i]):
        a[i] = a[i // 2] + 1
        b[i] = 1
    if(i % 3 == 0 and a[i // 3] + 1 < a[i]):
        a[i] = a[i // 3] + 1
        b[i] = 2
i = n
s = ''
while(i > 1):
    s += str(b[i] + 1)
    if(b[i] == 0):
        i -= 1
    elif(b[i] == 1):
        i = i // 2
    elif(b[i] == 2):
        i = i // 3
print(s[::-1])