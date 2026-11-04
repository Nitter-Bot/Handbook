int lehmer(vector<int> &v){
    int r = 0;
    int fact = 40320; // 8!
    for(int i=0; i<9; i++){
        int c = 0;
        for(int j=i+1; j<9; j++)
            if(v[j] < v[i]) c++;
        r += c*fact;
        if(i != 8) fact /= (8-i);
    }
    return r;
}
