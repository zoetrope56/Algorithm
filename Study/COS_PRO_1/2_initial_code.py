def func_a(string, length):
    padZero = ""
    padSize = length-len(string)
    for i in range(padSize):
        padZero += "0"
    return padZero + string

def solution(binaryA, binaryB):
    max_length = max(len(binaryA), len(binaryB))
    binaryA = func_a(binaryA, max_length)
    binaryB = func_a(binaryB, max_length)
    
    hamming_distance = 0
    for i in range(max_length):
        if binaryA[i] is not binaryB[i]:
            hamming_distance += 1
    return hamming_distance

binaryA = "10010"
binaryB = "110"
ret = solution(binaryA, binaryB)

print(ret)
