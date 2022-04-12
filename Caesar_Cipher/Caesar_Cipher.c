#include <stdio.h>
#include <stdlib.h>

void encryption(); //Encrypts the message
void decryption(); //Decrypts the message

int main(){

    int i,key,cho,ch;
    printf("--------------- CAESAR CYPHER ----------------\n");
    printf("Would you like to encrypt or decrypt a message?\n(1=Encrypt & 2=Decrypt)\n");
    scanf("%d",&cho);
    switch(cho){
        case 1:
            encryption();
            break;
        case 2:
            decryption();
            break;
        default:
            printf("\nInvalid Input!"); //Exits if number given is not 1 or 2
            exit(0);
    }
    printf("-------------------- END ---------------------\n");
        
}

void encryption(){
    char message[100];
    int i,ch,key;

    printf("Enter the message to encrypt: \n");
    scanf("%s",message);

    printf("Enter the key:\n");
    scanf("%d",&key);

    for(i=0;message[i]!='\0';i++){  //While message[i] is not a zero character
        ch=message[i];  //ch takes i character of the word

        if(ch>='a' && ch<='z'){ //if character is somewhere between 'a' and 'z'
            ch=ch+(key%26); //Encryption key is added mod 26 (26 characters in the English Language)
            if(ch>'z'){ //If ch is bigger than 'z' we substruct 'z' and then start back from 'a' character
                ch=ch-'z'+'a'-1;
            }
            message[i]=ch;
        }else if(ch>='A' && ch<='Z'){   //if character is somewhere between 'A' and 'Z'
            ch=ch+(key%26); //Encryption key is added mod 26 (26 characters in the English Language)
            if(ch>'Z'){ //If ch is bigger than 'Z' we substruct 'Z' and then start back from 'A' character
                ch=ch-'Z'+'A'-1;
            }   
            message[i]=ch;
        }
    }
    printf("Encryped message is : %s\n",message);
}

void decryption(){
    char message[100],ch;
    int i,key;

    printf("Enter the encrypted message: \n");
    scanf("%s",message);

    printf("Enter Key: \n");
    scanf("%d",&key);

    for(i=0;message[i]!='\0';++i){  //While message[i] is not a zero character
        ch=message[i];  //ch takes i character of the word

        if(ch>='a' && ch<='z'){ //if character is somewhere between 'a' and 'z'
            ch=ch-(key%26); //Encryption key is substructed mod 26 (26 characters in the English Language)
            if(ch<'a'){ //If ch is lower than 'a' we add 'z' and then substruct a + 1
                ch=ch+'z'-'a'+1;
            }
            message[i]=ch;
        }else if(ch>='A' && ch<='Z'){   //if character is somewhere between 'A' and 'Z'
            ch=ch-(key%26); //Encryption key is substructed mod 26 (26 characters in the English Language)
            if(ch <'A'){    //If ch is lower than 'A' we add 'Z' and then substruct A + 1;
                ch=ch+'Z'-'A'+1;
            }   
            message[i]=ch;
        }
    }
    printf("Encryped message is : %s\n",message);
    
}
