n = int(input())

k = [0] * (n + 2)
k[n] = 1

for i in reversed(range(n)):
    k[i] = k[i + 1] + k[i + 2]
print(k[0])
