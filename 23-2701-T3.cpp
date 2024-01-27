#include<bits/stdc++.h>
using namespace std;
int table[100][100];
void fill(string &input, string &key){
    for(int i=0;i<input.size();i++){
        table[0][i]=input[i]-'a';
    }
    int j=0;
    for(int i=0;i<input.size();i++){
        if(j==key.size()) j=0;
        table[1][i]=key[j]-'a';
        j++;
    }
}
void print(int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void encryption(string &input){
    for(int i=0; i<input.size();i++){
        input[i]=(char)((table[0][i]+table[1][i])%26 + 'a');
    }
}
void decryption(string &input){
    for(int i=0; i<input.size();i++){
        input[i]=(char)(((input[i]-'A')%26)+'a');
    }
}
int main(){
    string input;
    string key;
    int table[2][input.size()];
    cin>>input>>key;
    fill(input,key);
    print(2,input.size());
    encryption(input);
    cout<<"Encrypted text: "<<input<<endl;
    // decryption(input);
    // cout<<"decrypted text: "+input<<endl;
    // string s="abc";
    // int p=s[2];
    // cout<<p<<endl;
}