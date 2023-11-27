int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;
    queue<pair<int,int>> month, week;
    for(int day: days){

        while(!month.empty() && month.front().first <= day-30) month.pop();
        while(!week.empty() && week.front().first <= day-7) week.pop();

        month.push({day,ans+cost[2]});
        week.push({day,ans+cost[1]});

        ans = min(ans+cost[0],min(month.front().second, week.front().second));
    }

    return ans;
}