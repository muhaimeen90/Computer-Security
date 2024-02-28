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

string encrypt(const string &plaintext, char matrix[5][5]) {
    string processedText = diagram(plaintext);
    string ciphertext = "";

    for (int i = 0; i < processedText.size(); i += 2) {
        char a = processedText[i];
        char b = processedText[i + 1];

        int row1, col1, row2, col2;
        findPos(matrix, a, row1, col1);
        findPos(matrix, b, row2, col2);

        if (row1 == row2) { // Same row
            ciphertext += matrix[row1][(col1 + 1) % 5];
            ciphertext += matrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) { // Same column
            ciphertext += matrix[(row1 + 1) % 5][col1];
            ciphertext += matrix[(row2 + 1) % 5][col2];
        } else { // Forming rectangle
            ciphertext += matrix[row1][col2];
            ciphertext += matrix[row2][col1];
        }
    }

    return ciphertext;
}

string decrypt(const string &ciphertext, char matrix[5][5]) {
    string processedText = diagram(ciphertext);
    string plaintext = "";

    for (int i = 0; i < processedText.size(); i += 2) {
        char a = processedText[i];
        char b = processedText[i + 1];

        int row1, col1, row2, col2;
        findPos(matrix, a, row1, col1);
        findPos(matrix, b, row2, col2);

        if (row1 == row2) { // Same row
            plaintext += matrix[row1][(col1 - 1 + 5) % 5];
            plaintext += matrix[row2][(col2 - 1 + 5) % 5];
        } else if (col1 == col2) { // Same column
            plaintext += matrix[(row1 - 1 + 5) % 5][col1];
            plaintext += matrix[(row2 - 1 + 5) % 5][col2];
        } else { // Forming rectangle
            plaintext += matrix[row1][col2];
            plaintext += matrix[row2][col1];
        }
    }

    return plaintext;
}

int main() {
    string key,plainText;
    cin>>key>>plainText;
    string modKey = modifiedKey(key);
    char matrix[5][5];
    fillMatrix(matrix, modKey);

    string ciphertext = encrypt(plainText, matrix);
    cout << "Encrypted: " << ciphertext << endl;


    cout << "Decrypted: " << decrypt(ciphertext, matrix)<< endl;

}