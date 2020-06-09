             #include <bits/stdc++.h> 
                using namespace std; 
                #define int long long
                # define pii pair<int,int>
                const int maxn=1e6+5;
                void getzarr(int Z[],string s)
                {
                    int n=s.size(),l=0,r=0;
                    for(int i=1;i<n;i++)
                    {
                        if(i>r)
                        {
                            l=r=i;
                            while(r<n && s[r-l]==s[r])r++;
                            Z[i]=r-l;
                            r--;
                        }
                        else
                        {
                            int k=i-l;
                            if(Z[k]<r-i+1)
                                Z[i]=Z[k];
                            else
                            {
                                l=i;
                                while(r<n && s[r-l]==s[r])r++;
                                Z[i]=r-l;
                                r--;
                            }
                        }
                    }
                }
                signed main() { 
                    #ifndef ONLINE_JUDGE
                    freopen("input.txt","r",stdin);
                    freopen("output.txt","w",stdout);
                    #endif
                    ios::sync_with_stdio(0);
                    cin.tie(0);
                    int n;
                    while(cin>>n){
                    string pat,s;
                    cin>>pat;
                    cin>>s;
                    string concat=pat+"$"+s;
                    int l=concat.size();
                    int Z[l];
                    getzarr(Z,concat);
                    for(int i=1;i<l;i++)
                    {
                        if(Z[i]==pat.size())cout<<i-pat.size()-1<<endl;
                    }
                    cout<<endl;
                    }
                }
