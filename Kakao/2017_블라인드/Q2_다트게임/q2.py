import re

def solution(record):
  record = re.findall(r'[0-9]*?[^0-9][^a-zA-Z0-9]?', record)
  record.reverse()
  total = 0
  flag = 0

  for data in record:
    score = re.findall(r'[0-9][0-9]?',data) # list
    rate = re.findall(r'[S,D,T]',data) # list
    opt = re.findall(r'[^0-9a-zA-Z]',data) # list
    if rate[0] == 'D':
      rate = 2
    elif rate[0] == 'T':
      rate = 3
    else:
      rate = 1 

    if opt == ['*']:
      flag += 1
      if flag > 2: flag = 2
      opt = pow(2,flag)
    elif opt == ['#']:
      opt = pow(2,flag) * -1
      flag -= 1
    elif opt == []:
      opt = pow(2,flag)
      flag -= 1
    else:
      opt = pow(2,flag)
      flag -=1
    
    if flag < 0: flag = 0

    print( total, score, rate, opt)
    total += pow(int(score[0]),rate)*opt
  return total
    
print(solution('1S#2T#3S*'))  
