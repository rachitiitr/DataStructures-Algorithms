//Problem Link: https://codingcompetitions.withgoogle.com/codejam/round/0000000000051705/00000000000881da
#include <iostream>
using namespace std;
int main()
{
    int t,n;
    cin >> t;
    for(int ii = 0; ii < t; ii++){
        cout << "Case #" << 1+ii << ": ";
        string s;
        cin >> n;
        cin >> s;
        for(char c: s) {
            char p = 'S';
            if (c == p)
                p = 'E';
            cout << p;
        }
        cout << endl;
    }

}
