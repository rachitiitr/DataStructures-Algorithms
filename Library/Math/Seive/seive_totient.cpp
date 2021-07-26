//prime[i] is smallest prime that divides i
vector<ll> primes;
const int NN = 1e6+1;
int prime[NN];
void seive(){
    ll i;
    Fo(i, 1, NN) prime[i] = i;
    prime[0] = prime[1] = 0;
    for(i=2; i < NN; i++){
        if (prime[i] == i){
           
            for(ll j = 2*i; j < NN; j += i)
                if (prime[j] == j)
                    prime[j] = i;
        }
    }
   for(i=2; i<NN; i++) if(prime[i]==i) primes.pb(i);
}
int phi(int n){
    int n1, n2;
    n2 = n; n1 = 1;
    int i = 0;
    while(i<(int)primes.size() and  primes[i]*primes[i] <= n){
        if (n % primes[i] == 0){
            while(n % primes[i] == 0) n /= primes[i];
            n2 /= primes[i];
            n1 *= primes[i]-1;
        }
        i++;
    }
    if (n>1){
        n2 /= n;
        n1 *= n-1;
    }
    return n1*n2;
}
