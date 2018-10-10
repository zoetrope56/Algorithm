def solution(prices):
    INF = 1000000001;
    tmp = INF
    answer = -INF
    for price in prices:
        if tmp != INF:
            answer = max(answer, tmp - price)
        tmp = min(tmp, price)
    return answer

prices1 = [1, 2, 3];
ret1 = solution(prices1);

print(ret1)
    
prices2 = [3, 1];
ret2 = solution(prices2);

print(ret2)
