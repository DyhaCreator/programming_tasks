n = int(input())
A = map(int, input().split())
B = {}

for i in A:
    if (B.get(i) == None):
        B[i] = 0
    B[i] += 1

for i in list(B):
    print(i, B[i])