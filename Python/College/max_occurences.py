#Find the word which appears the maximum number of times in a given file.
import os

files=os.listdir()

filename=input('enter file')

if filename not in files:
	print('file not found')

else:
	f = open(filename,'r')

	li= ['.',',','?',';',':','=']
	x=[]
	dict={}

	for line in  f:
		
		line = line.lower()
		
		for i in li :
			line=line.replace(i,'')
		print(line)

		x.extend(line.split())
		print('list is', x)
		

	for i in x :
		p = x.count(i)
		dict[i] =p

	print('dict is ',dict)	
	# val = list(dict.values())
	# key = list(dict.keys())

	#print(key[val.index(max(val))])
	max1=0
	maxWord = ''
	for word in dict:

		if dict[word] > max1:
			max1=dict[word]
			maxWord=word

	print("'" + maxWord + "' has the maximum number of occurences and number of occurences = " + str(max1))	

