import re

t = int(input())
for test in range(1, t+1):
    n = int(input())
    print('Case %d:' % test)
    for i in range(n):
        line = input()
        line = re.sub(r' +', ' ', line)
        print(line)
    if test < t:
        print()
