vector<int> buildCircuit(vector<vector<pair<int,int>>> &g, int ini, int m){
    vector<int> circuit;
    vector<int> p = {ini};
    vector<bool> vis(m);
    while(!p.empty()){
        pair<int,int> next = {-1,-1};
        while(true){
            if(g[p.back()].empty()) break;
            if(vis[g[p.back()].back().sc]){
                g[p.back()].pop_back();
                continue;
            }
            next = g[p.back()].back();
            g[p.back()].pop_back();
            break;
        }
        if(next.f == -1){
            circuit.push_back(p.back());
            p.pop_back();
        }else{
            vis[next.sc] = true;
            p.push_back(next.f);
        }
    }
    return circuit;
}
