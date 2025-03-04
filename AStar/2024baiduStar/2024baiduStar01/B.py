isprime = [1] * 10000005
minp = [0] * 10000005
sum = [0] * 10000005
num = [0] * 10000005
f = [0] * 10000005
prime = [0] * 10000005
mod = 998244353
def init(n):
    global cnt
    cnt = 0
    isprime[1]= 0
    for i in range(2,n+1):
        if isprime[i]:
            cnt+=1
            prime[cnt]=i
            minp[i]=i
        j = 1
        while j <= cnt and i * prime[j] <= n:
            isprime[i*prime[j]]=False
            minp[i*prime[j]]=prime[j]
            if i % prime[j] == 0:
                break
            j+=1


lcm = 1
n = int(input())
init(10000000)
for i in range(2, n + 1):
    if isprime[i]:
        lcm = lcm * i
        num[i] += 1
        continue
    t = i
    mp = dict()
    while not isprime[t]:
        mp[minp[t]]+=1
        t /= minp[t]
    mp[t]+=1
    for c, d in mp:
        if num[c] < d:
            for z in range(0,d-num[c]):
                lcm = lcm * c
            num[c]=d
for i in range(n-1,0,-1):
    f[i] = lcm/i+1/i
ans = 0
for i in range(n-1,0,-1):
    sum[i] = f[i]*(n-i)+sum[i+1]
    ans=ans+sum[i]
print(ans % mod)
