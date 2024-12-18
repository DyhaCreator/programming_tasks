n, x = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

ma = -2
for i in range(len(a)):
    if(a[i] < a[ma]):
        ma = i

mb = -2
for i in range(ma + 1, len(b)):
    if(b[i] > b[mb]):
        mb = i

ox = round(x - a[ma] * (x / a[ma]) + b[mb] * (x / a[ma]))
print(ox)
if(mb != -2):
    print(ma + 1, mb + 1)
else:
    print(-1, -1)