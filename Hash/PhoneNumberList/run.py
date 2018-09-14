phoneBook = [
              ['119','97674223','1195524421'],
			  ['123','456','789'],
			  ['12','123','1235','567','88'],
			  ['12232332','12','222222']
            ]

def solution(phoneBook):
  answer = True
  count = len(phoneBook[0])
  
  for i in range(1,len(phoneBook)):
	temp_count = len(phoneBook[i])
	if temp_count < count:
	  count = temp_count

  for i in range(1,len(phoneBook)):
	print phoneBook[0][:count]
	print phoneBook[i][:count]
	if phoneBook[0][:count] == phoneBook[i][:count]:
	  answer = False
  return answer

print solution(phoneBook[3])
