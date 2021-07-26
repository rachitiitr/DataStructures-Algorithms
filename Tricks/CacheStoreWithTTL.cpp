#include <bits/stdc++.h>
using namespace std;

int getCurrentTimeStamp(){
	return 0; //assume this is a system function that returns the current timestamp	
}

//Implement a CacheStore that can store key values with some TTL info as well
template <typename K, typename V>
class CacheStore
{
	//mapping key to value as well as a timestamp till its valid
	unordered_map<K, pair<V, int>> _mep;
	public:
	void Add(K key, V value, int ttl) {
		if(_mep.find(key) == _mep.end()) {
			int expirationTime = getCurrentTimeStamp() + ttl;
			_mep[key] = {value, expirationTime};
		}
		else {
			//depends on business logic how to handle this case
			//one approach is we can overwrite the value
		}
	}
	
	//returns true if key existed and also alive
	bool Get(K key, V* out) {
		int currentTime = getCurrentTimeStamp();
		if(_mep.find(key) == _mep.end()) {
			out = NULL;
			return 0;
		}
		else {
			pair<V, int> cur = _mep[key];
			if (cur.second < currentTime) {
				//expired
				out = NULL;
				return 0;
			}
			else {
				*out = cur.first;
				return 1;
			}
		}
	}
};

int main() {
	CacheStore<string, int> M;
	M.Add("rachit", 1, 10);
	M.Add("Uber", 2, 100);
	int* res = new int;
	if(M.Get("rachit", res)) cout << *res << endl;
	if(M.Get("Uber", res)) cout << *res << endl;
	
	return 0;
}
