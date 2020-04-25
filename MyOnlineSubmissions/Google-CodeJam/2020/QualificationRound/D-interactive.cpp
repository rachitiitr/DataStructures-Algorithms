#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d",x)
#define pl(x)	printf("%lld",x)
#define ps(s)	printf("%s",s)
#define pnl()   printf("\n")
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int>	pii;
typedef pair<ll, ll>	pl;
typedef vector<int>		vi;
typedef vector<ll>		vl;
typedef vector<pii>		vpii;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;
int mpow(int base, int exp); 
void ipgraph(int m);
void dfs(int u, int par);
const int mod = 1000000007;
const int N = 130, M = N;
//=======================

template<typename T>
void out(T x) {
    cout << x << endl;
    // cout << flush;
}

int q, si, di, b;
vi arr, same, upd;
int ask(int idx) {
    int x;
    out(idx+1), q++;
    cin >> x;
    return x;
}
void init() {
    q = 0;
    arr = same = {};
    arr.resize(b, -1);
    same.resize(b, 0);
    si = di = -1;
    upd = {0, 0};
}
int main() {
    // ios_base::sync_with_stdio(0);
    int t, i, j, k, p, r, x, y, u, v, m, tt;
    cin >> t >> b;
    fo(tt, t) {
        init();
        fo(i, b/2) {
            if(q%10 == 0 and si != di) {
                if(si==-1 || di==-1) {
                    x = max(di, si);
                    upd[1] = upd[0] = ask(x) ^ arr[x]; //all of same kind so far
                    ask(0); //extra check to maintain even questions
                }
                else {
                    upd[1] = ask(si) ^ arr[si];
                    upd[0] = ask(di) ^ arr[di];
                }
                fo(k, b) arr[k] ^= upd[same[k]];
            }
            j = b-1-i;
            arr[i] = ask(i), arr[j] = ask(j);
            if(arr[i] == arr[j]) si = i, same[i] = same[j] = 1;
            else di = i;
        }
        string ans = "";
        for(int x: arr) ans += x+'0';
        out(ans);
        
        char verdict;
        cin >> verdict;
        assert(verdict == 'Y');
    }
    
    return 0;
}
