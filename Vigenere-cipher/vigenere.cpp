#include<iostream>
#include<string.h>
using namespace std;

int main(){
    char msg[] = "ORACLE RED BULL RACING";
    char key[] = "RASYID";
    int msgLen = strlen(msg), keyLen = strlen(key), i, j;

    char newKey[msgLen], encryptMsg[msgLen], decryptMsg[msgLen];

    //generating new key
    for(i = 0, j = 0; i < msgLen; i++, j++){
        if(j == keyLen)
            j = 0;

        newKey[i] = key[j];
    }

    newKey[i] = '\0';

    //encrypt
    for(i = 0; i < msgLen; i++) {
        if(msg[i] == ' ') {
            encryptMsg[i] = ' ';
        }
        else {
            encryptMsg[i] = ((msg[i] + newKey[i]) % 26) + 'A';
        }
    }

    encryptMsg[i] = '\0';

    //decrypt
    for(i = 0; i < msgLen; i++) {
        if(encryptMsg[i] == ' ') {
            decryptMsg[i] = ' ';
        }
        else {
            decryptMsg[i] = (((encryptMsg[i] - newKey[i]) + 26) % 26) + 'A';
        }
    }

    decryptMsg[i] = '\0';

    cout<<"Plain: "<<msg;
    cout<<"\nKey: "<<key;
    cout<<"\nEncrypt: "<<encryptMsg;
    cout<<"\nDecrypt: "<<decryptMsg;
 
return 0;
}