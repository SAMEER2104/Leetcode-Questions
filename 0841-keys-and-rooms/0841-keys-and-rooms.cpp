class Solution {
public:
bool dfs (vector<vector<int>>& rooms, int u, vector<bool>&visit)
{
    visit[u] = true;

    for(int v : rooms[u])
    {
        if(!visit[v])
        dfs(rooms, v, visit);

    }

    return true;

};

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>visit(n,false);

        dfs(rooms, 0, visit);
        for(int x : visit)
        {
            if(x == false)
            return false;
        };

        return true;
        
    }
};