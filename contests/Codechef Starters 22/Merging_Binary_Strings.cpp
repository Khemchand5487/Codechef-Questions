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
void solve()
{
    ll n;cin>>n;
    string a,b;cin>>a>>b;
    vector <ll> p(n+1,0),p1(n+1,0);
    ll util[n+1][n+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        util[i][j]=1e18;
    }
    util[n][n]=0;
    for(int i=n-1;i>=0;i--)
    {
        p[i]=p[i+1]+(a[i]=='0');
        p1[i]=p1[i+1]+(b[i]=='0');
    }
    for(int i=n-1;i>=0;i--)
    {
        util[n][i]=util[n][i+1];
        if(b[i]=='1')
        util[n][i]+=p[n]+p1[i];
    }
    for(int i=n-1;i>=0;i--)
    {
        util[i][n]=util[i+1][n];
        if(a[i]=='1')
        util[i][n]+=p[i]+p1[n];
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(a[i]=='0' && b[j]=='0')
            {
                util[i][j]=min(util[i][j],util[i+1][j]);
                util[i][j]=min(util[i][j],util[i][j+1]);
            }
            else if(a[i]=='0' && b[j]=='1')
            {
                util[i][j]=min(util[i][j],util[i+1][j]);
                util[i][j]=min(util[i][j],util[i][j+1]+p[i]+p1[j]);
            }
            else if(a[i]=='1' && b[j]=='0')
            {
                util[i][j]=min(util[i][j],util[i][j+1]);
                util[i][j]=min(util[i][j],util[i+1][j]+p[i]+p1[j]);
            }
            else
            {
                util[i][j]=min(util[i][j],util[i+1][j]+p[i]+p1[j]);
                util[i][j]=min(util[i][j],util[i][j+1]+p[i]+p1[j]);
            }
        }
    }
    cout<<util[0][0]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}

/** Solution By khemchand5487 **/