#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
 void qSort(int A[], int low, int high)///функци€ сортировки
{
      int i = low;///low-нижн€€ граница                
      int j = high;///high-верхн€€ граница
      int x = A[(low+high)/2];  /// x - опорный элемент посредине между low и high
      do 
	  {
          while(A[i] < x) ++i;  /// поиск элемента дл€ переноса в старшую часть
          while(A[j] > x) --j;  /// поиск элемента дл€ переноса в младшую часть
          if(i <= j)
		  {           
              /// обмен элементов местами:
              int temp = A[i];
              A[i] = A[j];
              A[j] = temp;
              /// переход к следующим элементам:
              i++; j--;
          }
      } while(i < j);
      if(low < j) qSort(A, low, j);
      if(i < high) qSort(A, i, high);
  }
int main()///главна€ функци€
{
	int n,z;///объ€вление вспомогательных переменных
	cout<<"input size of massive:";///ввод размерности массива
	cin>>n;
	cout<<"\n";
	int *A;///объ€вление массива
	A = new int[n];///создание динамичсекого массива
	for(z=0;z<n;++z)///заполнение и ввод массива
	{
		A[z]=rand()%10;
		cout<<A[z]<<" ";
	}
	qSort(A,0,n);
	cout<<"\n";
	for(z=1;z<=n;++z)///вывод отсортированного
	{
		cout<<A[z]<<" ";
	}
	delete A;
	return 0;
}