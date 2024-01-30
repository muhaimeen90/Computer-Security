#include<bits/stdc++.h>
using namespace std;
void encryption(string &input,int key){
    for(int i=0; i<input.size();i++){
        input[i]=(char)(((input[i]-'a'+key)%26)+'A');
    }
}
void decryption(string &input,int key){
    for(int i=0; i<input.size();i++){
        input[i]=(char)(((input[i]-'A'-key)%26)+'a');
    }
}
int main(){
    string input;
    int key;
    cin>>input>>key;
    encryption(input,key);
    cout<<input<<endl;
    decryption(input,key);
    cout<<input<<endl;
}