#include<iostream>
using namespace std;
string caesarCipher(string input_str,int num)
{
char ch;
string message=input_str;
int i, key;
key=num;
for(i = 0; message[i] != '\0'; ++i){
ch = message [i];
if(ch >='a' && ch<='z'){
ch = ch + key;
if(ch>'z'){
    ch=ch-'z'+'a'-1;
}
message[i] = ch;
}
else if(ch >= 'A' && ch < 'Z'){
ch = ch + key;
if(ch > 'Z'){
ch = ch - 'Z' + 'A' - 1;
}
message [i] = ch;
}
}

return message;
}

int main(){
    string ans=caesarCipher("Hello World!",4);
    cout<<ans<<endl;
}