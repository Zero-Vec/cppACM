mod = 998244353
n = int(input())
a = input()
b = input()
a1 = ""
b1 = ""
for i in range(0, n):
    mn = min(a[i], b[i])
    mx = max(a[i], b[i])
    a1 += mn
    b1 += mx
a1 = int(a1)
b1 = int(b1)
print(a1 * b1 % mod)
