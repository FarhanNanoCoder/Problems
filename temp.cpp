#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INT __int128
#define ff first
#define ss second
#define INF 1e18
#define pi acos(-1)
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define pii pair<int,int>
#define pll pair<ll,ll>
ll mod = 1000000007;
int fx[] = {0,0,-1,1};
int fy[] = {1,-1,0,0};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n,k,q,i,j;
  string s;
  string tokens[]={"ajjajsjsskskks7","abcd","xyz"};

  map<string,int>mp;

  vector<string>v[10];
  v[0].push_back("get");
  v[0].push_back("https://exampld.com/?token=aaaaa&name=rrrr");

  v[1].push_back("get");
  v[1].push_back("https://exampld.com/?token=abcd&name=rrrr&location=kuet");

  v[2].push_back("post");
  v[2].push_back("https://exampld.com/?token=abcd&csrf=asJ124Kii&name=rrrr&location=kuet&id=hiji");

  v[3].push_back("post");
  v[3].push_back("https://exampld.com/?token=abcd&name=rrrr&location=kuet&id=hiji");


  for(i=0;i<3;i++)
    mp[tokens[i]]=1;

  for(i=0;i<4;i++)
  {
    string type = v[i][0];
    string str = v[i][1];

    if(type=="get")
    {
        j=0;
        while(str[j]!='=') j++;

        string tmp = "";
        j++;

        while(str[j]!='&')
        {
            tmp+=str[j++];
        }

        if(mp[tmp]==1)
        {
            cout<<"VALID,";
            for(k=j+1;k<str.size();k++)
            {
                if(str[k]=='&' || str[k]=='=')
                    cout<<",";
                else
                    cout<<str[k];
            }
            cout<<endl;
        }
        else
        {
            cout<<"INVALID"<<endl;
        }


    }
    else
    {
        j=0;
        while(str[j]!='&') j++;
        j++;
        string tmp = "";
        for(k=0;k<4;k++)
            tmp+=str[j+k];
        if(tmp=="csrf")
        {
            cout<<"VALID,";
            while(str[j]!='&') j++;
            for(k=j+1;k<str.size();k++)
            {
                if(str[k]=='&' || str[k]=='=')
                    cout<<",";
                else
                    cout<<str[k];
            }
            cout<<endl;
        }
        else
        {
            cout<<"INVALID"<<endl;
        }


    }
  }

}