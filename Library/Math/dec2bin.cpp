//the bit size
#define szz 17
void go(ll no, vector<int> &a){
	a.clear();
	while(no){
		a.push_back(no%2);
		no /= 2;
	}
	int left = szz-a.size();
	while(left--) a.pb(0);
	//If you uncomment the following  10 will become -> 00000000000001010
	// reverse(a.begin(), a.end());
}
