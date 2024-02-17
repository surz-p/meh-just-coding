import random as r

sz = 3*10**3

v=[]

for _ in range(sz):
    v.append(r.randint(1,10**5))

print(f"[{','.join(str(x) for x in v)}]")

