// C++ program to find prime factorization of a
// number n in O(Log n) time with precomputation
// allowed.
#include "bits/stdc++.h"
using namespace std;
void chinese(int &a1, int &m1, int a2, int m2) ;
#define MAXN 100001

// stores smallest prime factor for every number
int spf[MAXN];

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)

        // marking smallest prime factor for every
        // number to be itself.
        spf[i] = i;

    // separately marking spf for every even
    // number as 2
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        // checking if i is prime
        if (spf[i] == i)
        {
            // marking SPF for all numbers divisible by i
            for (int j=i*i; j<MAXN; j+=i)

                // marking spf[j] if it is not
                // previously marked
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}


int nCrModpDP(int n, int r, int p)
{
    // The array C is going to store last row of
    // pascal triangle at the end. And last entry
    // of last row is nCr
    int C[r+1];
    memset(C, 0, sizeof(C));

    C[0] = 1; // Top row of Pascal Triangle

    // One by constructs remaining rows of Pascal
    // Triangle from top to bottom
    for (int i = 1; i <= n; i++)
    {
        // Fill entries of current row using previous
        // row values
        for (int j = min(i, r); j > 0; j--)

            // nCj = (n-1)Cj + (n-1)C(j-1);
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}

// Lucas Theorem based function that returns nCr % p
// This function works like decimal to binary conversion
// recursive function.  First we compute last digits of
// n and r in base p, then recur for remaining digits
int nCrModpLucas(int n, int r, int p)
{
    // Base case
    if (r==0)
        return 1;

    // Compute last digits of n and r in base p
    int ni = n%p, ri = r%p;

    // Compute result for last digits computed above, and
    // for remaining digits.  Multiply the two results and
    // compute the result of multiplication in modulo p.
    return (nCrModpLucas(n/p, r/p, p) * // Last digits of n and r
            nCrModpDP(ni, ri, p)) % p;  // Remaining digits
}


int gcdExtended(int a, int b, int *x, int *y);

// Function to find modulo inverse of a
int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
       // cout << "Modular multiplicative inverse is " << res;
        return res ;
    }
}

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;

    return gcd;
}

void chinese(int &a1, int &m1, int a2, int m2) {
    int m = m1 * m2 ;

    a1 =  (a1 * modInverse(m2, m1) % m1 * m2 + a2 * modInverse(m1, m2) % m2 * m1) % m ;
     m1 =  m1*m2;
}


// driver program for above function
int main(int argc, char const *argv[])
{
    // precalculating Smallest Prime Factor
    sieve();

    int n ,r,p;
    int testcases ;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin>>testcases ;

    while(testcases--) {
        cin >> n >> r >> p;

        // calling getFactorization function
        vector<int> pp = getFactorization(p);

        int ans = 0, mod = 1;

        for (int i = 0; i < pp.size(); i++) {
            cout << pp[i] << " ";
            chinese(ans, mod, nCrModpLucas(n, r, pp[i]), pp[i]);
        }

        cout<<ans << endl;
    }

    return 0;
}


