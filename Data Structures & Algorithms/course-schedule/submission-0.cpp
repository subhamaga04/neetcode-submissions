class Solution {
private: 
    bool isCycle(int src, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>>& adj){
        visited[src] = true; 
        recPath[src] = true; 

        for(auto &it : adj[src]){
            if(!visited[it]){
                if(isCycle(it, visited, recPath, adj)) return true; 
            }else if(recPath[it]) return true; 
        }

        recPath[src] = false; 
        return false; 
    }


public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 

        for(auto &it : prerequisites){
            int course = it[0];
            int prereq = it[1]; 
            adj[prereq].push_back(course);  
        }

        vector<bool> visited(numCourses, false); 
        vector<bool> recPath(numCourses, false);

        for(int i = 0; i < numCourses; i++){
            if(!visited[i]){
                 if(isCycle(i, visited, recPath, adj)) return false; 
            }
           
        }

        return true; 
    }
};
