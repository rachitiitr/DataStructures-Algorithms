// Video Explanation at https://www.youtube.com/watch?v=-F7cHQ-gWS4
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll f(ll &x, ll &y, ll &z) {
    return (x&z) * (y&z);
}

class Bit{
    ll x;
    int _bits; // we need only these many bits, in this case 40
    
    #define mask(b) (1LL<<(_bits-b)) // remember 0th bit is actually 39th bit
public:
    Bit() {}
    
    Bit(ll &y, int bits=40) { 
        init(y, bits);
    }

    void init(ll &y, int bits=40) {
        x = y;
        _bits = bits-1;
    }
    
    bool get(int &b) {
        return (x & mask(b)) != 0;
    }

    void set(int &b) {
        x |= mask(b);
    }

    void reset(int &b) {
        if(get(b))
            x ^= mask(b);
    }

    void set(int &b,int k) {
        if(k == 1) {
            set(b);
        }
        else {
            reset(b);
        }
    }

    ll toInt() {
        return x;
    }
} bitX, bitY;

vector<ll> getValidZValues(ll &L, ll &R) {
    vector<ll> Zcandidates = {L, R}; // L and R are always valid Z values we should handle
    Bit bitL(L);
    Bit bitR(R);
    int k = 0;
    while(k<40 and bitL.get(k) == bitR.get(k)) k++;

    for(int l = k+1; l < 40; l++) {
        if(bitL.get(l) != 0) continue;
        Bit z(L);
        z.set(l);
        for(int i=l+1; i<40; i++) {
            if(bitX.get(i) == 0 and bitY.get(i) == 0) {
                z.set(i, 0); // minimize Z
            }
            else {
                z.set(i, 1); // maximize F(X,Y,Z)
            }
        }
        Zcandidates.push_back(z.toInt());
    }
    for(int r = k+1; r < 40; r++) {
        if(bitR.get(r) != 1) continue;
        Bit z(R);
        z.reset(r);
        for(int i=r+1; i<40; i++) {
            if(bitX.get(i) == 0 and bitY.get(i) == 0) {
                z.set(i, 0);
            }
            else {
                z.set(i, 1);
            }
        }
        Zcandidates.push_back(z.toInt());
    }

    sort(Zcandidates.begin(), Zcandidates.end());
    return Zcandidates;
}

int main() {
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;

    while(t--) {
        ll x, y, l, r;
        cin >> x >> y >> l >> r;

        bitX.init(x);
        bitY.init(y);

        vector<ll> Zcandidates = getValidZValues(l, r);

        ll mx = -1, ans = r;
        for(ll z: Zcandidates) {
            ll currentF = f(x, y, z);
            if(currentF > mx) {
                mx = currentF;
                ans = z;
            }
        }

        cout << ans << endl;
    }
    
    return 0;
}
