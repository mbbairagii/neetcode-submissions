class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);
        for(auto edge: prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> order;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            order.push_back(node);
            for(int neighbour: adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }

        if(order.size() != numCourses){
            return {};
        }

        return order;
    }
};
