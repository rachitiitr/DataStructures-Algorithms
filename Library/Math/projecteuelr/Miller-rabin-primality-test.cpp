#include<iostream>
using namespace std;

typedef long long ll;
 
int T;
ll mod;
int b[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
ll a[]={1996011519951206ll,1995120619960115ll,1995100319960115ll,195100319951206ll,1996011519951003ll};
 
 
ll multi(ll x,ll y)
{
	ll w=x*y-mod*(ll(double(x)*y/mod+1e-3));
	while(w<0)
		w+=mod;
	while(w>=mod)
		w-=mod;
	return w;
}
 
ll pow(ll x,ll y)
{
	ll t=1;
	while(y)
	{
		if(y&1)
			t=multi(t,x);
		x=multi(x,x);
		y>>=1;
	}
	return t;
}
 
bool judge(ll n)
{
	if(n==2) return true;
	if(n<2||!(n&1)) return false;
	for(int i=0;i<25;i++)
		if(n%b[i]==0&&n!=b[i])
			return false;
	mod=n;
	int t=0;
	ll u=n-1;
	while(!(u&1)) t++,u>>=1;
	for(int i=0;i<5;i++)
	{
		ll x=a[i]%(n-1)+1;
		x=pow(x,u);
		ll y=x;
		for(int j=1;j<=t;j++)
		{
			x=multi(x,x);
			if(x==1&&y!=1&&y!=n-1)
				return false;
			y=x;
		}
		if(x!=1) return false;
	}
	return true;
}
 
int main()
{
	// judge(n) check whether a number is prime or not
//	ll n,lower,upper,count=0,numcount=0;
//	lower=3; upper=19;
//	for(n=lower;n<=upper;n=n+4)
//	{
//	if(judge(n)) cout<<n<<endl;}
//	cout<<count<<endl;
//	return 0;

	for(int x=18;x<30;x++){
		if(judge(((1<<x)|1))) cout<<"mil";
	}

} 
