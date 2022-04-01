
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#define LINE  cout << "          _____________________________________"<< '\n'
#define LINEZ  cout << "*************************************"<<'\n'
struct pas {
    
	char fam[15];
	char name[10];
	char otc[15];
	int ves;
	int kol;
	};
	
int main() {
	

	//SetConsoleCP(1251);
   // SetConsoleOutputCP(1251);
    
	int a = 0;
	int j;
	LINEZ;
	cout<< "Введите число пассажиров:  ";
	cin>> j;
	
	ofstream file;
	file.open("file.txt");
	
struct pas bag[5];
	for (int i=0;i<j;i++ ){
		LINEZ;
		cout <<" Информация о "<< i+1 <<" пассажире:"<<'\n'; 
		file << "  Информация о "<< i+1 <<" пассажире:"<<'\n';
		LINEZ;
		cout<<'\n'<<"          Фамилия:            ";
		cin>> bag[i].fam;
		file << "  Фамилия --       " << bag[i].fam << "|\n" ;
		LINE;
		cout<<"          имя:                ";
		cin>> bag[i].name;
		file <<  "  имя --           " <<bag[i].name << "|\n" ;
		LINE;
		cout<<"          отчество:           ";
		cin>> bag[i].otc;
		file << "  Отчество --      " <<bag[i].otc<< "|\n";
		LINE;
		cout<<"          Вес багажа:         ";
		cin>> bag[i].ves;
		file <<   "  Вес багажа --    " <<bag[i].ves<< "|\n";
		LINE;
		cout<<"          Количество багажа:  ";
        cin>> bag[i].kol;
        
        file << "  Кол-во багажа -- "<< bag[i].kol <<"|"<<endl<<endl;
        ;
        LINE;
        

	}
	
	
	for (int i=0;i<j;i++ ){
		if (bag[i].kol > 3){
			a = a+1;
		}
	}
	LINEZ;
	cout<<"Пассажиров, у которых больше 3 сумок:   "<< a<<'\n';
	file<<" Пассажиров, у которых больше 3 сумок:   "<< a<<endl;
    LINEZ;
    file.close();
    
    cout << "Выводим файл:"<< endl;LINEZ;
    
    
    char buff[256];
    ifstream file1;
	file1.open("file.txt");
	while (!file1.eof())
           {
             file1.getline(buff,256); 
             cout<<buff<<endl; 
           }
    file1.close();       
}
