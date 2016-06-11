#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    while(n!=0||m!=0)
    {
        int dp[501][501]={0};
        int dp2[501][501]={0};
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int x;
                cin>>x;
                dp[i][j]=x+dp[i][j-1];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x;
                cin>>x;
                dp2[i][j]=x;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=m-1;j>=0;j--)
            {
                dp2[i][j]+=dp2[i][j+1];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                    dp[i][j]=dp[i][j]+dp2[i][j];
            }
        }
        int maxi=-1;
        for(int i=n;i>0;i--)
        {
            for(int j=m;j>=0;j--)
            {
                if(i==n)
                {
                    dp[i][j]=max(dp[i][j+1],dp[i][j]);
                }
                else
                {
                    dp[i][j]=max(dp[i][j+1],dp[i][j]+dp[i+1][j]);
                }
            }
        }
        cout<<dp[1][0]<<endl;
        cin>>n>>m;
    }
}
