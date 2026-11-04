// Hierholzer Directed
vector<int> buildPath(vector<vector<int>> &g, int ini){
    vector<int> path;
    vector<int> p = {ini};
    while(!p.empty()){
        if(g[p.back()].empty()){
            path.push_back(p.back());
            p.pop_back();
        }else{
            int next = g[p.back()].back();
            g[p.back()].pop_back();
            p.push_back(next);
        }
    }
    reverse(all(path));
    return path;
}
