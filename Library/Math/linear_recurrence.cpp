//https://www.codechef.com/OCT16/problems/POWSUMS
//linear recurrence -> https://discuss.codechef.com/questions/49614/linear-recurrence-using-cayley-hamilton-theorem

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll long long
#define si(x)	scanf("%d",&x)
#define sl(x)	scanf("%lld",&x)
#define ss(s)	scanf("%s",s)
#define pi(x)	printf("%d\n",x)
#define pl(x)	printf("%lld\n",x)
#define ps(s)	printf("%s\n",s)
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
const int mod = 1e9+7;
const int N = 315;
vi g[N];
int n;
ll p[N], e[N], a[N];
ll tem[N][N], hold[N][N];
//BEGINS
const int MOD = 1e9 + 7;
const long long MOD2 = static_cast<long long>(MOD) * MOD;
const int MAX_K = 50;
vector<vl> C;
vector<vl> M;
ll A[N*2];
struct coef
{
    vl  mat;
    int  n_cols;

    coef() {}

    coef(vl values): mat(values), n_cols(values.size()){}
    
    static coef identity_coef(int n){
        vl res(n, 0);
        res[0] = 1;
        return coef(res);
    }
    coef operator*(const coef &other) const
    {
        int n = other.n_cols, i, j;
        fo(i, 2*n) A[i] = 0;
        fo(i, n)
        fo(j, n){
            ll &ans = A[i+j];
            ans += (mat[i] * other.mat[j])%mod;
            if (ans < 0) ans += mod;
            if (ans >= mod) ans -= mod;
        }
        vl res(n, 0);
        fo(i, n) {
            res[i] += A[i];
            if (res[i] < 0) res[i] += mod;
            if (res[i] >= mod) res[i] -= mod;
        }
        Fo(i, n, 2*n-1){
            ll mul = A[i];
            if (mul){
                fo(j, n){
                    res[j] += (mul*C[i][j])%mod;
                    if (res[j] < 0) res[j] += mod;
                    if (res[j] >= mod) res[j] -= mod;
                }
            }
        }
        return coef(res);
    }
};

// M_powers[i] is M, raised to 2^i-th power
coef M_powers[67];

void precalc_powers()
{
    M_powers[0] = coef(C[1]);
    for(int i = 1; i < 67; i++)
        M_powers[i] = M_powers[i - 1] * M_powers[i - 1];
}

coef mat_pow(ll power)
{
    coef result = coef::identity_coef(M_powers[0].mat.size());
    int pointer = 0;
    while(power) {
        if(power & 1)
            result = result * M_powers[pointer];
        pointer++;
        power >>= 1;
    }
    return result;
}



//ENDS
int mpow(int base, int exp) {
	base %= mod;
	int result = 1;
	while (exp > 0) {
	if (exp & 1) result = ((ll)result * base) % mod;
	base = ((ll)base * base) % mod;
	exp >>= 1;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i,k,j,q;
	ll val,x ;
	int sign;
	int t;
	cin>>t;
	while(t--){
		e[0] = 1;
		cin>>n>>q;
		// fo(i, n) cin>>a[i];
		fo(i, n) cin>>p[i+1];
		e[1] = p[1];
		Fo(i, 2, n+1){
			 val = 0;
			 sign = 1;
			Fo(j, 1, i+1){
				val += (sign*p[j]*e[i-j])%mod;
				if (val < 0) val += mod;
				if (val >= mod) val -= mod;
				sign *= -1;
			}
			val *= mpow(i, mod-2);
			val %= mod;
			e[i] = val;
		}
		M.resize(n, vl(n, 0));
		C.resize(2*n-1, vl(n, 0));
		//build matrix
		sign = 1;
		//construct 1st row of M
		M[0][0] = 1;
		fo(i, n)
			// M[1][i] = a[i];
			M[1][i] = sign*e[i+1], sign *= -1;
        //construct rows of M^2, M^3, .. M^{n-1}
		Fo(i, 2, n){
            fo(j, n){
                //M[i][j] = ?
                int pre = 0;
                if(j!=n-1) pre = M[i-1][j+1];
                ll &ans = M[i][j];
                ans = (M[i-1][0]*M[1][j] + pre)%mod;
                if (ans < 0) ans += mod;
            }
		}
		//find coefficients of M^i as C[i][0...n-1]  M^i = sum(C[i][j]*M^j)
		//i from [0, n)
		fo(i, n) fo(j, n) C[i][j] = 0;
		fo(i, n) C[i][i] = 1;
		//set for M^n -> use characteristic
		fo(i, n)
            C[n][n-1-i] = (mod+M[1][i])%mod;
		
		//i from [n+1, 2n-2]
		Fo(i, n+1, 2*n-1){
            C[i][0] = (C[i-1][n-1]*C[n][0])%mod;
            if(C[i][0] < 0) C[i][0] += mod;
            Fo(j, 1, n){
                ll &ans = C[i][j];
                ans = (C[i-1][n-1]*C[n][j] + C[i-1][j-1])%mod;
                if (ans < 0) ans += mod;
            }
		}
		
		//matrix M(mat);
		precalc_powers();
		//answer queries
		ll mx = 0;
		while(q--) {
			cin>>x;
			x -= n;
			
			//mat^x
			// fo(i, n) fo(j, n) M[i][j] = mat[i][j];
			coef res = mat_pow(x);
			// fo(i, n) cout<<res.mat[n-1-i]<<" ";
			// cout<<endl;
			val = 0;
			fo(i, n) A[i] = 0;
			fo(i, n){
			    ll mul = res.mat[i];
			    if (mul){
                    fo(j, n){
                        A[j] += (M[i][j]*mul)%mod;
                        if (A[j] >= mod) A[j] -= mod;
                        if (A[j] < 0) A[j] += mod;
                    }
			    }
			}
			//A[i] * p[n-i]
			fo(i, n) {
                val += (A[i]*p[n-i])%mod;
                if (val >= mod) val -= mod;
                if (val < 0) val += mod;
			}
			cout<<val<<" ";
		}
		fo(i, n+1) e[i] = 0;
		cout<<endl;
	}

	return 0;
}

