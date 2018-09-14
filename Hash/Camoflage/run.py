clothes_1 = [['yellow_hat','headgear'],
		     ['blue_sunglasses','eyeware'],
		     ['green_turban','headgear']
		    ]
clothes_2 = [['crow_mask','face'],
		     ['blue_sunglasses','face'],
			 ['smoky_makeup','face']
			]

def solution(clothes):
  item_count = 1
  category = dict()
  
  for c in clothes:
	temp_hash = hash(c[1])
	if temp_hash not in category:
	  category[temp_hash] = [c[0]]
	else:
	  category[temp_hash].append(c[0])

  hash_list = category.keys()
  for h in hash_list:
	item_count = item_count *(len(category[h])+1)

  return item_count-1

print solution(clothes_1)
