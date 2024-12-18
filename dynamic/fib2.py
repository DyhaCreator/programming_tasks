n = int(input())

fib = [0] * (n + 3)

fib[1] = 1

for i in range(2, n + 3):
    fib[i] = fib[i - 1] + fib[i - 2]

print(fib[n + 2])