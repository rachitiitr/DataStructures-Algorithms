#include <bits/stdc++.h>
using namespace std;
struct PT{
	double x, y;
	PT(){}
	PT(int a, int b){
		x = a, y = b;
	}
	PT unit(){
		return PT(x/mag(), y/mag());
	}
	double mag(){
		return sqrt(x*x+y*y);
	}
};
//returns dot product
double operator*(PT &a, PT &b){
	return a.x*b.x + a.y*b.y; 
}
#define PI 3.1415926535897932384626
double ang(PT &a, PT &b){
	double c0 = (a*b)/(a.mag()*b.mag());
	return acos(c0)*180/PI;
}

int main() {
	// your code goes here
	PT a(1, 0);
	PT b(-2, 2);
	cout<<ang(a, b)<<endl;
	
	return 0;
}
