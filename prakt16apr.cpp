
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
	cout<< "������� ����� ����������:  ";
	cin>> j;
	
	ofstream file;
	file.open("file.txt");
	
struct pas bag[5];
	for (int i=0;i<j;i++ ){
		LINEZ;
		cout <<" ���������� � "<< i+1 <<" ���������:"<<'\n'; 
		file << "  ���������� � "<< i+1 <<" ���������:"<<'\n';
		LINEZ;
		cout<<'\n'<<"          �������:            ";
		cin>> bag[i].fam;
		file << "  ������� --       " << bag[i].fam << "|\n" ;
		LINE;
		cout<<"          ���:                ";
		cin>> bag[i].name;
		file <<  "  ��� --           " <<bag[i].name << "|\n" ;
		LINE;
		cout<<"          ��������:           ";
		cin>> bag[i].otc;
		file << "  �������� --      " <<bag[i].otc<< "|\n";
		LINE;
		cout<<"          ��� ������:         ";
		cin>> bag[i].ves;
		file <<   "  ��� ������ --    " <<bag[i].ves<< "|\n";
		LINE;
		cout<<"          ���������� ������:  ";
        cin>> bag[i].kol;
        
        file << "  ���-�� ������ -- "<< bag[i].kol <<"|"<<endl<<endl;
        ;
        LINE;
        

	}
	
	
	for (int i=0;i<j;i++ ){
		if (bag[i].kol > 3){
			a = a+1;
		}
	}
	LINEZ;
	cout<<"����������, � ������� ������ 3 �����:   "<< a<<'\n';
	file<<" ����������, � ������� ������ 3 �����:   "<< a<<endl;
    LINEZ;
    file.close();
    
    cout << "������� ����:"<< endl;LINEZ;
    
    
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
