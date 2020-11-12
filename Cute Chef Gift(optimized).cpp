#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <utility>
#include <math.h>
#include <climits>
#include <string>
#include <cstring>
#include <iomanip>
#include <stack>
#include <queue>
#include <tuple>
#include <unordered_map>
#define int long long
//#define int long long
#define f(i,n) for(int i=0;i<n;i++)
#define f1(i,a,b) for(int i=a;i<b;i++)
#define ld long double
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define mii map<int,int>
#define mll map<int,int>
#define vl vector<int>
#define vpll vector<pair<int,int>>
#define mspii map<string,pair<int,int>>
#define pll pair<int,int>
#define F first
#define S second
#define PI 3.1415926535
#define setbits(x) __builtin_popcount(x)
#define inf 1e18
#define sp(x,y) fixed<<setprecision(y)<<x
#define mem(a,b) memset(a,b,sizeof(a))
#define endl '\n'
#define __gcd gcd
#define aint(v) (v).begin(),(v).end()
#define sz(a) (int)((a).size())
#define sq(x) ((x)*(x))
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define lb lower_bound
#define ub upper_bound
//typedef long long int;
using namespace std;

/*bool prime[200000 + 1];
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));

    prime[1] = false;

    for (int p = 2; p * p <= 200000; p++) {

        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {

            // Set aint multiples of p to non-prime
            for (int i = p * 2; i <= 200000; i += p)
                prime[i] = false;
        }
    }
}
int pow1(int a,int b){
     int ans=1;
     if(b==0)return ans;
     while(b>0){
          if(b&1==1)ans*=a;
          a*=a;
          b/=2;
     }
     return ans;
}

int ncr(int n,int r)
{
    if(r > n - r)
          r = n - r;
    int ans = 1;
    int i;
 
    for(i = 1; i <= r; i++)
     {
        ans *= n - r + i;
        ans /= i;
    }
 
    return ans;
}

*/

bool prime[200001];
int spf[200001];
void sieve(){
    memset(prime,true,sizeof(prime));
    for(int i=2;i<=200000;i++)spf[i]=i;
    for(int i=2;i*i<200000;i++){
        for(int j=i*i;j<=200000;j+=i){
            if(prime[j]==true)spf[j]=i;
            prime[j]=false;
        }
    }
}
vector<int> getfactors(int x){
    vector<int>res;
    while(x!=1){
        res.pb(spf[x]);
        x=x/spf[x];
    }
    return res;
}



int32_t main()
{

    //AUTHOR-JASKARAN
     //Thug-Life...
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output1.txt","w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int t;
     cin>>t;   
     sieve();                                                  
     while(t--){
        int n;cin>>n;
        int a[n+1]{};
        f1(i,1,n+1)cin>>a[i];
        mll s;
        mll e;
        f1(i,1,n+1){
            vector<int>ans=getfactors(a[i]);
            for(int j=0;j<ans.size();j++){
                if(s.find(ans[j])==s.end())s[ans[j]]=i;
                e[ans[j]]=i;
            }
        }
        int range[n+1]{};
        for(auto it=s.begin();it!=s.end();it++)range[it->second]+=1;
        for(auto it=e.begin();it!=e.end();it++)range[it->second]-=1;
        int ans=-1;
        f1(i,1,n+1){
            range[i]+=range[i-1];
            if(range[i]==0){
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
                
        
     }
}
