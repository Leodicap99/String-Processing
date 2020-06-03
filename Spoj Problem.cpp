     //https://www.spoj.com/problems/NAJPF/
     
     #include <bits/stdc++.h> 
        using namespace std; 
        //#define int long long
        # define pii pair<int,int>
        const int maxn=1e6+5;
        vector<int> rabin_karp(string const &s,string const &t)
        {
            const int p=31;
            const int m=1e9+9;
            int S=s.size(),T=t.size();
            vector<long long> p_pow(max(S,T));
            p_pow[0]=1;
            for(int i=1;i<(int)p_pow.size();i++)
            {
                p_pow[i]=(p_pow[i-1]*p)%m;
            }
            vector<long long> h(T+1,0);
            for(int i=0;i<T;i++)
            {
                h[i+1]=(h[i]+(t[i]-'a'+1)*p_pow[i])%m;
            }
            long long h_s=0;
            for(int i=0;i<S;i++)
            {
                h_s=(h_s+(s[i]-'a'+1)*p_pow[i])%m;
            }
            vector<int> ans;
            for(int i=0;i+S-1<T;i++)
            {
                long long cur_h=(h[i+S]-h[i]+m)%m;
                if(cur_h==h_s*p_pow[i]%m)ans.push_back(i);
            }
            return ans;
        }
        signed main() { 
            #ifndef ONLINE_JUDGE
            freopen("input.txt","r",stdin);
            freopen("output.txt","w",stdout);
            #endif
            ios::sync_with_stdio(0);
            cin.tie(0);
            int t;
            cin>>t;
            while(t--)
            {
                string s,t;
                cin>>s>>t;
                vector<int> ans=rabin_karp(t,s);
                if(ans.size()==0)
                {
                    cout<<"Not Found"<<endl;
                    continue;
                }
                cout<<ans.size()<<endl;
                for(int i=0;i<(int)ans.size();i++)cout<<ans[i]+1<<" ";
                cout<<endl;
            }
        }
