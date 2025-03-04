def judge(a, b, c):
    return a + b > c and a + c > b and b + c > a

def max_tr(arr):
    arr.sort(reverse=True)
    
    n = len(arr)
    for i in range(n - 2):
        if judge(arr[i], arr[i + 1], arr[i + 2]):
            return arr[i] + arr[i + 1] + arr[i + 2]
    
    return -1

T = int(input())
for _ in range(T):
    n = int(input())
    lent = list(map(int, input().split()))
    print(max_tr(lent))