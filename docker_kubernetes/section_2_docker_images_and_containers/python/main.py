import random as R

a = int(input('Enter smallest random number: '))
b = int(input('Enter largest random number: '))

if a > b:
    print('hey, are you dyslexic?')
    exit(1)
else:
    print(f'Here is a random number brother: {R.randint(a, b)}')
