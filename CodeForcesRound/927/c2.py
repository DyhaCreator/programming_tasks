t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    s = input()
    mult = 1
    for el in a:
        mult *= el
    left = 0
    right = n - 1
    for ch in s:
        if (ch == 'L'):
            print(int(mult % m), end=' ')
            mult /= a[left]
            left += 1
        elif (ch == 'R'):
            print(int(mult % m), end=' ')
            mult /= a[right]
            right -= 1
    print()