const int MAX = 1000001;
int phi[MAX];
 
void euler_phi() {
    phi[1] = 1;
    for(int i=2; i<MAX; i++) {
        if(!phi[i]) {
            phi[i] = i-1;
            for(int j=(i<<1); j<MAX; j+=i) {
                if(!phi[j]) phi[j] = j;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }
}
 
int main() {
    euler_phi();
    for(int t=1; t<MAX; t++) printf("%d\n", phi[t]);
    return 0;
}
