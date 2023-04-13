#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** create_matrix(int row, int col); //동적할당을 이용하여 행렬을 생성하는 함수
void print_matrix(int** matrix, int row, int col); //행렬을 출력하는 함수
int free_matrix(int** matrix, int row); //동적할당을 해제하는 함수
void addition_matrix(int** matrix_a, int** matrix_b, int row, int col, int row_x, int col_x); //두 행렬의 합을 구하는 함수
void subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col, int row_x, int col_x); //두 행렬의 차를 구하는 함수
void transpose_matrix(int** matrix, int row, int col); //전치행렬을 생성하는 함수
void multiply_matrix(int** matrix_a, int** matrix_b, int row_a, int col_a, int row_b, int col_b);//두 행렬의 곱을 구하는 함수

int main()
{

    printf("[----- [박에스더]  [2022041054] -----]\n"); 

    srand((unsigned)time(NULL));//srand를 선언하여 난수생성 시 항상 새로운 난수 값을 받을 수 있도록 한다
   int row_a, row_b, col_a, col_b;
   
   while(1){
   printf("행렬 A의 행: "); 
   scanf("%d", &row_a); //행렬 A의 행 개수 입력받기
   printf("행렬 A의 열: "); 
   scanf("%d", &col_a); //행렬 A의 열 개수 입력받기
   printf("행렬 B의 행: ");
   scanf("%d", &row_b); //행렬 B의 행 개수 입력받기
   printf("행렬 B의 열: ");
   scanf("%d", &col_b); //행렬 B의 열 개수 입력받기
   if(row_a<=0||col_a<=0||row_b<=0||col_b<=0) //행과 열이 음수나 0인 경우 다시 입력
   {
      printf("다시 입력해주세요 ");
   }
   else{break;} 
   }
   
    int **matrix_a = create_matrix(row_a, col_a); //2중포인터 matrix_a를 create_matrix함수를 이용하여 동적할당
    int **matrix_b = create_matrix(row_b, col_b); //2중포인터 matrix_b를 create_matrix함수를 이용하여 동적할당

   
   printf("행렬 A:\n");
   print_matrix(matrix_a, row_a, col_a); //print_matrix 함수를 이용해 A 행렬 출력
   printf("행렬 B:\n");
   print_matrix(matrix_b, row_b, col_b); //print_matrix 함수를 이용해 B 행렬 출력

   addition_matrix(matrix_a, matrix_b, row_a, col_a, row_b, col_b); //addition_matrix함수를 이용해 두 행렬의 합 출력
   subtraction_matrix(matrix_a,matrix_b, row_a,col_a,row_b,col_b); //subtraction_matrix함수를 이용해 두 행렬의 차 출력
   transpose_matrix(matrix_a, row_a, col_a); //transpose_matrix함수를 이용해 행렬 A의 전치행렬 출력
   multiply_matrix(matrix_a, matrix_b, row_a, col_a, row_a, col_b); //multiply_matrix함수를 이용해 두 행렬의 곱 출력

   return 0;
    
}

int** create_matrix(int row, int col)//이중포인터를 동적 메모리 할당을 하는 함수
{
    int** matrix = (int**)malloc(sizeof(int*) * row); //matrix를 동적메모리 할당
    for (int i = 0; i < row; i++)
     {  
         matrix[i] = (int*)malloc(sizeof(int) * col);//matrix[i]를 동적메모리 할당
     }

   for(int i=0; i<row; i++)
{
   for(int j=0; j<col; j++)
      {matrix[i][j]=(rand()%20);} //rand 함수를 이용해 matrix[i][j]에 임의의 값을 저장
}
    return matrix; //matrix로 리턴
}

void print_matrix(int** matrix, int row, int col) //행렬을 출력하는 함수
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d\t", matrix[i][j]); //반복문을 이용하여 **matrix를 출력한다
    
   printf("\n");
    }
   
}

int free_matrix(int** matrix, int row) //동적할당된 메모리를 해제하는 함수
{
    for (int i = 0; i < row; i++)
        free(matrix[i]);//반복문을 이용하여 matrix[i] 메모리 해제
    free(matrix); //matrix 메모리 해제
    return 0;
}

void addition_matrix(int** matrix_a, int** matrix_b, int row, int col, int row_x, int col_x) //두 행렬의 합을 구하는 함수
{
   if((row==row_x)&&(col==col_x))
   {
    int** matrix_sum= create_matrix(row, col); //**matrix_sum을 동적메모리 할당
    for (int i = 0; i < row; i++)
      { { for (int j = 0; j < col; j++)
            matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];} }//반복문을 이용하여 matrix_sum에 matrix_a,b의 합 저장
 
    printf("Add matrix:A+B\n");
   print_matrix(matrix_sum, row, col);//print_matrix 함수를 호출하여 matrix_sum 출력
   free_matrix(matrix_sum, row);//free_matrix 함수를 호출하여 matrix_sum메모리 해제
 
   }    
   else{
      printf("Add matrix:A+B\n");
      printf("크기가 맞지 않음!!\n");
   }
  
   
}

void subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col, int row_x, int col_x) //두 행렬의 차를 구하는 함수
{
   if((row==row_x)&&(col==col_x))
   {
    int** matrix_sub = create_matrix(row, col); //**matrix_sub를 동적메모리 할당
   
    for (int i = 0; i < row; i++)
     {  { for (int j = 0; j < col; j++)
            matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];}}//반복문을 이용하여 matrix_sub에 matrix_a,b의 차 저장

   printf("Subtract matrix:A-B\n");
   print_matrix(matrix_sub, row, col);//print_matrix 함수를 호출하여 matrix_sub출력
   free_matrix(matrix_sub, row);//free_matrix 함수를 호출하여 matrix_sub메모리 해제
   
   }
   else {
      printf("Subtract matrix:A-B\n");
      printf("행렬 크기가 맞지 않음!!\n");
   }
   
}

void transpose_matrix(int** matrix, int row, int col) //전치행렬을 구하는 함수
{
   printf("A의 전치행렬\n");
    for (int i = 0; i < col; i++)
        {for (int j = 0; j < row; j++)
             {printf("%d\t",matrix[j][i] );}//반복문을 이용하여 전치행렬을 구한다
             printf("\n");
        }
   
}

void multiply_matrix(int** matrix_a, int** matrix_b, int row_a, int col_a, int row_b, int col_b)//행렬의 곱을 구하는 함수
{
  if(col_a==row_b) //행렬 A의 열과 행렬 B의 행이 같을 때
  {
   int **matrix_axb=create_matrix(row_a, col_b); // **matrix_axb를 동적 메모리 할당
   for(int i=0; i<row_a; i++)
   {
      for(int j=0; j<col_b; j++)
      {
        matrix_axb[i][j]=0;
         for(int k=0; k<col_a; k++)
         matrix_axb[i][j]+=matrix_a[i][k]*matrix_b[k][j]; //반복문을 이용해 행렬의 곱을 matrix_axb에 저장
      }
   
   } 
   printf("multiply matrix:AxB\n");
   print_matrix(matrix_axb, row_a, col_b);//print_matrix 함수를 호출하여 matrix_axb출력
   free_matrix(matrix_axb, row_a);//free_matrix 함수를 호출하여 matrix_axb메모리 해제
  }
   else{
      printf("multiply matrix:AxB\n");
      printf("크기가 맞지 않음!!\n");
   }
  
  
}