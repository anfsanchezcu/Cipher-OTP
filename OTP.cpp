#include <bits/stdc++.h>

using namespace std;

string KeyGenerator(int size)
{
  string mapKey;
  int aux;
  for (int i = 0; i < size; i++)
  {
    aux = rand() % 26;
    mapKey.push_back(aux+97);
  }
  return mapKey;
}

string OTPCriptor(string plainText, string &key)
{
  string encriptedText;

  int letterAux;
  int keyCode;
  int result;
  for (int i = 0; i < plainText.length(); i++)
  {
    letterAux = int(plainText[i]);
    keyCode = int(key[i])-97;
    result = letterAux + keyCode;

    while(result>122)
      result -= 26;
    encriptedText.push_back(char(result));
  }
  return encriptedText;
}

string OTPDecryptor(string encriptedText, string key)
{
  string plainText;

  int letterAux;
  int keyCode;
  int result;
  for(int i = 0; i < encriptedText.length(); i++){
    letterAux = int(encriptedText[i]);
    keyCode = int(key[i])-97;
  
    result = letterAux - keyCode;
    while(result<97)
      result += 26;
    plainText.push_back(char(result));
  }
  return plainText;
}

int main()
{
  string plainText; cin >> plainText;
  string key = KeyGenerator(plainText.length());

  string encriptedText = OTPCriptor(plainText, key); 
  string uncriptedText = OTPDecryptor(encriptedText, key);

  cout << "llave: "<<key<<endl;
  cout <<"texto encriptado: "<< encriptedText << endl;
  cout <<"texto plano: "<< uncriptedText << endl;
  
}