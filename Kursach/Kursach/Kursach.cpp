#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#define M_PI
																									
using namespace std;

class Angles {
public:
	float Deg, Min;
private:
	const float pi =float (M_PI) ;
	float Rad;
	Angles * pointer1;
	Angles * pointer2;
public:
	Angles() {} 

	Angles(float Deg_, float Min_) {
		Deg = Deg_;
		Min = Min_;
	}

	Angles operator+(Angles ParAdd) {
		float DegNewAdd = Deg + ParAdd.Deg;
		float MinNewAdd = Min + ParAdd.Min;
		ParAdd.Deg = DegNewAdd;
		ParAdd.Min = MinNewAdd;
		cout << "Degrees = " << DegNewAdd << "° Minutes = " << MinNewAdd << "'";
		return ParAdd;
	}

	Angles operator-(Angles ParSubtr) {
		float DegNewSubtr = Deg - ParSubtr.Deg;
		float MinNewSubtr = Min - ParSubtr.Min;
		ParSubtr.Deg = DegNewSubtr;
		ParSubtr.Min = MinNewSubtr;
		cout << "Degrees = " << DegNewSubtr << "° Minutes = " << MinNewSubtr << "'";
		return ParSubtr;
	}
																								//Сделать конструктор для градусов и минут
																								//Подумать над отрицательными углами;															
																								//Conversion - преобразование, cast - приведение
	Angles operator<(Angles ParConv) {								
		while (ParConv.Deg >= 360)
		{
			ParConv.Deg -= 360;
		}
		while (ParConv.Min >= 60 )
		{
			ParConv.Min -= 60;
		}
		float DegNewConv = ParConv.Deg;
		float MinNewConv = ParConv.Min;
		cout << "Degrees = " << DegNewConv << "° Minutes = " << MinNewConv << "'";
		return ParConv;
	}

	Angles operator*(Angles ParCast) {															//rad  = deg*(pi/180)  rad = (min/60)*(pi/180)
		ParCast.operator<(ParCast);
		float RadNew = (ParCast.Deg * (pi / 180)) + ((ParCast.Min / 60) * (pi / 180));
		ParCast.Rad = RadNew;
		cout << "Degrees = " << ParCast.Deg << "° Minutes = " << ParCast.Min << "' Radians = " << ParCast.Rad;
		return ParCast;
	}
};

void main() {
	Angles J(4454,5655);
	Angles K(5,7);
	J.operator<(J);
	Angles Q;
	J.operator+(K);
}