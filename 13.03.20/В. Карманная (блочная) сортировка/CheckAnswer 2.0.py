out = open('output.txt', 'r', encoding='utf-8')

b = list(map(int, out.readline().split()))

good = True
for i in range(1, len(b)):
	if b[i] < b[i - 1]:
		print(f'BAD {i}: ...{b[i - 2]} {b[i - 1]} {b[i]} {b[i + 1]} {b[i + 2]}...')
		good = False
		break

if good:
	print('GOOD')