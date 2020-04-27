#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stack>
#include<queue>
#include<iostream>
#include<map>
#include<vector>
#define Inf 0x3f3f3f3f
#define PI acos(-1.0)
using namespace std;
int str[1234];
int ans[1244];
int dp[1234][1234];
int len=1;
int main()
{
    char str1[1234],str2[1234];
    int len1,len2;
    while(scanf("%s %s",&str1,&str2)!=-1){
    len1=strlen(str1);
    for(int i=len1;i>=1;i--)
    {
        str1[i]=str1[i-1];
    }
    len2=strlen(str2);
    for(int i=len2;i>=1;i--)
    {
        str2[i]=str2[i-1];
    }
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=len1; i++)
        for(int j=1; j<=len2; j++)
        {
             if(str1[i]==str2[j])
             {
                 dp[i][j]=dp[i-1][j-1]+1;
             }
             else{

                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
             }
        }
        printf("%d\n",dp[len1][len2]);
    }
    return 0;
}
