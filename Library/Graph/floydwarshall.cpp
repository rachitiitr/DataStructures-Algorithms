#include<iostream>
using namespace std;
#define INF 1e7
void floydwarshall(int m[][100],int n)
{
    int dist[n][n];
    
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dist[i][j]=m[i][j];
            }
        }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]+dist[k][j]<dist[i][j])
                dist[i][j]=dist[i][k]+dist[k][j];
            }
        }
    }
    for(int i=0;i<n;i++)
        {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
            cout<<"INF"<<" ";
            else
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
        }
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int m[100][100];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>m[i][j];
	        }
	    }
	    floydwarshall(m,n);
	    
	    /*for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(m[i][j]==INF)
	            cout<<"INF"<<" ";
	            else
	            cout<<m[i][j]<<" ";
	        }
	        cout<<endl;
	    }*/
	}
	return 0;
}