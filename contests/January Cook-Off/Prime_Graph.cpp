/** Solution By khemchand5487 **/

#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define debug(x) cout << #x <<" "; _print(x); cout << endl;

typedef long long ll;

//for debugging
template <class T>
void _print(T t) {cout << t;}

template <class T, class V> void _print(pair <T, V> p) {cout << "{"; _print(p.first); cout << ","; _print(p.second); cout << "}" << endl;}
template <class T> void _print(vector <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T> void _print(set <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T> void _print(multiset <T> v) {cout << "[ "; for (T i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T, class V> void _print(map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]" << endl;}
template <class T, class V> void _print(unordered_map <T, V> v) {cout << "[ "; for (auto i : v) {_print(i); cout << " ";} cout << "]" << endl;}
//END

//reading input 
template<typename... T>
void input(T&... args) {(((cin>>args), ...));}

//writing output
template<typename... T>
void output(T... args) {(((cout<<args<<" "), ...));  cout<<endl;}

////////solution goes here////////

vector<int> primes;
 
// Utility function of Sieve of Sundaram
void Sieve()
{
    int n = 200010;
 
    int nNew = sqrt(n);
 
    int marked[n/2+500] = {0};

    for (int i=1; i<=(nNew-1)/2; i++)
        for (int j=(i*(i+1))<<1; j<=n/2; j=j+2*i+1)
            marked[j] = 1;

    primes.push_back(2);
 
    for (int i=1; i<=n/2; i++)
        if (marked[i] == 0)
            primes.push_back(2*i + 1);
}

void solve()
{
    int n;
    cin>>n;
    int idx = lower_bound(all(primes), n-1) - primes.begin();

    if(primes[idx] > n-1) idx--;
    
    ll sum =0, maxSum = (ll)n * (ll)primes[idx];
    ll remaining = n;
    for(int i = idx;i>=0;i--)
    {
        ll coef = min(remaining, maxSum/primes[i]);
        if(i > 0 &&( coef & 1)) coef--;
        sum += primes[i]*coef;
        maxSum -=  primes[i]*coef;
        remaining -= coef;
    }
    cout<<(sum/2)<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin>>t;
    Sieve();
    while(t--)
    {
        solve();
    }

    return 0;
}

/** Solution By khemchand5487 **/