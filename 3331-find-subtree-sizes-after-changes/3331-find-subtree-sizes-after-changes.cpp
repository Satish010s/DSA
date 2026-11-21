class Solution {

private:
    void findNewParent(int u, string &s,vector<vector<int>>&adj, vector<int>&new_parent, vector<int>&last_seen){
        int char_idx=s[u]-'a';
        if(last_seen[char_idx]!=-1){
            new_parent[u]=last_seen[char_idx];
        }
        int prev_ancestor=last_seen[char_idx];
        last_seen[char_idx]=u;

        for(int v:adj[u]){
            findNewParent(v,s,adj,new_parent,last_seen);
        }
        last_seen[char_idx]=prev_ancestor;
    }

    int getSubtreeSize(int u,vector<vector<int>>&new_adj,vector<int>&ans){
        int size=1;
        for(int v:new_adj[u]){
          size+=getSubtreeSize(v,new_adj,ans);
        }
        ans[u]=size;
        return size;
    }
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();

        // adejencency list for node 
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        vector<int>new_parent=parent;
        vector<int>last_seen(26,-1);

        findNewParent(0,s,adj,new_parent,last_seen);

         vector<vector<int>>new_adj(n);
        for(int i=1;i<n;i++){
            new_adj[new_parent[i]].push_back(i);
        }
        vector<int>ans(n,0);
        getSubtreeSize(0,new_adj,ans);
        return ans;
    }
};