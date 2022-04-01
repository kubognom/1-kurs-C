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

	printf("Неотсортированный массив: \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array[i]);
			printf("\n\n");
	
	timeOfSortArray = SortOtbor(array, size);

	printf("Отсортированный массив (выбором): \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array[i]);
	printf("\n\n");
	
	timeOfSortArray2 = PSort(array2, size);

	printf("Отсортированный массив (\"Пузырек\"): \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array2[i]);
	printf("\n\n");
		
		
		
		timeOfSortArray3 = SortPerest(array3, size);

	printf("Отсортированный массив (\"Perestanovka\"): \n");
	for (int i = 0; i < size; i++)
		printf("%4d", array3[i]);
	printf("\n\n");
	
	
	
	printf("На сортировку массива методом \"Отбор\" потрачено: %4d временных тактов процессора!\n\n", timeOfSortArray);
	printf("На сортировку массива методом \"Пузырек\" потрачено: %4d временных тактов процессора!\n\n", timeOfSortArray2);
	printf("На сортировку массива методом \"Перестановка\" потрачено: %4d временных тактов процессора!\n\n", timeOfSortArray3); 

	if ((timeOfSortArray < timeOfSortArray2) and (timeOfSortArray < timeOfSortArray3))
	{
		printf("Более эффективным оказался метод сортировки отбором!\n\n");
	}
	
	 if ((timeOfSortArray2 < timeOfSortArray3) and (timeOfSortArray2 < timeOfSortArray))
	{
		printf("Более эффективным оказался метод сортировки пузырьком!\n\n");
	}
	  if ((timeOfSortArray3 < timeOfSortArray) and (timeOfSortArray3 < timeOfSortArray2))
	{
		printf("Более эффективным оказался метод сортировки перестановкой!\n\n");
	}
	
	
	
	
	
	
	if ((timeOfSortArray2 == timeOfSortArray3) and (timeOfSortArray == timeOfSortArray3))
	{
		printf("Эффективность методов сортировки в данном случае равна!\n\n");
	}
	else if  ((timeOfSortArray == timeOfSortArray3) and (timeOfSortArray > timeOfSortArray2))
	{
		printf("Эффективность метода \"Пузырек\" хуже остальных!\n\n");
	}
	else if  ((timeOfSortArray2 == timeOfSortArray3) and (timeOfSortArray2 > timeOfSortArray))
	{
		printf("Эффективность метода \"ОТбор\" хуже остальных!\n\n");
	}
	else if  ((timeOfSortArray == timeOfSortArray2) and (timeOfSortArray3 > timeOfSortArray2))
	{
		printf("Эффективность метода \"Перестановка\" хуже остальных!\n\n");
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
	int startTime = 0; // начальное время работы функции сортировки
	int endTime = 0; // конечное время работы функции сортировки
	int searchTime = 0; //продолжительность работы функции сортировки

	int temp; //буфер
	int i,j;
	

	startTime = clock(); //начинаем отсчет продолжительности сортировки
	
	for (i = Size - 1; i > 0; i--)
		for (j = 0; j < i; j++)
			if (Array2[j] > Array2[j + 1])
			{
				temp = Array2[j];
				Array2[j] = Array2[j + 1];
				Array2[j + 1] = temp;
			}
	endTime = clock(); // конечное время работы функции сортировки

	return searchTime = (endTime - startTime); //искомое время работы функции ;
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
