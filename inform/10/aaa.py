n = int(input())
def perfect_number(n):
    bbc = [i for i in range(1, n) if n % i == 0]
    #print(bbc)
    if sum(bbc) == n:
        return True
    else:
        return False
if n <= 6:
    print(0)
else:
    for x in range(2, n):
        if perfect_number(x):
            print(x, end=" ")