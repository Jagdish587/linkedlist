#include <bits/stdc++.h>
using namespace std;
//example of lucas theorm for prime MOD
// https://www.hackerearth.com/practice/notes/ncr-mod-mod-lucas-theorem/
// https://www.hackerearth.com/practice/notes/lucas-theorem-wilsons-theorem/
#define MOD 5

vector<int> getRepresentation(int N) {
    vector<int> res;
    while (N > 0) {
        res.push_back(N % MOD);
        N /= MOD;
    }
    return res;
}

int fact(int n) {
    if ( n == 0)
        return 1;
    else
        return n * fact(n-1);
}

int computencr(int n,int r) {
    int num = fact(n);
    int denom = fact(n-r) * fact(r) ;

    return num/denom ;
}

int main() {

    vector<int> n = getRepresentation(588);
    vector<int> k = getRepresentation(277);

    long long res = 1;

        for (int i = 0; i < k.size(); ++i) {
            res =( res * computencr(n[i],k[i]) ) % MOD;
        }

      //  cout<<" 4 choose 2 ="<<computencr(3,2)<<endl;
        cout<<"res = "<<res<<endl;

        return 0;

}