#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int a,b;
    cin>>a>>b;
    string s1,s2;
    cin>>s1>>s2;

    int n=a;
    string t=s1;
    int cnt=0;
    bool flag=false;
    bool ft=false;
    if(b<a){
         if(t.find(s2)!= string::npos){
            cout<<0<<endl;

         }
         else{
             t=t+t;
             if(t.find(s2)!= string::npos){
              cout<<1<<endl;
             }
             else{
                cout<<-1<<endl;
             }


         }
       
     ft=true;
        
    }
   while((n<=(3*b+1))&&(!ft)){
     if(t.find(s2)!= string::npos){
    cout<<cnt<<endl;
flag=true;
    break;
   }
    t=t+t;
    cnt++;
   n=t.length();
   }
   if(!flag&&!ft){
    cout<<-1<<endl;
   }
    }
}