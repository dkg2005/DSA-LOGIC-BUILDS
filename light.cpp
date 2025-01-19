#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int dp[17][(1<<16)];

int f(int i, int vis, vector<vector<pair<double,int>>>&adjclock, vector<vector<pair<double,int>>>&adjcounter, int n){
   if(i == n - 1){
      return 0;
   }
   if(dp[i][vis] != -1) return dp[i][vis];
   int ans = 1e9;
      for(size_t k = 0; k < adjclock[i].size(); k++){
         int ind = adjclock[i][k].second;
         if(vis & (1<<ind)) continue;
         vis |= (1<<ind);
         int res = f(ind, vis, adjclock, adjcounter, n);
         if(res != 1e9) ans = min(ans, res + 1);
         vis ^= (1<<ind);
         break;
      }
      for(size_t k = 0; k < adjcounter[i].size(); k++){
         int ind = adjcounter[i][k].second;
         if(vis & (1<<ind)) continue;
         vis |= (1<<ind);
         int res = f(ind, vis, adjclock, adjcounter, n);
         if(res != 1e9) ans = min(ans, res + 1);
         vis ^= (1<<ind);
         break;
      }
      return dp[i][vis] = ans;
}

void solve(){
   int n;
   cin>>n;
   vector<int>x(n), y(n);
   for(int i = 0; i < n; i++){
      cin>>x[i]>>y[i];
   }
   vector<vector<pair<double,int>>>adjclock(n), adjcounter(n);
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         if(i == j) continue;
         if(y[i] == y[j]){
            adjclock[i].push_back({0, j});
            adjcounter[i].push_back({0, j});
         }
         if((x[i] < x[j] && y[i] < y[j]) || (x[i] > x[j] && y[i] > y[j])){
            double m = abs((y[j] - y[i])/(double)(x[j] - x[i]));
            adjcounter[i].push_back({m, j});
         }
         else if(x[i] == x[j]){
            adjcounter[i].push_back({1e6, j});
            adjclock[i].push_back({1e6, j});
         }
         else{
            double m = abs((y[j] - y[i])/(double)(x[j] - x[i]));
            adjclock[i].push_back({m, j});
         }
      }
      sort(begin(adjclock[i]),end(adjclock[i]));
      sort(begin(adjcounter[i]),end(adjcounter[i]));
   }
   int vis = 1;
   memset(dp, -1, sizeof(dp));
   int ans = f(0, vis, adjclock, adjcounter, n);
   cout<<ans;
}
int main(){
  solve();
  return 0;
}