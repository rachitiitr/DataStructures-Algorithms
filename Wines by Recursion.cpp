#include<bits/stdc++.h>
#include <climits>
using namespace std;

int profit(int wines[],int i,int j,int y){
    // Base Case
    if(i>j)
    return 0;

    // Recursive Case
    int opt1= wines[i]*y + profit(wines,i+1,j,y+1);
    int opt2= wines[j]*y + profit(wines,i,j-1,y+1);
    return max(opt1,opt2);

}


int main(){
   
    int wines[]={2,3};
    int n =sizeof(wines)/sizeof(int);
    int y=1;
    cout<<profit(wines,0,n-1,y);


}