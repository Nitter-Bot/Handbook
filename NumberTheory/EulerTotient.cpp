
vi phi(N);
iota(all(phi),0);

for(int i=2;i<N;i++)
	if(phi[i]==i)
		for(int j=i;j<N;j+=i)
			phi[j] -= phi[j]/i
