//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void dfs(int src,vector<int>ADJ[],vector<int>&vis){
        vis[src]=1;
        for(auto it:ADJ[src]){
            if(!vis[it]){
                dfs(it,ADJ,vis);
            }
        }
        return;
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int count=0;
        int m=adj.size();
        int n=adj[0].size();
        vector<int>ADJ[V];
       for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
               if(i!=j &&adj[i][j]==1){
                   ADJ[i].push_back(j);
                   ADJ[j].push_back(i);
               }
           }
       }
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,ADJ,vis);
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends