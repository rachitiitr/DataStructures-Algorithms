# The 5-digit number, 16807=7^5, is also a fifth power. 
# Similarly, the 9-digit number, 134217728=8^9, is a ninth power.
# How many n-digit positive integers exist which are also an nth power?

def digits(x):
    ans = 0
    while x > 0:
        x //= 10
        ans += 1
    return ans

ans = 1 # 1^1 = 1
for k in range(2, 11):
    for p in range(1, 22):
        # check if k^p has p digits
        if digits(pow(k, p)) == p:
            ans += 1
            print(f'{k}^{p} = {pow(k, p)} has {p} digits.')
print(ans)
