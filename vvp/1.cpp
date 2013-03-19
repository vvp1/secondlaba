#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
 void qSort(int A[], int low, int high)///������� ����������
{
      int i = low;///low-������ �������                
      int j = high;///high-������� �������
      int x = A[(low+high)/2];  /// x - ������� ������� ��������� ����� low � high
      do 
	  {
          while(A[i] < x) ++i;  /// ����� �������� ��� �������� � ������� �����
          while(A[j] > x) --j;  /// ����� �������� ��� �������� � ������� �����
          if(i <= j)
		  {           
              /// ����� ��������� �������:
              int temp = A[i];
              A[i] = A[j];
              A[j] = temp;
              /// ������� � ��������� ���������:
              i++; j--;
          }
      } while(i < j);
      if(low < j) qSort(A, low, j);
      if(i < high) qSort(A, i, high);
  }
int main()///������� �������
{
	int n,z;///���������� ��������������� ����������
	cout<<"input size of massive:";///���� ����������� �������
	cin>>n;
	cout<<"\n";
	int *A;///���������� �������
	A = new int[n];///�������� ������������� �������
	for(z=0;z<n;++z)///���������� � ���� �������
	{
		A[z]=rand()%10;
		cout<<A[z]<<" ";
	}
	qSort(A,0,n);
	cout<<"\n";
	for(z=1;z<=n;++z)///����� ����������������
	{
		cout<<A[z]<<" ";
	}
	delete A;
	return 0;
}