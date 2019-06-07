voter = int(input())
for i in range(pow(2,voter)):
	print(bin(i)[2:].zfill(voter).replace('0','O').replace('1','X'))
