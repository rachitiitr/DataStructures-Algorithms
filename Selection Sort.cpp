#include <iostream>
#include <bits/stdc++.h>
#define int  long long
using namespace std;

int min(int A[],int k,int N){
    int j,LOC,MIN;
    MIN=A[k];
    LOC=k;
    for(j=k+1;j<=N;j++)
    if(MIN>A[j])
    {  MIN=A[j];
       LOC=j;
     }

     return (LOC);
}

int32_t main(){
    int n; cin>>n;
	int A[n];
	for(int i=0;i<n;i++)  cin>>A[i];
    int LOC,k,temp;

    for(k=0;k<n-1;k++){
        LOC=min(A,k,n);
        swap(A[k],A[LOC]);

    }

    for(k=0;k<n;k++){
        cout<<A[k]<<endl;

    }

}