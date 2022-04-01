#include <stdio.h>
#include <iomanip>
#include <ctime>
#include <cstdlib>

int SortOtbor(int[], int);
int PSort(int[], int);
int SortPerest(int[], int);    


int main()
{

	setlocale(LC_ALL, "rus");

	const int size=1000; 
	int array[size];
	int array2[size];
	int array3[size];

	int timeOfSortArray = 0;
	int timeOfSortArray2 = 0;
	int timeOfSortArray3 = 0;


	srand(time(NULL));

	for (int i = 0; i < size; i++)
	{
		array[i] = 1 + rand() % 800;
		array2[i] = array[i];
		array3[i] = array[i];
	}

	printf("����������������� ������: \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array[i]);
			printf("\n\n");
	
	timeOfSortArray = SortOtbor(array, size);

	printf("��������������� ������ (�������): \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array[i]);
	printf("\n\n");
	
	timeOfSortArray2 = PSort(array2, size);

	printf("��������������� ������ (\"�������\"): \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array2[i]);
	printf("\n\n");
		
		
		
		timeOfSortArray3 = SortPerest(array3, size);

	printf("��������������� ������ (\"Perestanovka\"): \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array3[i]);
	printf("\n\n");
	
	
	
	printf("�� ���������� ������� ������� \"�����\" ���������: %4d ��������� ������ ����������!\n\n", timeOfSortArray);
	printf("�� ���������� ������� ������� \"�������\" ���������: %4d ��������� ������ ����������!\n\n", timeOfSortArray2);
	printf("�� ���������� ������� ������� \"������������\" ���������: %4d ��������� ������ ����������!\n\n", timeOfSortArray3); 

	if ((timeOfSortArray < timeOfSortArray2) and (timeOfSortArray < timeOfSortArray3))
	{
		printf("����� ����������� �������� ����� ���������� �������!\n\n");
	}
	
	 if ((timeOfSortArray2 < timeOfSortArray3) and (timeOfSortArray2 < timeOfSortArray))
	{
		printf("����� ����������� �������� ����� ���������� ���������!\n\n");
	}
	  if ((timeOfSortArray3 < timeOfSortArray) and (timeOfSortArray3 < timeOfSortArray2))
	{
		printf("����� ����������� �������� ����� ���������� �������������!\n\n");
	}
	
	
	
	
	
	
	if ((timeOfSortArray2 == timeOfSortArray3) and (timeOfSortArray == timeOfSortArray3))
	{
		printf("������������� ������� ���������� � ������ ������ �����!\n\n");
	}
	else if  ((timeOfSortArray == timeOfSortArray3) and (timeOfSortArray > timeOfSortArray2))
	{
		printf("������������� ������ \"�������\" ���� ���������!\n\n");
	}
	else if  ((timeOfSortArray2 == timeOfSortArray3) and (timeOfSortArray2 > timeOfSortArray))
	{
		printf("������������� ������ \"�����\" ���� ���������!\n\n");
	}
	else if  ((timeOfSortArray == timeOfSortArray2) and (timeOfSortArray3 > timeOfSortArray2))
	{
		printf("������������� ������ \"������������\" ���� ���������!\n\n");
	}
	 
	

	return 0;
}

int SortOtbor(int Array[], int Size)
{
	int startTime = 0; 
	int endTime = 0; 
	int searchTime = 0; 

	int min; 
	int index;
	int temp; 

	startTime = clock(); 
	for (int i = Size - 1; i >= 1; i--)
	{
		
		min = Array[i];
		index = i;

		
		for (int j = i - 1; j >= 0; j--)
		{
		
			if (min > Array[j])
			{
				
				min = Array[j];
				index = j;
			}
		}

		
		temp = Array[index];

		for (int x = index; x < i; x++)
		{
			Array[x] = Array[x + 1];
		}

		Array[i] = temp;
	}
	endTime = clock(); 

	return searchTime = (endTime - startTime); 
}

int PSort(int Array2[], int Size)
{
	int startTime = 0; // ��������� ����� ������ ������� ����������
	int endTime = 0; // �������� ����� ������ ������� ����������
	int searchTime = 0; //����������������� ������ ������� ����������

	int temp; //�����
	int i,j;
	

	startTime = clock(); //�������� ������ ����������������� ����������
	
	for (i = Size - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (Array2[j] > Array2[j + 1])
			{
				temp = Array2[j];
				Array2[j] = Array2[j + 1];
				Array2[j + 1] = temp;
			}
	endTime = clock(); // �������� ����� ������ ������� ����������

	return searchTime = (endTime - startTime); //������� ����� ������ ������� ;
}
int SortPerest(int Array3[], int Size)
{
	int startTime = 0; 
	int endTime = 0; 
	int searchTime = 0; 


	int temp; 

	startTime = clock(); 
	for (int i = 0; i < Size-1; i++){

for (int j = i+1; j < Size; j++){

if (Array3[i]>Array3[j]){

temp = Array3[j];

Array3[j] = Array3[i];

Array3[i] = temp;

}

}

}
	endTime = clock(); 

	return searchTime = (endTime - startTime); 
}
