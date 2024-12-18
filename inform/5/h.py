n = int(input())

for i in range(n):
    s = input()
    print("URL #", i + 1, sep='')
    print("Protocol =", s.split("://")[0])
    s2 = s.split("://")[1]
    s3 = ''
    if (s2.find(':') >= 0 and (s2.find('/') == -1 or s2.find(':') < s2.find('/'))):
        print('Host     =', s2.split(':')[0])
        s3 = s2.split(':')[1]
        print('Port     =', s3.split('/')[0])
        s2 = s2[s2.find('/'):]
    else:
        print('Host     =', s2.split('/')[0])
        print('Port     = <default>')
    s3 = s2[s2.find('/') + 1:]
    if (len(s3) > 0 and s2.find('/') > -1):
        print('Path     =',s3)
    else:
        print('Path     = <default>')
    print()