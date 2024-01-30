#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> table[5][5];
vector<int> search(vector<vector<char>> arr, char target)
{
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[i].size(); j++) {
      if (arr[i][j] == target) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}
void fill(string input, string key){
    int k=0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(k<key.size()){
                if(search(table,key))    
                table[i].pushback(key[k]);
            }
        }
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
    cout<<"Encrypted text: "<<input<<endl;
    decryption(input);
    cout<<"Decrypted text: "<<input<<endl;
}