#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	char name[10];
	char in[5];
	int i = 0;
	float o;
	
	char name2[10];
	char in2[5];
	int i2 = 0;
	float o2;
	
	char name3[10];
	char in3[5];
	int i3 = 0;
	float o3;
	
	
	printf("vvedite familiy, initsyaly, god rojdeniya, oklad dlya    1     sotrudnika\n" );
	scanf("%s%s%d%f", &name , &in, &i, &o);
	printf("vvedite familiy, initsyaly, god rojdeniya, oklad dlya    2     sotrudnika\n" );
	scanf("%s%s%d%f", &name2 , &in2, &i2, &o2);
	printf("vvedite familiy, initsyaly, god rojdeniya, oklad dlya    3     sotrudnika\n" );
	scanf("%s%s%d%f", &name3 , &in3, &i3, &o3);
	
	
	
    printf("_____________________________________________________________________________");
	printf("\n|       Otdel kadrov                                                      |");
	printf("\n|_________________________________________________________________________|");
	printf("\n|  familiya   |   initsyaly   |   god rojdenya   |   oklad                |");
	printf("\n|_________________________________________________________________________|");
	printf("\n| %s      |     %s      |    %d          |    %.2f|", name, in, i, o );
	printf("\n|_________________________________________________________________________|");
    printf("\n| %s      |     %s      |    %d          |    %.2f|", name2, in2, i2, o2 );
	printf("\n|_________________________________________________________________________|");
	printf("\n| %s      |     %s      |    %d          |    %.2f|", name3, in3, i3, o3 );
	
	printf("\n|_________________________________________________________________________|");

	printf("\n| Primechaniye: oklad ystanovlen na 1 decabrya 2000 goda                  |");
	printf("\n|_________________________________________________________________________|");

}
