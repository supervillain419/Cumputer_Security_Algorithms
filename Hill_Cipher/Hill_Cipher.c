#include<stdio.h>
#include<math.h>

float encr[3][1], decr[3][1], a[3][3], b[3][3], c[3][3], inv_matrix[3][3], mes[3][1];

void encryption();    //encrypts the message
void decryption();    //decrypts the message
void inverse();     //finds inverse of the matrix
void getMsg();    //gets a message and a 3x3 matrix key from user
        
void main() {
    printf("---------- HILL CYPHER -----------\n");
    getMsg();
    encryption();
    decryption();
    printf("\n-------------- END ---------------\n");
}

void getMsg() {
    int i, j,cho,k=0;
    char msg[4],str[10];

    printf("Enter 3x3 Inversible Matrix (KEY):\n\n");
    printf("Do you prefer entering it as a string or as a number?\n(1=String,2=Number):\t");
    scanf("%d",&cho);
    switch(cho){
        case 1:
            printf("Enter a 9 letter string :\n");
            scanf("%9s",str);
        
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    a[i][j]=str[k] - 97;//It subtructs 97 from the character to convert it from ASCII to a number!
                    c[i][j] = a[i][j]; //A copy of the matrix for the inversion
                    k++;
                }
            }
            
            printf("----- Characters to ASCII -----\n");
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    printf(" %f ",a[i][j]);
                } 
                printf("\n");
            }
            printf("---------------- ---------------");
            break;
            
        case 2:
            printf("Enter a 3x3 numeric matrix: \n");
            for(i = 0; i < 3; i++){
                for(j = 0; j < 3; j++) {
                    scanf("%f", &a[i][j]);
                    c[i][j] = a[i][j];
                }
            }
            break;
    }
    
    printf("\nEnter a 3 letter string (PLAINTEXT): ");
    scanf("%3s", msg);
    for(i = 0; i < 3; i++)
        mes[i][0] = msg[i] - 97; //For example it subtructs 97 from "a"(a=97, b=98.. in ASCII)
}                                // and stores the value 0 for "a" ,1 for "b", 2 for "c" etc.

void encryption() {
    int i, j;

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            encr[i][0] = encr[i][0] + a[i][j] * mes[j][0]; //Multiplies 3x3 matrix with the given message
        }
    }
    printf("\nEncrypted string is (CYPHERTEXT): ");
    for(i = 0; i < 3; i++){
        printf("%c", (char)(fmod(encr[i][0], 26) + 97)); //Prints the character after mod 26 (26 letters in Eng language)
                                                        //then adds 97 so we can display it with the ASCII code
    }

}

void decryption() {
    int i, j;
    inverse();
    
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            decr[i][0] = decr[i][0] + inv_matrix[i][j] * encr[j][0]; //Multiplies inverse matrix with the encrypted message(cyphertext)
        }
    }

    printf("\nDecrypted string is: ");
    for(i = 0; i < 3; i++){
        printf("%c", (char)(fmod(decr[i][0], 26) + 97));
    }
    printf("\n");
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

    for(i = 0; i < 3; i++)
        for(j = 0; j < 3; j++)
            inv_matrix[i][j] = b[i][j] / c[i][i];

    printf("\n\n------- Inverse Matrix -------\n");
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++){
            printf("%d ", inv_matrix[i][j]);
        }
        printf("\n");
    }
}
