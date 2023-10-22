#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int a,b,c;
    cin>>a>>b>>c;
    priority_queue<int>st;
    st.push(a);
    st.push(b);
    st.push(c);
    bool flag=false;
    if(a==b&&b==c){
        cout<<"YES"<<endl;
        flag=true;
        continue;
    }
    vector<int>vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    
    for(int i=0;i<3;i++){
        sort(vec.begin(),vec.end());
        int n=vec.size();
        int n1=vec[0];
        int n2=vec[n-1];
        int n3=n2-n1;
         vec.pop_back();
         vec.push_back(n3);
         vec.push_back(n1);
         bool ans=true;
         for(int i=0;i<vec.size()-1;i++){
            if(vec[i]!=vec[i+1]){
                ans=false;
            }
         }
         if(ans){
            cout<<"YES"<<endl;
            flag=true;
            break;
         }

   
    }
    if(!flag){
        cout<<"NO"<<endl;
    }
    }
}