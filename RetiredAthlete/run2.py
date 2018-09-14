participant = ['marina', 'josipa', 'nikola', 'vinko', 'filipa'] 
completion = ['josipa', 'filipa', 'marina', 'nikola']

def solution(part, comp):
  marathon = {}
  hash_sum = 0
  for p in part:
	marathon[hash(p)]= p
	hash_sum += hash(p)

  for c in completion:
	hash_sum -= hash(c)
  answer = marathon[hash_sum]
  return answer

print solution(participant, completion)
