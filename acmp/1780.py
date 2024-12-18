import sys
sys.set_int_max_str_digits(2**30)

def mult(a, b):
    b = [[a[0][0] * b[0][0] + a[0][1] * b[1][0], a[0][0] * b[0][1] + a[1][0] * b[1][1]],
        [a[0][1] * b[0][0] + a[1][1] * b[0][1], a[0][1] * b[1][0] + a[1][1] * b[1][1]]]
    return b

count = 0

def pow(a, b):
    #print(b)
    #count += 1
    d = [[1, 1], [1, 0]]
    #print(d)
    if (b == 1):
        return d
    if (b > 1):
        d = pow(a, b // 2)
        d = mult(d, d)
    if (b % 2 == 1):
        d = mult(d, a)
    #print(d)
    return d

def pw(a, b):
    print(b)
    d = 1
    if (b > 1):
        d = pw(a, b // 2)
        d = d * d
    if (b % 2 == 1):
        d = d * a
    return d

n = int(input())

a = [[1, 1], [1, 0]]

print(pow(a, n - 1)[0][0])

#print(pw(2, n))