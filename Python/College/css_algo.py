from math import ceil

def gen_even_key(pt):
	k=0
	for ele in pt:
		if ele%2==0:
			k+=1
	return k

def gen_num(inp):
	num=[]
	for i in range(len(inp)):
		x = ord(inp[i])
		if x>= ord('a') and x<=ord('z'):
			num.append(x-ord('a'))
	return num

57380140059
def gen_letters(num):
	let = []
	for i in range(len(num)):
		let.append(chr(num[i]+ord('a')))
	return let

def gen_cipher(num):
	for i in range(len(num)):
		if num[i]%2==0:
			num[i] = (num[i]+k2)%26
		else:
			num[i] = (num[i]+k1)%26
	return num

def gen_transposition(letters):
	transposed_text = []
	k=0
	flag = 0
	if len(letters)%2!=0:
		flag=1
	for i in range(2):

		for j in range(ceil(len(letters)/2)):
			if i==1 and j== ceil(len(letters)/2)-1 and flag==1:
				break
			transposed_text.append(letters[k])
			k+=2
			
		k=1
	return transposed_text

def decrypt_transpos(transposed_text):
	decrypt = []
	mid = ceil(len(transposed_text)/2)
	try:
		for i in range(mid):
			decrypt.append(transposed_text[i])
			decrypt.append(transposed_text[mid+i])

	except IndexError:
		pass
	return decrypt

def decrypt_cipher(decrypt_transpos,k1,k2):
	num = gen_num(decrypt_transpos)
	print(num)
	for i in range(len(num)):
		if num[i]%2==0:
			num[i] = (num[i]-k2)%26
		else:
			num[i] = (num[i]-k1)%26
	letters = gen_letters(num)
	return letters

inp = input("Enter the plain text\n")
inp = inp.split(" ")

num = gen_num(inp)
print(num)

k2 = gen_even_key(num)
k1 = len(num) - k2

if k2%2==0:
	k2+=1
if k1%2==0:
	k1+=1

num = gen_cipher(num)

letters = gen_letters(num)

print(letters)

no_columns = 3

transposed_text = gen_transposition(letters)

print(transposed_text)

decrypt_transpos = decrypt_transpos(transposed_text)
print(decrypt_transpos)

decrypt_cipher = decrypt_cipher(decrypt_transpos,k1,k2)
print(decrypt_cipher)
