
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
using namespace std;

struct st {
	int id;
	char name[15];
	char secname[25];
	char dad[20];
	int chislo;
	int month;
	int year;
	int post;
	char facult[70];
	char cafed[6];
	char gr[15];
	char number[10];
	int sex;
	int ses,ls;
	int mark[9][10];
	char less[10][10][10];
	
};

void finder(int n){
	int f_id,fmen,end,chet,enddd;
	fmen = 0;
	st stud;
	FILE *f;
	int i;
	
	char elem[15];
	if(n==1){
	chet=0;
	cout << "  Элемент для поиска:\n>>  ";
	cin >> elem;
	
		f=fopen("1.bin", "ab+");
		
	while (!feof(f))
    {
	
 
    if(fread(&stud, sizeof(st), 1, f)){
    
    if ((strcmp(stud.number, elem) == 0)||(strcmp(stud.secname, elem) == 0)  ){
          
cout<<endl <<setw(4)<<stud.id<<' '<<setw(15)<<left<< stud.name<<setw(25)<<left<<stud.secname<<"  "<< stud.dad<<endl
	<<"     "<<stud.chislo<<'.'<<stud.month<<'.'<<stud.year<<"      ";
	if(stud.sex==0) cout << "Женский    "; else if(stud.sex==1) cout << "Мужской    "; else cout<< "удален    ";
	cout << stud.post<<"   "<<stud.number<<"   "<<endl<<"     "<<stud.facult<<"  "<<stud.cafed<<"  "<<stud.gr;
    for (int i=0;i <stud.ses;i++){
    	cout <<"\n        "<<  i+1 << " сессия:";
    	for ( int j=0;j <stud.ls;j++){
    		cout <<"\n     "<<j+1<<' '<<stud.less[i][j]<< ": -- "<<stud.mark[i][j];
    	}}    
	f_id=stud.id-1;
    chet=chet+1; 
    
    }}
    
	}
	fclose(f);}
	
	if(n==3){ 
	
	if(chet!=1){
		cout <<"\n!Имеются одинаковые элементы, воспользуйтесь корректировкой по id(--2)\n";
	} else {
	f=fopen("1.bin", "ab+");	
	fseek(f, (f_id-1)*sizeof(st), SEEK_SET);
	fread(&stud, sizeof(st), 1, f);
    fclose(f);
		 
    cout << "  \nКакой элемент изменить?\n11-Имя  12-Фамилию  13-Отчество  14-Пол  21-число рождения  22-месяц  23-год"<<
	"\n31-год поступления  32-номер билета  33-Факультет  34-Кафедру  35-Группу\n 41-оценки(все оценки будут перезаписаны)\n>>";		
		fmen=0;
		cin >> fmen;if(cin.fail())exit(0);
	switch(fmen){   
    case 11: cout << ">>"; cin >> stud.name;
    if(strlen(stud.name)>15){ cout << "XXX Превышено максимальное число символов - 15\n"; break;} break;
    case 12: cout << ">>"; cin >> stud.secname;    
	if(strlen(stud.secname)>25){ cout << "  XXX Превышено максимальное число символов - 25\n"; break;}break;
    case 13: cout << ">>";cin >> stud.dad;
    if(strlen(stud.dad)>20){ cout << "   XXX Превышено максимальное число символов - 20\n"; break;} break;
    case 14:cout << ">>"; cin >> stud.sex;if(cin.fail())exit(0);
    if((stud.sex>1)||(stud.sex<0)){cout<< "    XXX Неверно введен пол\n";break;    } break;
    case 21:cout << ">> (1-М;0-Ж)";cin >> stud.chislo;if(cin.fail())exit(0);
	if((stud.chislo>31)||(stud.chislo<1)){cout << "XXX  Введено неверное число\n"; break;} break;
    case 22:cout << ">>"; cin >> stud.month;if(cin.fail())exit(0);
	if((stud.month>12)||(stud.month<1)){cout << " XXX  Введен неверный месяц\n"; break;} break;
    case 23:cout << ">>"; cin >> stud.year;if(cin.fail())exit(0);
	if((stud.year>2010)||(stud.year<1940)){cout << "  XXX  Введен неверный год\n"; break;} break;
    case 31:cout << ">>";cin >> stud.post;if(cin.fail())exit(0);
	if((stud.post>2021)||(stud.post<1940)){cout << "XXX  Введен неверный год\n"; break;} break;
    case 32:cout << ">>"; cin >> stud.number;
	if(strlen(stud.number)>10){ cout << " XXX Превышено максимальное число символов - 10\n"; break;} break;
    case 33:cout << ">>";cin.getline((stud.facult), 69);
	cin.getline((stud.facult), 69);
	if(strlen(stud.facult)>69){ cout << "  XXX Превышено максимальное число символов - 70\n"; break;} break;
    case 34:cout << ">>";cin >> stud.cafed;
	if(strlen(stud.cafed)>6){ cout << "   XXX Превышено максимальное число символов - 6\n"; break;} break;
    case 35:cout << ">>";cin >> stud.gr;
	if(strlen(stud.gr)>15){ cout << "    XXX Превышено максимальное число символов - 15\n"; break;} break;
    case 41:cout << "Сколько сессий? >>  ";
    cin >> stud.ses;if(cin.fail())exit(0);
    if(stud.ses>9){ cout << "XXX Превышено максимальное число сессий - 9\n"; break;}
    cout << "       предметов? >>  ";
    cin >> stud.ls;if(cin.fail())exit(0);
    if(stud.ls>10){ cout << "       XXX Превышено максимальное число предметов - 10\n"; break;}
    enddd=0;
    for (int i=0;i <stud.ses;i++){
    	cout <<endl<<  i+1 << " сессия:\n";
    	for ( int j=0;j <stud.ls;j++){
    		cout << j+1<<"й предмет(сокращ.) >> ";
    		cin >> stud.less[i][j];
    		if(strlen(stud.less[i][j])>15){ cout << "XXX Превышено максимальное число символов - 15\n"; enddd=1;break;}
    		cout <<      "      Оценка >>  ";
    		cin >> stud.mark[i][j];if(cin.fail())exit(0);
    		if((stud.mark[i][j]>5)||(stud.mark[i][j]<2)){ cout << "    XXX Неверная оценка(2--5)\n"; enddd=1;break;}
    	}
    if(enddd==1) break;
    }
    }
		 f=fopen("1.bin", "r+b");	
	fseek(f, (f_id-1)*sizeof(st), SEEK_SET);
    fwrite(&stud, sizeof(st), 1, f);
    fclose(f);
	}}
	
}
int main() {
	st stud;
	FILE *f;
	int mm, min,min2,min3, id,endd;
    stud.id = 0;
    char find[22];
while (mm!=3){
	min = 0;
	cout << "1 -- Работа с учениками  |  2 -- Работа с файлом  |\n3 -- Выход               |  4 -- решить вариант 40";
cout << "\n>>   ";
cin >> mm;
if(cin.fail()) mm=3;
if(mm==4){//решение варианта
	FILE *f2;
	int summa,idd,s_id,j,n;
	
	cout << "По какому полу сортировать?(1-М,0-Ж)";
	cin >> min;
	if(cin.fail())mm=3;
	if((min!=0)&&(min!=1)){cout<<"XXX Неверно введен пол"; break;	}
	cout << "По какой сессии:";
	cin >> min2;
	if(cin.fail())mm=3;
	if((min2<1)||(min2>9)){cout<<"XXX Неверно введена сессия(макс.9)";break;	}
	s_id = 0;
		f=fopen("1.bin", "rb+");
    	
    	
    	while(!feof(f)){
    	
    if (fread(&stud, sizeof(st), 1, f)){
    summa=0;
    
    	if(min==stud.sex){
    	
    	for ( j=0;j <stud.ls;j++){
    		
    		summa=summa+stud.mark[min2-1][j];
    	}
    summa=summa/stud.ls;
    idd=stud.id;
    s_id+=1;
    cout<<endl<<idd<<"й ученик - средн.усп:  "<<summa;
            
            f2=fopen("2.bin", "ab+");
    		fwrite(&summa, sizeof(int), 1, f2);
    		fwrite(&idd, sizeof(int), 1, f2);
    		fclose(f2);
    		
    
    }  } else {
           
           cout << endl;
           break;
}
	}

	
	fclose(f);
	int arr[s_id];
	int temp;
	f2=fopen("2.bin", "ab+");
	for(int i=0;i<s_id;i++){
		if (fread(&summa, sizeof(int), 1, f2)){
			if (fread(&idd, sizeof(int), 1, f2)){
			arr[i]=summa*1000+idd;
			
			
			
		}
		}
	}
	
	for (int i = 0; i < s_id-1; i++) {
        for (int j = 0; j < s_id-1 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
	fclose(f2);
	f=fopen("1.bin", "ab+");
	for(int i=0; i<s_id;i++){
		id=arr[i]%1000;
		
	fseek(f, (id-1)*sizeof(st), SEEK_SET); 
    fread(&stud, sizeof(st), 1, f); 
    cout<<endl <<setw(4)<<stud.id<<' '<<setw(15)<<left<< stud.name<<setw(25)<<left<<stud.secname<<"  "<< stud.dad<<endl
	<<"     "<<stud.chislo<<'.'<<stud.month<<'.'<<stud.year<<"      ";
	if(stud.sex==0) cout << "Женский    "; else if(stud.sex==1) cout << "Мужской    "; else cout<< "удален    ";
	cout << stud.post<<"   "<<stud.number<<"   "<<endl<<"     "<<stud.facult<<"  "<<stud.cafed<<"  "<<stud.gr;
    for (int i=0;i <stud.ses;i++){
    	cout <<"\n        "<<  i+1 << " сессия:";
    	for ( int j=0;j <stud.ls;j++){
    		cout <<"\n     "<<j+1<<' '<<stud.less[i][j]<< ": -- "<<stud.mark[i][j]<<endl;
    	}}
   
   id=0;
     
	}
	fclose(f);  
	min =0;
	char filename2[10] = "2.bin";
    remove(filename2);
}
if(mm == 2){
	while (min!= 3){
	
	cout << "1 -- Вывести весь файл  | 2 -- Удалить файл  |  3  -- Выход \n>>  ";
    cin >> min;if(cin.fail())exit(0);
    if (min == 1){
    	f=fopen("1.bin", "ab+");
    	
    	
    	while(!feof(f)){
    	
    if (fread(&stud, sizeof(st), 1, f)){
    
    
cout<<endl <<setw(4)<<stud.id<<' '<<setw(15)<<left<< stud.name<<setw(25)<<left<<stud.secname<<"  "<< stud.dad<<endl
	<<"     "<<stud.chislo<<'.'<<stud.month<<'.'<<stud.year<<"      ";
	if(stud.sex==0) cout << "Женский    "; else if(stud.sex==1) cout << "Мужской    "; else cout<< "удален    ";
	cout << stud.post<<"   "<<stud.number<<"   "<<endl<<"     "<<stud.facult<<"  "<<stud.cafed<<"  "<<stud.gr;
    for (int i=0;i <stud.ses;i++){
    	cout <<"\n        "<<  i+1 << " сессия:";
    	for ( int j=0;j <stud.ls;j++){
    		cout <<"\n     "<<j+1<<' '<<stud.less[i][j]<< ": -- "<<stud.mark[i][j];
    	}}
        }   else {
           
           cout << endl;
           break;
}
	}
	fclose(f);
	min =0;
}
    if(min == 2){
    char filename[10] = "1.bin";
    	
    remove(filename);
    stud.id=0;  	

    	cout << "  Файл успешно удален\n";
    	min = 3;
    }
}

	
}
	
if(mm == 1){

	while (min!=5){
	
cout << "\n1 -- Добавить ученика  |  2 -- Вывести ученика  | \n3 -- Удалить ученика   |  4 -- Изменить ученика |  \n5 -- Выход\n>>   ";

cin >> min;if(cin.fail())exit(0);
if (min == 1){
	
	f=fopen("1.bin", "ab+");
	   while(!feof(f)) fread(&stud, sizeof(st), 1, f);
	   
	cout <<"Имя >>  ";
    cin >> stud.name;
    if(strlen(stud.name)>15){ cout << "XXX Превышено максимальное число символов - 15\n"; break;}
    cout <<" Фамилия >>  ";
    cin >> stud.secname;    
	if(strlen(stud.secname)>25){ cout << "  XXX Превышено максимальное число символов - 25\n"; break;}
    cout <<"  Отчество >>  ";
    cin >> stud.dad;
    if(strlen(stud.dad)>20){ cout << "   XXX Превышено максимальное число символов - 20\n"; break;}
    cout <<"   Пол(1-М,0-Ж)>>  ";
	cin >> stud.sex;if(cin.fail())exit(0);
    if((stud.sex>1)||(stud.sex<0)){cout<< "    XXX Неверно введен пол\n";break;    }
    
	cout <<"Дата рождения - число >>  ";
	cin >> stud.chislo;if(cin.fail())exit(0);
	if((stud.chislo>31)||(stud.chislo<1)){cout << "XXX  Введено неверное число\n"; break;}
	cout <<"    (цифрами)   - месяц >>  ";
	cin >> stud.month;if(cin.fail())exit(0);
	if((stud.month>12)||(stud.month<1)){cout << " XXX  Введен неверный месяц\n"; break;}
	cout <<"                   - год >>  ";
	cin >> stud.year;if(cin.fail())exit(0);
	if((stud.year>2010)||(stud.year<1940)){cout << "  XXX  Введен неверный год\n"; break;}
	
	cout <<"Год поступления >>  ";
	cin >> stud.post;if(cin.fail())exit(0);
	if((stud.post>2021)||(stud.post<1940)){cout << "XXX  Введен неверный год\n"; break;}
	cout <<"   Номер зачетки >>  ";
	cin >> stud.number;
	if(strlen(stud.number)>10){ cout << " XXX Превышено максимальное число символов - 10\n"; break;}
	cout <<"        Факультет >>  ";
	cin.getline((stud.facult), 69);
	cin.getline((stud.facult), 69);
	if(strlen(stud.facult)>69){ cout << "  XXX Превышено максимальное число символов - 70\n"; break;}
	cout <<"(сокращ.)  Кафедра >>  ";
	cin >> stud.cafed;
	if(strlen(stud.cafed)>6){ cout << "   XXX Превышено максимальное число символов - 6\n"; break;}
	cout <<"             Группа >>  ";
	cin >> stud.gr;
	if(strlen(stud.gr)>15){ cout << "    XXX Превышено максимальное число символов - 15\n"; break;}
	cout << "Сколько сессий? >>  ";
    cin >> stud.ses;if(cin.fail())exit(0);
    if(stud.ses>9){ cout << "XXX Превышено максимальное число сессий - 9\n"; break;}
    cout << "       предметов? >>  ";
    cin >> stud.ls;if(cin.fail())exit(0);
    if(stud.ls>10){ cout << "       XXX Превышено максимальное число предметов - 10\n"; break;}
    endd=0;
    for (int i=0;i <stud.ses;i++){
    	cout <<endl<<  i+1 << " сессия:\n";
    	for ( int j=0;j <stud.ls;j++){
    		cout << j+1<<"й предмет(сокращ.) >> ";
    		cin >> stud.less[i][j];if(cin.fail())exit(0);
    		if(strlen(stud.less[i][j])>15){ cout << "XXX Превышено максимальное число символов - 15\n"; endd=1;break;}
    		cout <<      "      Оценка >>  ";
    		cin >> stud.mark[i][j];if(cin.fail())exit(0);
    		if((stud.mark[i][j]>5)||(stud.mark[i][j]<2)){ cout << "    XXX Неверная оценка(2--5)\n"; endd=1;break;}
    	}
    if(endd==1) break;
    }
    
	   
	   stud.id = stud.id+1;
	   fwrite(&stud, sizeof(st), 1, f); 
	   fclose(f);
}
if (min == 2){
	min2 = 0;
	
	cout << "\n1 -- По элементу  |  2 -- По id  | 3 -- Назад \n>>  ";
	cin >> min2;if(cin.fail())exit(0);
	
	if(min2 == 2 ){
		cout << "  Введите id студента >>  ";
		cin >> id;if(cin.fail())exit(0);
	f=fopen("1.bin", "ab+");
	fseek(f, (id-1)*sizeof(st), SEEK_SET); 
    fread(&stud, sizeof(st), 1, f); 
    cout<<endl <<setw(4)<<stud.id<<' '<<setw(15)<<left<< stud.name<<setw(25)<<left<<stud.secname<<"  "<< stud.dad<<endl
	<<"     "<<stud.chislo<<'.'<<stud.month<<'.'<<stud.year<<"      ";
	if(stud.sex==0) cout << "Женский    "; else if(stud.sex==1) cout << "Мужской    "; else cout<< "удален    ";
	cout << stud.post<<"   "<<stud.number<<"   "<<endl<<"     "<<stud.facult<<"  "<<stud.cafed<<"  "<<stud.gr;
    for (int i=0;i <stud.ses;i++){
    	cout <<"\n        "<<  i+1 << " сессия:";
    	for ( int j=0;j <stud.ls;j++){
    		cout <<"\n     "<<j+1<<' '<<stud.less[i][j]<< ": -- "<<stud.mark[i][j];
    	}}
   
   id=0;
   fclose(f);    
   min2 = 3;
}
	if(min2 == 1 ){
	finder(1);
	

	
	    
    min2 = 3;
}
}



if(min==4){
	min2=0;
	while (min2 !=3){
	
	cout << "\n1 -- По совпадению  |  2 -- По id  | 3 -- Назад \n>>  ";
	cin >> min2;if(cin.fail())exit(0);
		if(min2 == 1 ){
	finder(1);
	finder(3);
  
    id =0;
	   
	   min2 = 3;
    min2 = 3;
}
	if(min2 == 2 ){
		cout << "  Введите id студента >>  ";
		cin >> id;if(cin.fail())exit(0);
		cout << "  Выбрана строка:";
			f=fopen("1.bin", "ab+");
	fseek(f, (id-1)*sizeof(st), SEEK_SET); 
    fread(&stud, sizeof(st), 1, f); 
cout<<endl <<setw(4)<<stud.id<<' '<<setw(15)<<left<< stud.name<<setw(25)<<left<<stud.secname<<"  "<< stud.dad<<endl
	<<"     "<<stud.chislo<<'.'<<stud.month<<'.'<<stud.year<<"      ";
	if(stud.sex==0) cout << "Женский    "; else if(stud.sex==1) cout << "Мужской    "; else cout<< "удален    ";
	cout << stud.post<<"   "<<stud.number<<"   "<<endl<<"     "<<stud.facult<<"  "<<stud.cafed<<"  "<<stud.gr;
    for (int i=0;i <stud.ses;i++){
    	cout <<"\n        "<<  i+1 << " сессия:";
    	for ( int j=0;j <stud.ls;j++){
    		cout <<"\n     "<<j+1<<' '<<stud.less[i][j]<< ": -- "<<stud.mark[i][j];
    	}}   
	 fclose(f);
		cout << "  \nКакой элемент изменить?\n11-Имя  12-Фамилию  13-Отчество  14-Пол  21-число рождения  22-месяц  23-год"<<
	"\n31-год поступления  32-номер билета  33-Факультет  34-Кафедру  35-Группу\n 41-оценки(все оценки будут перезаписаны)\n>>";
		min3=0;
		cin >> min3;if(cin.fail())exit(0);
		switch(min3){   
    case 11: cout << ">>"; cin >> stud.name;
    if(strlen(stud.name)>15){ cout << "XXX Превышено максимальное число символов - 15\n"; break;} break;
    case 12: cout << ">>"; cin >> stud.secname;    
	if(strlen(stud.secname)>25){ cout << "  XXX Превышено максимальное число символов - 25\n"; break;}break;
    case 13: cout << ">>";cin >> stud.dad;
    if(strlen(stud.dad)>20){ cout << "   XXX Превышено максимальное число символов - 20\n"; break;} break;
    case 14:cout << ">>"; cin >> stud.sex;if(cin.fail())exit(0);
    if((stud.sex>1)||(stud.sex<0)){cout<< "    XXX Неверно введен пол\n";break;    } break;
    case 21:cout << ">>";cin >> stud.chislo;if(cin.fail())exit(0);
	if((stud.chislo>31)||(stud.chislo<1)){cout << "XXX  Введено неверное число\n"; break;} break;
    case 22:cout << ">>"; cin >> stud.month;if(cin.fail())exit(0);
	if((stud.month>12)||(stud.month<1)){cout << " XXX  Введен неверный месяц\n"; break;} break;
    case 23:cout << ">>"; cin >> stud.year;if(cin.fail())exit(0);
	if((stud.year>2010)||(stud.year<1940)){cout << "  XXX  Введен неверный год\n"; break;} break;
    case 31:cout << ">>";cin >> stud.post;if(cin.fail())exit(0);
	if((stud.post>2021)||(stud.post<1940)){cout << "XXX  Введен неверный год\n"; break;} break;
    case 32:cout << ">>"; cin >> stud.number;
	if(strlen(stud.number)>10){ cout << " XXX Превышено максимальное число символов - 10\n"; break;} break;
    case 33:cout << ">>";cin.getline((stud.facult), 69);
	cin.getline((stud.facult), 69);
	if(strlen(stud.facult)>69){ cout << "  XXX Превышено максимальное число символов - 70\n"; break;} break;
    case 34:cout << ">>";cin >> stud.cafed;
	if(strlen(stud.cafed)>6){ cout << "   XXX Превышено максимальное число символов - 6\n"; break;} break;
    case 35:cout << ">>";cin >> stud.gr;
	if(strlen(stud.gr)>15){ cout << "    XXX Превышено максимальное число символов - 15\n"; break;} break;
    case 41:cout << "Сколько сессий? >>  ";
    cin >> stud.ses;if(cin.fail())exit(0);
    if(stud.ses>9){ cout << "XXX Превышено максимальное число сессий - 9\n"; break;}
    cout << "       предметов? >>  ";
    cin >> stud.ls;if(cin.fail())exit(0);
    if(stud.ls>10){ cout << "       XXX Превышено максимальное число предметов - 10\n"; break;}
    endd=0;
    for (int i=0;i <stud.ses;i++){
    	cout <<endl<<  i+1 << " сессия:\n";
    	for ( int j=0;j <stud.ls;j++){
    		cout << j+1<<"й предмет(сокращ.) >> ";
    		cin >> stud.less[i][j];
    		if(strlen(stud.less[i][j])>15){ cout << "XXX Превышено максимальное число символов - 15\n"; endd=1;break;}
    		cout <<      "      Оценка >>  ";
    		cin >> stud.mark[i][j];if(cin.fail())exit(0);
    		if((stud.mark[i][j]>5)||(stud.mark[i][j]<2)){ cout << "    XXX Неверная оценка(2--5)\n"; endd=1;break;}
    	}
    if(endd==1) break;
    }
    }
		 	f=fopen("1.bin", "r+b");	
	fseek(f, (id-1)*sizeof(st), SEEK_SET);
    fwrite(&stud, sizeof(st), 1, f);
    id =0;
	   fclose(f);
	   min2 = 3;
}
}
}
if(min==3){
	min2=0;
	while (min2 !=3){
	
	cout << "\n  1 -- По id  | 3 -- Назад \n>>  ";
	cin >> min2;if(cin.fail())exit(0);
	if(min2 == 1 ){
		cout << "Введите id студента >>  ";
		cin >> id;if(cin.fail())exit(0);
		 	f=fopen("1.bin", "r+b");	
	fseek(f, (id-1)*sizeof(st), SEEK_SET);
	stud.id=id;
	strcpy( stud.name, "удалено" ); 	strcpy( stud.dad, "удалено" );	strcpy( stud.secname, "удалено" );
	strcpy( stud.cafed, "--" ); 	strcpy( stud.gr, "удалено" );	strcpy( stud.facult, "удалено" );
	stud.chislo=0;stud.post=0;stud.month=0;stud.year=0;strcpy( stud.number, "удалено" );stud.ls=0;stud.ses=0;
    fwrite(&stud, sizeof(st), 1, f);
    id =0;
	   fclose(f);
	   min2 = 3;
}
}
}

}





}
}
}


   
