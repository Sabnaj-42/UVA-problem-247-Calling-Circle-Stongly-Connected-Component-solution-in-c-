#include<bits/stdc++.h>
using namespace std;
map<string,bool>visit,onstack;
map<string,int>in,low;
stack<string>st;
map<string,vector<string>>graph;
int timer;
void dfs_scc(string node)
{
    visit[node]=1;
    onstack[node]=1;
    in[node]=low[node]=timer;
    timer++;
    st.push(node);
    for(string child:graph[node])
    {
        if(visit[child]==1&&onstack[child]==1)
        {
            low[node]=min(low[node],in[child]);
        }
        else if(visit[child]==0)
        {
            dfs_scc(child);
            if(onstack[child]==1)low[node]=min(low[node],low[child]);
        }
    }
    if(low[node]==in[node])
    {
        while(1)
        {
            string s=st.top();
            st.pop();
            onstack[s]=0;
            if(s==node)
            {
                cout<<s<<endl;break;
            }
            else cout<<s<<", ";
        }
    }
}
int main()
{
    int n,m,k=0;
    while(1)
    {
        graph.clear();
        onstack.clear();
        visit.clear();
        timer =1;
        map<string,int>flag;
        cin>>n>>m;
        k++;
        if(n==0&&m==0)break;
        printf("Calling circles for data set %d:\n",k);
        for(int i=0;i<m;i++)
        {
            string a,b;cin>>a>>b;
            graph[a].push_back(b);
            flag[a]++;
            flag[b]++;
        }
        int i=0;
        for(auto it:flag)
        {
            if(visit[it.first]==0)
            {
                dfs_scc(it.first);//cout<<i++<<" ";
            }
        }
    }

}
