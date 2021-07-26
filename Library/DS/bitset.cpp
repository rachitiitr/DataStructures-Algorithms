//http://codeforces.com/contest/707/submission/21781107
//bitset begins
unsigned ll allone = (1LL<<64)-1;
struct node{
	
	// MX = numbers needed in bitmask / 64
	#define MX 16
	int SIZE;
	int extra;
	unsigned ll mask[MX];
	
	node(){
		int i;
		fo(i, MX) mask[i] = 0;
	}
	
	//n is total numbers for which bitset is needed
	void init(int n){
		SIZE = n/64;
		if(n%64) SIZE++;
		extra = (n%64);
		if(!extra) extra = 64;
		int i;
		fo(i, SIZE) mask[i] = 0;
	}
	
	//returns true if bit was earlier off
	bool set(int pos){
		bool res = true;
		int idx = (pos-1)/64;
		int j = (pos-1)%64;
		if (mask[idx]&(1LL<<j)) res = false;
		mask[idx] |= (1LL<<j);
		return res;
	}
	
	//returns true if bit was earlier on
	bool unset(int pos){
		bool res = false;
		int idx = (pos-1)/64;
		int j = (pos-1)%64;
		if (mask[idx]&(1LL<<j)) res = true;
		mask[idx] &= (allone)^(1LL<<j);
		return res;
	}
	
	void complement(int idx){
		if (idx == SIZE-1){
			mask[idx] ^= ((1LL<<extra)-1);
			return;
		}
		mask[idx] ^= allone;
	}
	void complementall(){
		int i;
		fo(i, SIZE) complement(i);
	}
	//returns how many bits are 1
	int ans(){
		int res = 0, i;
		fo(i, SIZE) res += __builtin_popcountll(mask[i]);
		return res;
	}
}bit[N];
//bitset ends
