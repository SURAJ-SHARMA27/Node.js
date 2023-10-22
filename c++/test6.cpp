#include<bits/stdc++.h>
using namespace std;
void rotateMatrix(vector<vector<char> >& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<char> > new_mat(m, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_mat[j][n - i - 1] = mat[i][j];
        }
    }
    mat = new_mat;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int a;
    cin>>a;
    vector<vector<char>>mat;
     for(int i=0;i<a;i++){
     for(int j=0;j<a;j++){
        cin>>mat[i][j];
     }
     }
     vector<vector<char>>orig;
     orig=mat;
     rotateMatrix(mat);
     bool flag=false;
     int ans;
     for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            if(orig[i][j]=='z'&&orig[i][j]!=mat[i][j]){
                cout<<-1<<endl;
                flag=true;
                break;
            }
            if((mat[i][j]!=orig[i][j])&&(orig[i][j]<mat[i][j])){
            
            }
        }
     }
    }
}