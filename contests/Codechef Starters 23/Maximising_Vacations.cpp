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
    ll n, x;
    input(n, x);
    string s;
    cin>>s;
    vector<int> vacations(n+1), nextPositionOfone(n+1);
    int positionOne = n, cntzero=0, vac=0;
    for(int i=n-1;i>=0;i--)
    {
        nextPositionOfone[i] = positionOne;
        if(s[i]=='1')
        {
            cntzero = 0;
            positionOne=i;
        }
        else
        {
            cntzero++;
            if(cntzero==x)
            {
                vac++;
                cntzero=0;   
            }
        }
        vacations[i] = vac;
    }
    int res = vac;
    vac = cntzero = 0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            if(nextPositionOfone[i]> i+ (x - 1 - cntzero)) res = max(res, vac + vacations[i + x - cntzero]+1);
            cntzero = 0;
        }
         else
        {
            cntzero++;
            if(cntzero==x)
            {
                vac++;
                cntzero=0;   
            }
        }
    }
    cout<<res<<endl;

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