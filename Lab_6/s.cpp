#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define ff first
#define ss second
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define CC(x) cout<<"Case " << ++x << ":";
#define nl "\n"
#define LL_INF (1LL << 62)
#define INF (1<<30)
#define SetBit(x,k) (x |= (1LL<<k))
#define ClearBit(x,k) (x &= ~(1LL<<k))
#define CheckBit(x,k) ((x>>k)&1)
#define mod 1000000007
#define N 200005

void solve()
{
    vector<string> v;
    string s, a;
    cin>>a;
    while(1)
    {
        getline(cin, s);
        if (s=="END_OF_TEXT")
            break;
        string x;
        x.clear();
        for (int i = 0; i < s.size(); i++)
        {
            if (x[i]==' ')
            {
                v.push_back(x);
                x.clear();
                continue;
            }
            x.push_back(s[i]);
        }
        v.push_back(x);
    }
    int ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]==a)
        {
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);   cin.tie(0);     cout.tie(0);
    ll t=1;
    cin >> t;
    while (t--)
    solve();
    return 0;
}