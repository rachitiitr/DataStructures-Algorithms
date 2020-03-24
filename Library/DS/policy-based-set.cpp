#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_mset;
//ENDS

int t = 0;

int main()
{
	
	int x = 1;
	ordered_mset me;
	me.insert({x, t++});
	// me.erase(me.lower_bound({x, 0}));
	cout << me.order_of_key({x, 0}) << "\n";


	ordered_set A;
	A.insert(1);
	A.insert(2);
	A.insert(10);
	A.insert(100);
	//how many numbers are smaller than it
	cout<<A.order_of_key(1)<<endl;
	cout<<A.order_of_key(2)<<endl;
	
	//find the ith number	
	cout<<*A.find_by_order(1)<<endl;
	cout<<*A.find_by_order(2)<<endl;
	

	return 0;
} 


