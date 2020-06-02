void si(int &ret){
	int ip=gc(),flag=1;ret=0;for(;ip<'0'||ip>'9';ip=gc())
	if(ip=='-'){flag=-1;ip=gc();break;}
	for(;ip>='0'&&ip<='9';ip=gc())ret=(ret<<1)+(ret<<3)+ip-'0';ret*=flag;
}

void sl(ll &ret) {
	int ip=gc(),flag=1;ret=0;for(;ip<'0'||ip>'9';ip=gc())
	if(ip=='-'){flag=-1;ip=gc();break;}
	for(;ip>='0'&&ip<='9';ip=gc())ret=(ret<<1)+(ret<<3)+ip-'0';ret*=flag;
}