//normal round means 2.345 -> 2.35 and not 2.34 as in scientific
void out(double x, int n){
	cout<<fixed<<setprecision(n)<<x<<endl;
}
void R(double d, int n) {
	double original = d;
	ll factor = 100000;
	ll scaled_and_rounded = (ll)(original * factor + 0.5);
	double rounded = (double)scaled_and_rounded / factor;
	out(rounded, n);
	return;
    
} 
