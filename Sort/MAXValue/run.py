answer=''
numbers=[6,10,2]
sorted(numbers, key=lambda x:x)
for i in range(0, len(numbers)//2):
  for j in range(i+1,len(numbers)):
	if len(str(numbers[j])) == len(str(numbers[i])):
	  if numbers[j] % numbers[i] == 0:
		numbers[j] , numbers[i] = numbers[i], numbers[j]
	else:
	  pass
while(len(numbers)):
  answer+=str(numbers.pop())
print(answer)

# EX2
"""
for n in numbers:
  if len(str(n))>1:
	div = len(str(n))-1
	n = float(float(n)/(10**div))
  order.append(n)
order.sort(reverse=True)
print(order)
while(len(order)):
  answer+=str(order.pop()).replace('.','')
print(answer)
"""
