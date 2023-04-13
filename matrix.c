#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** create_matrix(int row, int col); //�����Ҵ��� �̿��Ͽ� ����� �����ϴ� �Լ�
void print_matrix(int** matrix, int row, int col); //����� ����ϴ� �Լ�
int free_matrix(int** matrix, int row); //�����Ҵ��� �����ϴ� �Լ�
void addition_matrix(int** matrix_a, int** matrix_b, int row, int col, int row_x, int col_x); //�� ����� ���� ���ϴ� �Լ�
void subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col, int row_x, int col_x); //�� ����� ���� ���ϴ� �Լ�
void transpose_matrix(int** matrix, int row, int col); //��ġ����� �����ϴ� �Լ�
void multiply_matrix(int** matrix_a, int** matrix_b, int row_a, int col_a, int row_b, int col_b);//�� ����� ���� ���ϴ� �Լ�

int main()
{

    printf("[----- [�ڿ�����]  [2022041054] -----]\n"); 

    srand((unsigned)time(NULL));//srand�� �����Ͽ� �������� �� �׻� ���ο� ���� ���� ���� �� �ֵ��� �Ѵ�
   int row_a, row_b, col_a, col_b;
   
   while(1){
   printf("��� A�� ��: "); 
   scanf("%d", &row_a); //��� A�� �� ���� �Է¹ޱ�
   printf("��� A�� ��: "); 
   scanf("%d", &col_a); //��� A�� �� ���� �Է¹ޱ�
   printf("��� B�� ��: ");
   scanf("%d", &row_b); //��� B�� �� ���� �Է¹ޱ�
   printf("��� B�� ��: ");
   scanf("%d", &col_b); //��� B�� �� ���� �Է¹ޱ�
   if(row_a<=0||col_a<=0||row_b<=0||col_b<=0) //��� ���� ������ 0�� ��� �ٽ� �Է�
   {
      printf("�ٽ� �Է����ּ��� ");
   }
   else{break;} 
   }
   
    int **matrix_a = create_matrix(row_a, col_a); //2�������� matrix_a�� create_matrix�Լ��� �̿��Ͽ� �����Ҵ�
    int **matrix_b = create_matrix(row_b, col_b); //2�������� matrix_b�� create_matrix�Լ��� �̿��Ͽ� �����Ҵ�

   
   printf("��� A:\n");
   print_matrix(matrix_a, row_a, col_a); //print_matrix �Լ��� �̿��� A ��� ���
   printf("��� B:\n");
   print_matrix(matrix_b, row_b, col_b); //print_matrix �Լ��� �̿��� B ��� ���

   addition_matrix(matrix_a, matrix_b, row_a, col_a, row_b, col_b); //addition_matrix�Լ��� �̿��� �� ����� �� ���
   subtraction_matrix(matrix_a,matrix_b, row_a,col_a,row_b,col_b); //subtraction_matrix�Լ��� �̿��� �� ����� �� ���
   transpose_matrix(matrix_a, row_a, col_a); //transpose_matrix�Լ��� �̿��� ��� A�� ��ġ��� ���
   multiply_matrix(matrix_a, matrix_b, row_a, col_a, row_a, col_b); //multiply_matrix�Լ��� �̿��� �� ����� �� ���

   return 0;
    
}

int** create_matrix(int row, int col)//���������͸� ���� �޸� �Ҵ��� �ϴ� �Լ�
{
    int** matrix = (int**)malloc(sizeof(int*) * row); //matrix�� �����޸� �Ҵ�
    for (int i = 0; i < row; i++)
     {  
         matrix[i] = (int*)malloc(sizeof(int) * col);//matrix[i]�� �����޸� �Ҵ�
     }

   for(int i=0; i<row; i++)
{
   for(int j=0; j<col; j++)
      {matrix[i][j]=(rand()%20);} //rand �Լ��� �̿��� matrix[i][j]�� ������ ���� ����
}
    return matrix; //matrix�� ����
}

void print_matrix(int** matrix, int row, int col) //����� ����ϴ� �Լ�
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            printf("%d\t", matrix[i][j]); //�ݺ����� �̿��Ͽ� **matrix�� ����Ѵ�
    
   printf("\n");
    }
   
}

