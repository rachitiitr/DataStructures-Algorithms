// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



void rotateArr(int arr[], int d, int n){
    
    
    // HINT ->
    // reverse(a, a+d) Reverse array from beginning till D
    // reverse(a+d, a+n) Reverse array from D till N
    // reverse(a, a+n) Reverse the whole array
    
  int l=0;
  int r=d-1;
  while(l<r){
      int t=arr[l];
      arr[l]=arr[r];
      arr[r]=t;
      l++;
      r--;
      
  }
  int l1=d;
  
  int r1=n-1;
   while(l1<r1){
       int t=arr[l1];
      arr[l1]=arr[r1];
      arr[r1]=t;
      l1++;
      r1--;
       
   }
   
   int l2=0;
   int r2=n-1;
   while(l2<r2){
       int t=arr[l2];
      arr[l2]=arr[r2];
      arr[r2]=t;
      l2++;
      r2--;
       
   }
    
  
}




// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n, d;
	    cin >> n >> d;
	    
	    int arr[n];
	    
	    for(int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    rotateArr(arr, d,n);
	    
	    for(int i =0;i<n;i++){
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	}
	return 0;
}  // } Driver Code Ends