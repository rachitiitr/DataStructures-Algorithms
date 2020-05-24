#include<bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;

int mpow(int base, int exp) {
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((long long)result * base) % mod;
    base = ((long long)base * base) % mod;
    exp >>= 1;
  }
  return result;
}

namespace NcR {
    int fact[200005],ifact[200005];
    int get(int n, int r) {
        if(n<r||r<0||n<0) return 0;
        return (((fact[n]*1LL*ifact[r])%mod)*1LL*ifact[n-r])%mod;
    }

    void init() {
        fact[0]=1;
        for(int i = 1; i <= 200000; i++) {
            fact[i] = (fact[i-1] * 1LL * i)%mod;
        }

        ifact[200000] = mpow(fact[200000], mod-2);
        for(int i=199999; i>=0; i--) {
            ifact[i] = (ifact[i+1] * 1LL * (i+1))%mod;
        }
    }
};

int main() {

    NcR::init();
    cout << NcR::get(4, 2) << endl;
    return 0;
}