#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#define M_PI
																									
using namespace std;

class Angles {
public:
	int Deg, Min;
private:
	const float pi =float (M_PI) ;
	int Rad;
	Angles * pointer1;
	Angles * pointer2;
public:
	Angles operator+(Angles ParAdd) {
		int DegNewAdd = Deg + ParAdd.Deg;
		int MinNewAdd = Min + ParAdd.Min;
		ParAdd.Deg = DegNewAdd;
		ParAdd.Min = MinNewAdd;
		cout << "Degrees = " << DegNewAdd << "° Minutes = " << MinNewAdd << "'";
		return ParAdd;
	}

	Angles operator-(Angles ParSubtr) {
		int DegNewSubtr = Deg - ParSubtr.Deg;
		int MinNewSubtr = Min - ParSubtr.Min;
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
		int DegNewConv = ParConv.Deg;
		int MinNewConv = ParConv.Min;
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
	Angles J;
	Angles K;

}