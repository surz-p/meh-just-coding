sz = int(input('enter size: '))

import random as r

R = int(input('enter randomness: '))
L = []

for x in range(sz):
	L.append(r.randint(1, R))

print(L)
