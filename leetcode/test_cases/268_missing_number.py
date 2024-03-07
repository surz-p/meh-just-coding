sz = int(input('input size: '))

L = []

for i in range(0, sz + 1):
    L.append(i)

import random as r
r.shuffle(L)

O = L[1:]
if 0 not in O:
    O[0] = 0
print(O)
