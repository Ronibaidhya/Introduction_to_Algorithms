//https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include<bits/stdc++.h>
using namespace std;
class cmp{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        }

};
class Solution
{
	public:
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        int dis[V];
        for(int i=0;i<V;i++){
            dis[i] = INT_MAX;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        pq.push({s,0});
        dis[s] = 0;
        while(!pq.empty()){
            pair<int,int> parent = pq.top();
            int node = parent.first;
            int cost = parent.second;
            pq.pop();
            for(auto child: adj[node]){
                int childNode = child[0];
                int childCost = child[1];
                    
                if(cost+childCost < dis[childNode]){
                    dis[childNode] = cost+childCost;
                    pq.push({childNode,dis[childNode]});
                }
            }

        }
        
        vector<int> x;
        for(int i=0;i<V;i++){
            x.push_back(dis[i]);
        }
        return x;
    }
};

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class cmp{
    public:
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        }

};
class Solution
{
	public:
	
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        int dis[V];
        for(int i=0;i<V;i++){
            dis[i] = INT_MAX;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
        pq.push({s,0});
        dis[s] = 0;
        while(!pq.empty()){
            pair<int,int> parent = pq.top();
            int node = parent.first;
            int cost = parent.second;
            pq.pop();
            for(auto child: adj[node]){
                int childNode = child[0];
                int childCost = child[1];
                    
                if(cost+childCost < dis[childNode]){
                    dis[childNode] = cost+childCost;
                    pq.push({childNode,dis[childNode]});
                }
            }
        }
        
        vector<int> x;
        for(int i=0;i<V;i++){
            x.push_back(dis[i]);
        }
        return x;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends