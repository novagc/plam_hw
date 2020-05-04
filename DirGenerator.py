import os
temp = open('dirs.txt', 'r').readlines()
inDir = ''
for dir in temp:
	if sum([x.isdigit for x in dir.split('.')]) == 3:
		os.mkdir(f'./{dir}')
		inDir = dir
	else:
		os.mkdir(f'./{inDir}/{dir}')
		if not os.path.exists(f'./{inDir}/{dir}/Source.cpp'):
			open(f'./{inDir}/{dir}/Source.cpp', 'w').close()