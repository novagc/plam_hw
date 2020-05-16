import sys
import random as r 

if len(sys.argv) == 4:
	count = int(sys.argv[1])
	min = int(sys.argv[2])
	max = int(sys.argv[3])
else: 
	count = r.randint(10, 10000000)
	min = 0
	max = 100000

out = open('input.txt', 'w', encoding='utf-8')
out.write(f'{count}\n')
for i in range(count):
	x = r.randint(min, max)
	out.write(f'{x} ')
out.close()