#include <stdio.h>
#include <string.h>

void encryption();  //Encrypts the message
void decryption();  //Decrypts the message

char encrMes[100],decMes[100];
char mes[100];
char alph[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";     //English Alphabet
char key[26]="YDCEFGHJILKMZNPOQRSTUVWXA";      //Random alphabet that will be used as a key 


int main(){
    int i,cho,ch;
    printf("------------ Monoalphabetic Cipher ------------\n\n");
    printf("Would you like to encrypt or decrypt a message?\n(1=Encrypt & 2=Decrypt)\n");
    scanf("%d",&cho);

    switch(cho){
        case 1:
            encryption();
            break;
        case 2:
            decryption();
            break;
    }
    printf("\n\n-------------------- END ---------------------\n");
        
}

void encryption(){
    int i,j;

    printf("Enter the message to encrypt: \n");
    scanf("%s",mes);

    printf("\n-------- Encryption --------\n\n");
    for(i=0;i < sizeof(mes) && mes[i]!='\0';i++){
        for ( j = 0; j < 26; j++){
            if(mes[i] == alph[j]){      //Finds the position of the character in the alphabet and uses its position for the encryption
                encrMes[i]=key[j];
            }
        }   
    }

    printf("Encrypted string is :\t");
    for ( i = 0; i < sizeof(mes); i++){
        printf("%c",encrMes[i]);
    }
}

void decryption(){
    int i,j;
    printf("Enter the message you want to decrypt: \n");
    scanf("%s",mes);

    printf("\n----------- Decryption -----------\n\n");
    for(i=0;i < sizeof(mes) && mes[i] !='\0';i++){
        for ( j = 0; j < 26; j++){
            if(key[j] == mes[i]){       //Finds the encrypted character in the alphabet and uses its position to decrypt the message
                decMes[i] = alph[j];
            }
        }
    }

    printf("Decrypted string is :\t");
    for ( i = 0; i < sizeof(mes); i++){
        printf("%c",decMes[i]);
    }
}