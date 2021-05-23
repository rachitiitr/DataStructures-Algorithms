unordered_map<int, int> power; // O(1) lookup, O(N) extra space

int get_power(int n) {
    if(n == 1) return 0;
    if(power[n] != 0) return power[n];
    if (n&1) {
        return power[n] = 1 + get_power(3*n + 1);
    }
    else {
        return power[n] = 1 + get_power(n/2);
    }
}

bool cmp(int x, int y) {
    int px = get_power(x);
    int py = get_power(y);
    if (px == py) return x < y;
    return px < py;
}

class Solution {
public:
    // let n: hi-lo
    int getKth(int lo, int hi, int k) {
        // power of 178 -- x steps to reach 380 -- x+z
        // power of 239 -- y steps to reach 380 -- y+z
        // both eventually meet at 380 -- z steps to reach 1
        vector<int> arr; // O(n) extra space
        for(int i = lo; i <= hi; i++) {
            arr.push_back(i);
        }
        sort(arr.begin(), arr.end(), cmp); // O(nlogn) time
        return arr[k-1];
    }
};

/*
- ranges
    - inclusive: [ ]
    - exclusive: ()
    (1, 5) -> 2,3,4
    [1, 5) -> 1,2,3,4


*/
