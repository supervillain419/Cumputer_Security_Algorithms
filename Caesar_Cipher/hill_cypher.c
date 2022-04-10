#include<stdio.h>
#include<math.h>

float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
char msg[3];

void getMessage();
void encryption();    //encrypts the message
void decryption();    //decrypts the message
void getKeyMessage();    //gets key and message from user
void inverse();        //finds inverse of key matrix

void main(){
    int num;
    printf("-----HILL CYPHER-----\n");
    do{
        printf("Choose an option!\n1.Encryption\n2.Decryption\n");
        printf("---------------------\n");
        scanf("%d",&num);
    }while(num<0 && num>3);
    
    //edw tha exei to encryption
    switch(num){
    case 1:
        getKeyMessage();
        encryption();
        //decryption();
    break;
    case 2:
        //getMessage();
        decryption();
    break;
    }
    
    printf("\n------TELOS------");
}
void encryption() {
    int i, j, k;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 1; j++){
            for(k = 0; k < 3; k++){
                encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];//mul act with 3x3 key
            }
        }
    }
    printf("\nEncrypted string is: ");
    for(i = 0; i < 3; i++){
        printf("%c", (char)(fmod(encrypt[i][0], 26) + 97));//Adds 97 to ascii alphabet word
    }
}

void decryption() {
    int i, j, k;
    float p, q;
    //char msg[4];
    

    printf("Enter 3x3 matrix for key (It should be inversible):\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
            c[i][j] = a[i][j];
        }
    }
    
    printf("\nEnter a 3 letter encrypted string: "); // to poh
    scanf("%3s", msg);
    for(i = 0; i < 3; i++){
        mes[i][0] = msg[i]-97; //!!!!!!!!
        printf("%f",mes[i][0]);

    }
        
    //
    

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++) {
            if(i == j)
                b[i][j]=1;
            else
                b[i][j]=0;
        }
    }

    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = c[i][k];
            q = c[k][k];

            for(j = 0; j < 3; j++) {
                if(i != k) {
                    c[i][j] = c[i][j]*q - p*c[k][j];
                    b[i][j] = b[i][j]*q - p*b[k][j];
                }
            }
        }
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            b[i][j] = b[i][j] / c[i][i];
        }
    }

    printf("\n\n----Inverse Matrix----\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++){
            printf("%d ", b[i][j]);
        }

        printf("\n");
    }
    //
    
    for(i=0;i<3;i++){
        decrypt[i][0]=0;
    }
    
    for(i = 0; i < 3; i++){
            for(k = 0; k < 3; k++){
                decrypt[i][0] = decrypt[i][0] + b[i][k] * mes[k][0];
                //printf("--- encrypt is-------> %f ------\n\n",mes[k][j]);
                //printf("\n to decr= %f, to b %f, to encr %f \n",decrypt[i][0],b[i][k],mes[k][0]);
                printf("\n decrypt[%d][0] = %f + B[%d][%d] = %f * mes[%d][0] = %f\n",i,decrypt[i][0],i,k,b[i][k],k,mes[k][0]);
                
            }
            printf("\n\n ---> decrypt[%d][0] = %f <---\n",i,decrypt[i][0]);
            //printf("\n to decr= %f, to b %f, to encr %f \n",decrypt[i][0],b[i][k],encrypt[k][0]);
            //printf("--- %f --- %c---\n",decrypt[i][j],(char)(fmod(decrypt[i][0],26)+97));
            //printf("\n--- decrypt[%d][0]=== %f ---\n",i,decrypt[i][0]);
    }

    printf("\nDecrypted string is: ");
    for(i = 0; i < 3; i++){
        printf("\n%f\n",decrypt[i][0]);
        printf("%c", (char)(fmod(decrypt[i][0], 26) + 97));
    }

    printf("\n");
}

void getKeyMessage() {
    int i, j;
    

    printf("Enter 3x3 matrix for key (It should be inversible):\n");

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++) {
            scanf("%f", &a[i][j]);
            c[i][j] = a[i][j];
        }
    }

    printf("\nEnter a 3 letter string: ");
    scanf("%3s", msg);

    for(i = 0; i < 3; i++){
        mes[i][0] = msg[i] - 97; //!!!!!!!!
        //printf("%c",msg[i]);
    }
}

void inverse() {
    int i, j, k;
    float p, q;

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++) {
            if(i == j)
                b[i][j]=1;
            else
                b[i][j]=0;
        }

    for(k = 0; k < 3; k++) {
        for(i = 0; i < 3; i++) {
            p = c[i][k];
            q = c[k][k];

            for(j = 0; j < 3; j++) {
                if(i != k) {
                    c[i][j] = c[i][j]*q - p*c[k][j];
                    b[i][j] = b[i][j]*q - p*b[k][j];
                }
            }
        }
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            b[i][j] = b[i][j] / c[i][i];
            //printf("---- %f ----",b[i][j]);
        }
    }
    printf("\n\n----Inverse Matrix----\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++)
            printf("%d ", b[i][j]);

        printf("\n");
    }
    for(i = 0; i < 3; i++){
        for(j = 0; j < 1; j++){
            for(k = 0; k < 3; k++){
                decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
            }
            printf("--- %f --- %c---\n",decrypt[i][j],(char)(fmod(decrypt[i][0],26)+97));
        }
    }

    printf("\nDecrypted string is: ");
    for(i = 0; i < 3; i++){
        printf("%c", (char)(fmod(decrypt[i][0], 26) + 97));
    }
    printf("\n");
}
