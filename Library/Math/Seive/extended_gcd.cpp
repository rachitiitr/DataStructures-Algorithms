//used in solving linear congruences a*x = b (mod n)
// x = extended_gcd(a, n).F * b % n
// if x < 0: x += n
//CONDITION: gcd(a, n) = 1
typedef ll var;
pair<var, var> extended_gcd(var a, var b){
	bool swp = 0;
	if (a<b) swap(a, b), swp = 1;
	//1 = N*a + M*b
	//returns {N, M}
	vector<var> K;
	var k, r, FF, SS;
	while(1){
		k = a/b;
		r = a - k*b;
		if(r == 1){
			FF = 1, SS = -k;
			reverse(all(K));
			for(int k: K){
				var tem = FF;
				FF = SS;
				SS = tem - SS * k;
			}
			return swp?mp(SS, FF):mp(FF, SS);
		}
		else{
			K.pb(k);
		}
		a = b;
		b = r;
	}
}
var solve(var a, var b, var n){
	pair<var, var> ans = extended_gcd(a, n);
	var x = ( ans.F * b ) % n;
	if ( x < 0)
		x += n;
	
	//a*x is b (mod n)
	return x;
	
}
