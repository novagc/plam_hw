import random as r 

out = open('input.txt', 'w', encoding='utf-8')
n = r.randint(10, 10000000)
out.write(f'{n}\n')
for i in range(n):
	x = r.randint(0, 100000)
	out.write(f'{x} ')
out.close()