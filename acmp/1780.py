import sys
sys.set_int_max_str_digits(2 ** 30)

n = int(input())
print(round(1 / (5 ** 0.5) * (((1 + 5 ** 0.5) / 2) ** n - ((1 - 5 ** 0.5) / 2) ** n)))