inp = open('input.txt', 'r', encoding='utf-8')
out = open('output.txt', 'r', encoding='utf-8')

inp.readline()
a = list(map(int, inp.readline().split()))
b = list(map(int, out.readline().split()))

a.sort()

good = True
for i in range(len(a)):
	if a[i] != b[i]:
		print('BAD')
		good = False

if good:
	print('GOOD')