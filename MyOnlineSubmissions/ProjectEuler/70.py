# Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.
# Find the value of n, 1 < n < 10^7, for which φ(n) is a permutation of n and the ratio n/φ(n) produces a minimum.
N = 10**7
rat = N + 1
ans = -1

def same(x, y):
    return sorted(str(x)) == sorted(str(y))

def euler_phi(MAX=N+1):
    phi = [0 for _ in range(MAX+1)]
    phi[1] = 1
    for i in range(2, MAX+1):
        if not phi[i]:
            phi[i] = i-1
            for j in range((i<<1), MAX+1, i):
                if not phi[j]:
                    phi[j] = j
                phi[j] = (phi[j]//i) * (i-1)
    return phi
            
phi = euler_phi()

for n in range(2, N + 1):
    p = phi[n]
    if same(p, n):
        print(n, p)
        if rat > n/p:
            rat = n/p
            ans = n

print(ans)
