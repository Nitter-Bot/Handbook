int gauss (vector < vector<ll> > a, vector<ll> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;
 
    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (a[sel][col] == 0)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;
 
        for (int i=0; i<n; ++i)
            if (i != row) {
                ll c = divide(a[i][col] , a[row][col]);
                for (int j=col; j<=m; ++j)
                    a[i][j] = (a[i][j]-a[row][j] * c % MOD + MOD) % MOD;
            }
        ++row;
    }
 
    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = divide(a[where[i]][m] , a[where[i]][i]);
    for (int i=0; i<n; ++i) {
        ll sum = 0;
        for (int j=0; j<m; ++j)
            sum = (sum + ans[j] * a[i][j] % MOD) % MOD;
        if (sum - a[i][m])
            return 0;
    }
 
    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return 2;
    return 1;
