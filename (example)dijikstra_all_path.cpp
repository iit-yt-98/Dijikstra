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






ll n,m,k;                                                                                                //dijikstra

vector<vector<ll>> d;
vector<vector<ll>> routes;

vector<vector<pair<ll , ll>>> adj;


void dijikstra(int x){
    set<pii> s;

    d[x][x] = 0;

    s.insert({0 , x});

    while(!s.empty()){
        int v = s.begin()->second;
        s.erase(s.begin());

        for(auto &nb : adj[v]){
            int w = nb.second;
            int to = nb.first;

            if(d[x][v] + w < d[x][to] ){
                s.erase({d[x][to] , to });
                d[x][to] = d[x][v] + w;
                s.insert({d[x][to] , to});
            }
        }
    }
}








void solve(){    
    
    cin>>n>>m>>k;
    adj.resize(n+1);

    vector<vector<ll>> edge;

    loop(i,0,m){
        int x,y,w;
        cin>>x>>y>>w;
        edge.pb({x,y});
        adj[x].pb({y,w});
        adj[y].pb({x,w});
    }

    d.assign(n+1 , vector<ll>(n+1 , inf));

    loop(i,1,n+1){
        dijikstra(i);
    }

    routes.assign(k , vector<ll>(2));

    for(auto &v : routes){
        cin>>v[0]>>v[1];
    }

    cout<<d[0][3]<<d[1][3]<<Endl;  // distance from 0 to 3 and 1 to 3 
    

  

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
