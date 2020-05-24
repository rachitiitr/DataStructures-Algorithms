#include<bits/stdc++.h>
using namespace std;


typedef long long HashInt;
static const HashInt HASH_MOD = 2'000'000'033;
struct ModBasedHashInt {
	HashInt x; ModBasedHashInt(HashInt x=0) : x(x) {}
	ModBasedHashInt operator+(ModBasedHashInt o) { 
        HashInt y = x + o.x; 
        return y - (y >= HASH_MOD) * HASH_MOD; 
    }
	ModBasedHashInt operator*(ModBasedHashInt o) { return x*o.x % HASH_MOD; }
	HashInt operator-(ModBasedHashInt o) { 
        HashInt y = x - o.x; 
        return y + (y < 0) * HASH_MOD; 
    }
};
struct RollingHash {
    #define sz(x) ((int)x.size())
	vector<ModBasedHashInt> hash, power;
	HashInt C;
	RollingHash(string& str, HashInt Co) : hash(sz(str)+1, 0), power(hash) {
		C = Co;
		power[0] = 1;
		for(int i=0; i<sz(str); i++) {
			hash[i+1] = hash[i] * C + str[i];
			power[i+1] = power[i] * C;
        }
	}

	HashInt get(int l, int r) { // hash [l, r)
		return hash[r] - hash[l] * power[r - l];
	}
};