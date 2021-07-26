import math

def countMultiples(x, a, b):
    '''returns # of multiples of a or b in range [1, x]'''
    lcm = a * b // math.gcd(a, b)
    return x//a + x//b - x//lcm # x/2 + x/3 - x/6
    
class Solution:
    def nthMagicalNumber(self, n: int, a: int, b: int) -> int:
        # a = 2, b = 3 in our case
        lo, hi = 1, min(a, b) * n # hi = 2*n remember?
        while lo < hi:
            mid = (lo + hi) >> 1
            if countMultiples(mid, a, b) < n:
                lo = mid + 1
            else:
                hi = mid
                
        return hi % (10**9 + 7)
        
