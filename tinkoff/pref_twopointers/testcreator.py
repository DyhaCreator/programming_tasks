file = open('test', 'w')

string = ''
num = 1
m = 10000

file.write(str(m - 1 + m - 1 + 1) + '\n')

for i in range(num + 1, m + 1):
    string += str(i) + ' '

string += str(num) + ' '

for i in reversed(range(num + 1, m + 1)):
    string += str(i) + ' '

file.write(string)