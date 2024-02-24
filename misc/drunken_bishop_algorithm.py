# https://www.codingame.com/ide/puzzle/ascii-art-the-drunken-bishop-algorithm

# helper to print rows of a 2D list
def display(b):
    for row in b:
        print(f"|{''.join(row)}|")

# sanitizing input and setting helper variables
f = input().split(':')
c = [' ','.','o','+','=','*','B','O','X','@','%','&','#','/','^']
m = { '00': [-1,-1], '01': [-1,1], '10': [1,-1], '11': [1,1] }

# create board
b = []
for i in range(9):
    b.append([' '] * 17)

sp = [4,8]
# set starting character
b[sp[0]][sp[1]] = 'S'

for item in f:
    # get the binary representation of each byte (separated by :)
    # make sure to get 8 bits, because some hex like 0x7C fit in 7 bits
    t = bin(int(item, 16))[2:].zfill(8)
    while t:
        # get last two bits
        where = m[t[-2:]]
        # check if you can navigate to new point
        if 0 <= sp[0] + where[0] < 9:
            sp[0] += where[0]
        if 0 <= sp[1] + where[1] < 17:
            sp[1] += where[1]
        # replace the new point with the next character in sequence
        if b[sp[0]][sp[1]] != 'S':
            n = (c.index(b[sp[0]][sp[1]]) + 1) % len(c)
            b[sp[0]][sp[1]] = c[n]
        t = t[:-2]

# set ending character
b[sp[0]][sp[1]] = 'E'
# print the result
print('+---[CODINGAME]---+')
display(b)
print('+-----------------+')
