#include<bits/stdc++.h>
using namespace std;
char table[100][100];
void fill(string input,string key){
    for(int i=0;i<input.size();i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(input[i]==table[j][k]){
                    continue;
                }
            }
        }
        table
    }
}
void encryption(string &input){

}
void decryption(string &input){

}
int main(){
    string input,key;
    cin>>input>>key;
    fill(input,key);
    encryption(input);
    cout<<input<<endl;
    decryption(input);
    cout<<input<<endl;
}