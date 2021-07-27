#include <bits/stdc++.h>  
#define ll long long int
#define llu unsigned long long int
#define lld long double
#define endl '\n'
#define Endl '\n'


#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define pb push_back
#define SZ(x) ((int)x.size())
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define pii             pair<ll,ll>
#define mii             map<int,int>
#define pq             priority_queue<int>
#define inf             1e15
#define mod             1e9+7



#define all(a) a.begin(),a.end()  


using namespace std;







void dijikstra(ll x , vector<ll> &d , vector<vector<ll>> &adj , ll w){
 
    set<pii> s;
 
    d[x] = 0;
 
    s.insert({0 , x});
 
    while(!s.empty()){
        int v = s.begin()->second;
        s.erase(s.begin());
 
        for(auto &nb : adj[v]){
            //ll w = nb.second;
            ll to = nb;
 
            if(d[v] + w < d[to] ){
                s.erase({d[to] , to });
                d[to] = d[v] + w;
                s.insert({d[to] , to});
            }
        }
    }
}








void solve(){    
    
    ll n,m;
    cin>>n>>m;

    ll weight ;
    cin>>weight;
 
    ll F , T; //from to
 
    vector<vector<ll>> adj;
 
    adj.resize(n+1);
 
 
    loop(i,0,m){
        cin>>F>>T;
        adj[F].pb(T);
        adj[T].pb(F);
    }
 
    
 
    vector<ll> d(n+1 , 1e11);
 
    
    
    dijikstra(1 , d , adj , weight); 
    
 
    ll ans = 1e9;
 
    loop(i,1,n+1){
        //cout<<d1[1][i]<<" "<<d2[2][i]<<" "<<d3[i][n]<<endl;
        ans = min(ans , d[i]); 
    }
 
    cout<<ans<<Endl;

}




int32_t main()
{


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    loop(i,0,t)
    solve();
    

    return 0;
}
