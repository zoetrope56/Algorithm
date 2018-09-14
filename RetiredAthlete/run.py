import time

#Case 1

participant = ['marina', 'josipa', 'nikola', 'vinko', 'filipa'] 
completion = ['josipa', 'filipa', 'marina', 'nikola']

"""
#Case 2
participant = ['mislav', 'stanko', 'mislav', 'ana']
completion = ['stanko', 'ana', 'mislav']
"""

"""
#Case 3
participant = ['leo', 'kiki','eden']
completion = ['eden','kiki']
"""

def solution1(participant, completion):
  participant.sort()
  completion.sort()

  for i in range(len(completion)):
	if participant[i] != completion[i]:
	  return participant[i]
  return participant[len(participant)-1]

def solution2(part, comp):
  part.sort(reverse=True)
  comp.sort(reverse=True)
  while(len(comp) != 0):
	t1 = comp.pop()
	t2 = part.pop()
	if not(t1 == t2):
	  return t1
  return part[0]

print '\n\n-----------------------------------'

print "Participant"
print participant

print "Completion"
print completion

print '-----------------------------------\n\n'

t1_begin = time.clock()
print solution1(participant, completion)
t1_end = time.clock()
print 'elapsed (floating point) : ', t1_end-t1_begin

t2_begin = time.clock()
print solution2(participant, completion)
t2_end = time.clock()
print 'elapsed (floating point) : ', t2_end-t2_begin


