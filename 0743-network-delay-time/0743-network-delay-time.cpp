using p_i = pair<int,int>;

class Solution {
public:
    int dijkstra(int node,vector<p_i> adj[], int n){
      vector<int> dist(n,INT_MAX);
      dist[node] = 0;
      priority_queue<p_i, vector<p_i>,greater<p_i>> q;
      q.push({dist[node],node});
      while(!q.empty()){
        auto [distance_so_far, popped_node] = q.top();q.pop();
        if(distance_so_far != dist[popped_node]) continue;
        for(auto child : adj[popped_node]){
          int new_node  = child.first;
          int added_dist = child.second;
          if(dist[new_node] > distance_so_far + added_dist){
            dist[new_node] = distance_so_far + added_dist;
            q.push({dist[new_node],new_node});
          }
        }
      }
      int maxTime = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    } 
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<p_i> adj[n];
        for(int i=0; i<size(times); i++) {
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            u--;
            v--;
            adj[u].push_back({v,w});
        }
      k--;
      return  dijkstra(k,adj,n);
    }
};