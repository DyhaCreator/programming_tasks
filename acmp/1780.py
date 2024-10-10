import sys
sys.set_int_max_str_digits(2**30)

n = int(input())
a = 0
b = 1
while n > 0:
    a += b
    b = a - b
    n -= 1

print(len(str(a)))