int free_matrix(int** matrix, int row) //�����Ҵ�� �޸𸮸� �����ϴ� �Լ�
{
    for (int i = 0; i < row; i++)
        free(matrix[i]);//�ݺ����� �̿��Ͽ� matrix[i] �޸� ����
    free(matrix); //matrix �޸� ����
    return 0;
}

void addition_matrix(int** matrix_a, int** matrix_b, int row, int col, int row_x, int col_x) //�� ����� ���� ���ϴ� �Լ�
{
   if((row==row_x)&&(col==col_x))
   {
    int** matrix_sum= create_matrix(row, col); //**matrix_sum�� �����޸� �Ҵ�
    for (int i = 0; i < row; i++)
      { { for (int j = 0; j < col; j++)
            matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];} }//�ݺ����� �̿��Ͽ� matrix_sum�� matrix_a,b�� �� ����
 
    printf("Add matrix:A+B\n");
   print_matrix(matrix_sum, row, col);//print_matrix �Լ��� ȣ���Ͽ� matrix_sum ���
   free_matrix(matrix_sum, row);//free_matrix �Լ��� ȣ���Ͽ� matrix_sum�޸� ����
 
   }    
   else{
      printf("Add matrix:A+B\n");
      printf("ũ�Ⱑ ���� ����!!\n");
   }
  
   
}

void subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col, int row_x, int col_x) //�� ����� ���� ���ϴ� �Լ�
{
   if((row==row_x)&&(col==col_x))
   {
    int** matrix_sub = create_matrix(row, col); //**matrix_sub�� �����޸� �Ҵ�
   
    for (int i = 0; i < row; i++)
     {  { for (int j = 0; j < col; j++)
            matrix_sub[i][j] = matrix_a[i][j] - matrix_b[i][j];}}//�ݺ����� �̿��Ͽ� matrix_sub�� matrix_a,b�� �� ����

   printf("Subtract matrix:A-B\n");
   print_matrix(matrix_sub, row, col);//print_matrix �Լ��� ȣ���Ͽ� matrix_sub���
   free_matrix(matrix_sub, row);//free_matrix �Լ��� ȣ���Ͽ� matrix_sub�޸� ����
   
   }
   else {
      printf("Subtract matrix:A-B\n");
      printf("��� ũ�Ⱑ ���� ����!!\n");
   }
   
}

void transpose_matrix(int** matrix, int row, int col) //��ġ����� ���ϴ� �Լ�
{
   printf("A�� ��ġ���\n");
    for (int i = 0; i < col; i++)
        {for (int j = 0; j < row; j++)
             {printf("%d\t",matrix[j][i] );}//�ݺ����� �̿��Ͽ� ��ġ����� ���Ѵ�
             printf("\n");
        }
   
}

void multiply_matrix(int** matrix_a, int** matrix_b, int row_a, int col_a, int row_b, int col_b)//����� ���� ���ϴ� �Լ�
{
  if(col_a==row_b) //��� A�� ���� ��� B�� ���� ���� ��
  {
   int **matrix_axb=create_matrix(row_a, col_b); // **matrix_axb�� ���� �޸� �Ҵ�
   for(int i=0; i<row_a; i++)
   {
      for(int j=0; j<col_b; j++)
      {
        matrix_axb[i][j]=0;
         for(int k=0; k<col_a; k++)
         matrix_axb[i][j]+=matrix_a[i][k]*matrix_b[k][j]; //�ݺ����� �̿��� ����� ���� matrix_axb�� ����
      }
   
   } 
   printf("multiply matrix:AxB\n");
   print_matrix(matrix_axb, row_a, col_b);//print_matrix �Լ��� ȣ���Ͽ� matrix_axb���
   free_matrix(matrix_axb, row_a);//free_matrix �Լ��� ȣ���Ͽ� matrix_axb�޸� ����
  }
   else{
      printf("multiply matrix:AxB\n");
      printf("ũ�Ⱑ ���� ����!!\n");
   }
  
  
}