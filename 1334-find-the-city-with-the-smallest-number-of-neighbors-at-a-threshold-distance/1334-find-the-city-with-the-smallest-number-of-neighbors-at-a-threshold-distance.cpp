#define pb push_back
using ll = long long;
using p_ll = pair<ll,ll>;
using p_q = priority_queue<p_ll,vector<p_ll>,greater<p_ll>>;

class Solution {

public:
    int dijkstra(int u, int n, vector<p_ll> adj[], ll tar){
        vector<ll> dist(n,1e18);
        dist[u] = 0;
        p_q q;
        q.push({dist[u], u});
        while(!q.empty()){
            ll distance_so_far = q.top().first,
               u = q.top().second;
            q.pop();
            if(distance_so_far > dist[u]) continue;
            for(auto [v,d] : adj[u]){
                if(dist[v] > distance_so_far + d ){
                    dist[v] = distance_so_far + d;
                    q.push({dist[v],v});
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(i!=u && dist[i]<=tar) cnt++;
        }
        return cnt;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // adj list
        vector<p_ll> adj[n];
        for(int i=0; i<size(edges); i++){
            ll u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            adj[u].pb({v,wt});
            adj[v].pb({u,wt});
        }
        ll given_dist = distanceThreshold*1ll;
        int res = -1, mini= INT_MAX;
        for(int i=0; i<n; i++){
           int val = dijkstra(i,n,adj,given_dist);
        if(val<=mini) mini = val,res = i;
        }
        return res;
    }
};