// Author: Sai Tripura Manne
// DAA Assignment 3
//LEAST COMMON SUBSEQUENCE

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to retrieve the Least Commom Subsequence and it's length 
void lcs(char X[],char Y[], int m, int n)
{
    int c[20][20]; //array to store the length of the LCS
    int i,j;
    char b[20][20]; //array to store the directions to trace the length the LCS
    //initializing the first row and column of the matrix c[i][j] to 0
    for(i=0;i<=m;i++)
    {
        c[i][0] = 0;
    }
    for(j=0;j<=n;j++)
    {
        c[0][j] = 0;
    }
    //calculate the length of the LCS
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
           
          
         if (X[i-1] == Y[j-1])
            {
                c[i][j] = c[i-1][j-1]+1;
                b[i-1][j-1] = 'D';
                
            }
            else
            {
                if(c[i][j-1] > c[i-1][j])
                {
                        c[i][j] = c[i][j-1];
                        b[i-1][j-1] = 'L';
                       
                }
                else 
                {
                    c[i][j] = c[i-1][j];
                    b[i-1][j-1] = 'U';
                    
                }
                
                
            }
            
        }
    }
   
 printf("Length of LCS is %d \n",c[m][n]);

 i = m-1; 
 j = n-1;
 // assigning c[m][n](length of LCS) to z
 int z;
 z = c[m][n]; 
//creating a array  to store LCS
 char final_string[z-1];
 
//code to retrieve LCS 
 while(z!=0)
 {
     if(b[i][j] == 'U')
     {
         i--;
         
     }
     else if(b[i][j] == 'L')
     {
         j--;
         
     }
     else if(b[i][j] == 'D')
     {
         i--;
         j--;
         
        final_string[z-1] = X[i+1];
        
        z--;
        
        
     }

 }
 printf("LCS : %s \n",final_string);


}
//Driver code
int main(int argc, char *argv[])
{
    //To retrieve strings from the command line to find LCS
    char *A;
    char *B;
    //Print error if input is more than 2 strings
    if(argc==3)
    {
         A = argv[1];
         B = argv[2];
    }
    else
    {
        printf("ERROR\n");
        return -1;
    }
    //The length of the strings must not exceed 100 characters
    char *X;
    char *Y;
    if(strlen(A) <= 100 && strlen(B) <= 100)
    {
        X = B;
        Y = A; 
    }
    else
    {
        printf("the string is too long\n");
        return -2;
    }
    int m = strlen(X);  //length of string X
    int n = strlen(Y);  //length of string Y
    
    lcs(X,Y,m,n);
    
    return 0;
}
