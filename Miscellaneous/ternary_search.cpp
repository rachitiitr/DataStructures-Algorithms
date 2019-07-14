double f(double x){
	double ans = T(dis(x1,Y1, x,0), v1);
	 ans += T(dis(x2,y2, x,0), v2);
	 return ans;
}
double ter(double lo, double hi, int iter = 0){
	if (iter == 300) return lo;
	double m1 = lo + (hi-lo)/3;
	double m2 = hi - (hi-lo)/3;
	if (f(m1) > f(m2)) return ter(m1, hi, iter+1);
	else return ter(lo, m2, iter+1);
}
