#include <iostream>
#include <cmath>

using namespace std;

int main(){
	float r1,r2, x,y;
	cout<< "VVedite R1>>";
	cin >> r1;
	cout<< "VVedite R2>>";
	cin >> r2;
	cout<< "VVedite X>>";
	cin >> x;
	cout<< "VVedite Y>>";
	cin >> y;
	
	if((sqrt(x*x+y*y) > r))||(sqrt(x*x+y*y) < r2)) cout << " Ne vhodit";
	else 
		if((x<0&&y>0)||(x>0&&y<0)) cout << "Ne vhodit";
		else cout << " Vhodit";	
}
