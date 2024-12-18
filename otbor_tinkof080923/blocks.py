import math

N, K, Q = map(int, input().split())
k = []

for i in range(K):
    k.append(int(input()))
for i in range(Q):
    index = int(input())
    for j in range(len(k)):
        a = math.ceil(index / (2 ** k[j]))
        if(a % 2 == 0):
            index -= 2 ** k[j]
        else:
            index += 2 ** k[j]
    print(index)