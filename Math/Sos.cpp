for(auto x : a) sos[x]++;
for(int i=0; i<20; i++){
    for(int j=0; j<(1<<20); j++){
        if(j&(1<<i))
            sos[j] += sos[j-(1<<i)];
    }
}
