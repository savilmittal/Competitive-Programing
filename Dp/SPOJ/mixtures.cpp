#include<bits/stdc++.h>
using namespace std;
struct node
{
    int no;
    int cost;
};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        node a[110][110];
        for(int j=1;j<=n;j++){
            scanf("%d",&a[j][j].no);
            a[j][j].cost=0;
        }
        for(int ic=2;ic<=n;ic++){
            for(int j=1,k=ic;k<=n;j++,k++)
            {
                a[j][k].cost=1000000000;
                int old=-1;
                a[j][k].no=-1;
                for(int l=j;l<k;l++)
                {
                    a[j][k].cost=min(a[j][k].cost,a[j][l].no*a[l+1][k].no+a[j][l].cost+a[l+1][k].cost);
                    if(old!=a[j][k].cost)
                    {
                        a[j][k].no=(a[j][l].no+a[l+1][k].no)%100;
                    }
                }
            }
        }
        cout<<a[1][n].cost<<endl;
    }
}
