//Diana Rios #1001142931

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 5 
#define COLS 5

void FillBingoCard(int num[ROWS][COLS]);

void PrintBingoCard(int A[ROWS][COLS]);

int NumExist(int arr[ROWS][COLS],int num);

int PickNum(int num[],int count);

int CompletedRow(int arr[ROWS][COLS]);

int CompletedCol(int arr[ROWS][COLS]);

int CompletedDiag(int arr[ROWS][COLS],int num);



int main(void)
{
    char input;
    int next=0;
    int a[ROWS][COLS]={};// initializing to null
    int num[75]={};
    int count=1;
    FillBingoCard(a);
    PrintBingoCard(a);
    
    
    
    while(count<=75&& !(CompletedRow(a)||CompletedCol(a)||CompletedDiag(a,next)))
    {
        next=PickNum(num,count);
        
        if(next<=15)
        {
            printf("The next number is B%d\n",next);
        }
        else if(next<=30&&next>15)
        {
            printf("The next number is I%d\n",next);
          
        }
        else if(next<=45&&next>30)
        {
            printf("The next number is N%d\n",next);
            
        }
        
        else if(next<=60&&next>45)
        {
            printf("The next number is G%d\n",next);
           
        }
        else if(next<=75&&next>60)
        {
            printf("The next number is O%d\n",next);
            
        }
        
        printf("Do you have it? (Y/N)");
        scanf(" %c", &input);
        if(input == 'Y')
        {
            if(!NumExist(a,next))//if they say yes and it's not in the bingo card
            {
                printf("That value is not on your BINGO card - are you trying to cheat??");
                
            }
            if((CompletedCol(a))&&(CompletedRow(a))&&CompletedDiag(a,next))
            {
                PrintBingoCard(a);
                printf("You filled out a row and a column and diagonals- BINGO!!!");
              
            }
            else if(CompletedCol(a)&&CompletedRow(a))
            {
                PrintBingoCard(a);
                printf("You filled out a row and a column- BINGO!!!");
               
                
            }
            else if(CompletedCol(a)&&CompletedDiag(a,next))
            {
                PrintBingoCard(a);
                printf("You filled out a Diagonal and a column- BINGO!!!");
                
                
            }
            else if(CompletedRow(a)&&CompletedDiag(a, next))
            {
                PrintBingoCard(a);
                printf("You filled out a Diagonal and a Row- BINGO!!!");
                
                
            }
            else if(CompletedRow(a))
            {
                PrintBingoCard(a);
                printf("You filled out a Row- BINGO!!!");
                
                
            }
            else if(CompletedCol(a))
            {
                PrintBingoCard(a);
                printf("You filled out a Column- BINGO!!!");
                
                
            }
            else if(CompletedDiag(a, next))
            {
                PrintBingoCard(a);
                printf("You filled out a Diagonal - BINGO!!!");
                
            }

            else
            {
                PrintBingoCard(a);
                count++;// keep track/count up to 75
            }
            
        }
        else
        {
            PrintBingoCard(a);
            count++;// still keep track if the input is not 'y'
            
        }
        
        
        
    }
    
    return EXIT_SUCCESS;
    
}






void FillBingoCard(int num[ROWS][COLS])// int num[][5]
{
    int size=5;
    srand((unsigned int)time(NULL)); // call random numbers
    
    
    for (int i=0; i<size;i++)
    {
        for (int j=0;j<size;j++)
        {
            if(j==0)// the letter "B"
            {
                num[i][j]=(rand()%15)+1;
            }
            else if(j==1)//the letter "I"
            {
                num[i][j]=(rand()%15)+16;
            }
            else if(j==2)//the letter "N"
            {
                num[i][j]=(rand()%15)+31;
            }
            else if(j==3)//the letter "G"
            {
                num[i][j]=(rand()%15)+46;
            }
            else// the letter"O"
            {
                num[i][j]=(rand()%15)+61;
            }
            num[2][2]=0;
            
        }
    }
}

void PrintBingoCard(int A[ROWS][COLS])
{
    srand((unsigned int)time(NULL));
    
    

    printf("\n\n B      I      N      G     O   ");
    printf("\n-------------------------------\n");
    for (int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            if(A[i][j] == 0)
                printf("|%5c", 'X'); //turning every 0 to an char X
            else
                printf("|%5d",A[i][j]);
        }
       
        printf("|\n------------------------------\n");
    }
}
int PickNum(int num[],int count)
{
    int index=0;
    
    srand((unsigned int)time(NULL));
    int num_rad=rand()%75+1;
    while(index<count)//it has be one to run the while loop(0<1) true
    {
        if(num[index]==num_rad)// checking number is in the array
        {
            num_rad=rand()%75+1;// generate a new number that why we called it again
            index=0;// going back to start of the array to zero
        }
        else
        {
            index++; // adds 1 and goes to the next spot
        }
        
    }
    num[count]=num_rad;//saving the value of count on the num and equaling it to numrad;
    
    return num_rad;// returns the number
    
}
int NumExist(int arr[ROWS][COLS],int num)
{
    for(int i=0; i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
           if(arr[i][j]==num)//checking each element number.
           {
               arr[i][j]=0;
               return 1;// returns true
           }
            
        }
    }
    return 0;//returns false
    
}

int CompletedRow(int arr[ROWS][COLS])
{
    int sum=0;
    
    for(int i=0;i<ROWS;i++)
    {
        for (int j=0;j<COLS;j++)
        {
            sum+=arr[i][j];// adding the whole row
            
        }
        if(sum==0)
        {
            return 1;
            
        }
        else
        {
            sum=0;//  resetting the value of sum
            
        }
    }
    
    return 0;
}
int CompletedCol(int arr[ROWS][COLS])
{
    int sum=0;
    
    for(int i=0;i<ROWS;i++)
    {
        for (int j=0;j<COLS;j++)
        {
            sum+=arr[j][i];// adding the whole column
            
        }
        if(sum==0)
        {
            return 1;
            
        }
        else
        {
            sum=0;//  resetting the value of sum
            
        }
    }
    
    return 0;
}
int CompletedDiag(int arr[ROWS][COLS],int num)
{
    for(int i=0;i<ROWS;i++)
    {
        for(int j=0;j<COLS;j++)
        {
            if (arr[i][j]==num)
            {
                while((arr[0][0]==0&&arr[1][1]==0&&arr[3][3]==0&&arr[4][4]==0&&arr[2][2]==0)||(arr[4][0]==0&&arr[3][1]==0&&arr[2][2]==0&&arr[1][3]==0&&arr[0][4]==0))//check diagonal
                      {
                          return 1;
                      }
                    
            }
        }
    }
    return 0;
    
}








