int popc[66000];

int popcount(int x) {
	return popc[x & 0xffff] + popc[(x>>16) & 0xffff];
}

string ThueMorseGame::get(int n,int m)
{
	popc[0] = 0;
	for (int i = 1; i < (1<<16); i++) popc[i] = popc[i & (i-1)] + 1;
    
    int currl = 0;
    while(currl + m + 1 <= n)
    {
       currl+= m + 1;
       while(currl<=n && (popcount(currl) & 1))++currl;
    }
    if(currl == n)return "Bob";
    return "Alice";
}
