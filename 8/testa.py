import random
import os
import time

name = 'a.py'

f = open('testa', 'w')

n = 100
m = 10
s = '\n'
for i in range(n):
    s += str(random.randint(0, m)) + ' '
s += '\n'
f.write(str(n))
f.write(s)
f.close()

start_time = time.time()

cmd = f'python {name} < testa'
os.system(cmd)

print("%s sec" % (time.time() - start_time))