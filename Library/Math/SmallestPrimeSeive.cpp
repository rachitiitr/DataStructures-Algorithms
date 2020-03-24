const int M = 1e6+3;
int pr[M];
//pr[6] = 2 and not 3
void pre()
{
	int i;
	pr[1] = 1; pr[2] = 2;
	fo(i, M) pr[i] = i;
	for(i=2; i<M; i++){
		if (pr[i] != i) continue;
		for(int j = 2*i; j<M; j+=i){
			if (pr[j] == j)
				pr[j] = i;
		}
	}
}

