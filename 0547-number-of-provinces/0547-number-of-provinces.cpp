class Solution {
public:
    void solve(int node, vector<vector<int>>& isConnected, vector<bool>& vis) {
    
    vis[node] = true;
    
    for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
        if (isConnected[node][neighbor] == 1 && !vis[neighbor]) {
            solve(neighbor, isConnected, vis);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<bool> vis(n, false);
    int res = 0;
    
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            solve(i, isConnected, vis);
            res++; 
        }
    }
    return res;
}
};