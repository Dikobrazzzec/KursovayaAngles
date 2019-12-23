#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>

using namespace std;

class Angles {
public:
	float Deg, Min;
private:
	const float pi = 3.14;
	float Rad;
	Angles* pointer1;
	Angles* pointer2;
public:
	Angles() {}

	Angles(float Deg_, float Min_) {
		Deg = Deg_;
		Min = Min_;
		Rad = -1;
	}

	Angles operator+(Angles ParAdd) {
		float DegNewAdd = Deg + ParAdd.Deg;
		float MinNewAdd = Min + ParAdd.Min;
		ParAdd.Deg = DegNewAdd;
		ParAdd.Min = MinNewAdd;
		cout << "Degrees = " << DegNewAdd << "° Minutes = " << MinNewAdd << "'" << endl;
		return ParAdd;
	}

	Angles operator-(Angles ParSubtr) {
		float DegNewSubtr = Deg - ParSubtr.Deg;
		float MinNewSubtr = Min - ParSubtr.Min;
		ParSubtr.Deg = DegNewSubtr;
		ParSubtr.Min = MinNewSubtr;
		cout << "Degrees = " << DegNewSubtr << "° Minutes = " << MinNewSubtr << "'" << endl;
		return ParSubtr;
	}

	Angles operator<(Angles ParConv) {
		while (ParConv.Deg >= 360) {
			ParConv.Deg -= 360;
		}
		while (ParConv.Min >= 60) {
			ParConv.Min -= 60;
		}
		float DegNewConv = ParConv.Deg; 
		float MinNewConv = ParConv.Min;
		cout << "Degrees = " << DegNewConv << "° Minutes = " << MinNewConv << "'" << endl;
		return ParConv;
	}

	Angles operator=(Angles ParPrisv) {
		Angles Ret;
		Ret.Deg = ParPrisv.Deg;
		Ret.Min = ParPrisv.Min;
		cout << Ret.Deg << " " << Ret.Min << " = " << endl;
		pointer1 = &Ret;
		pointer1->CreatRad();
		return Ret;
	} 

	Angles operator*(Angles ParCast) {
		ParCast = ParCast.operator<(ParCast);
		//pointer1->CreatRad();
		return ParCast;
	}

	Angles CreatRad() {
		Angles Ret;
		cout << Deg << " " << Min << pi<< " 1111" << endl;													
		float RadNew = (Deg * (pi / 180)) + ((Min / 60) * (pi / 180));
		cout << "Degrees = " << Deg << "° Minutes = " << Min << "' Radians = " << RadNew << endl;
		Ret.Rad = RadNew;
		Ret.Deg = Deg;
		Ret.Min = Min;
		return Ret;
	}
};

void Sl() {
	Angles A;
	Angles B;
	cout << "Vvedite znacheniya gradusov i minut pervogo ugla" << endl;
	cin >> A.Deg;
	cin >> A.Min;
	cout << "Vvedite znacheniya gradusov i minut vtorogo ugla" << endl;
	cin >> B.Deg;
	cin >> B.Min;
	A.operator+(B);
}

void Vic() {
	Angles K, L;
	cout << "Vvedite znacheniya gradusov i minut pervogo ugla" << endl;
	cin >>K.Deg;
	cin >> K.Min;
	cout << "Vvedite znacheniya gradusov i minut vtorogo ugla" << endl;
	cin >> L.Deg;
	cin >> L.Min;
	K.operator-(L);
}

void Pr() {
	Angles Z;
	cout << "Vvedite znacheniya gradusov i minut" << endl;
	cin >> Z.Deg;
	cin >> Z.Min;
	Z.operator<(Z);
}

void Rad() {
	Angles X;
	cout << "Vvedite znacheniya gradusov i minut" << endl;
	cin >> X.Deg;
	cin >> X.Min;
	X.CreatRad();
}



void work() {
	cout << "Vvedite rezhim raboti: S, V, P, R - Slozhenie, Vichitanie, Preobrazovanie, Radiani" << endl;
	char WorkMode;
	cin >> WorkMode;
	switch (WorkMode) {
	case 'S':
		Sl();
		break;
	case 'V':
		Vic();
		break;
	case 'P':
		Pr();
		break;
	case 'R':
		Rad();
		break;
	}
}

void EndOrNo() {
	cout << "Eto konec raboti? Y or N" << endl;
	char Finish;
	cin >> Finish;
	if (Finish == 'Y') {
		cout << "Goodbue!";
	}
	else {
		if (Finish == 'N') {
			work();
		}
		else {
			cout << "vvedite correctnoe znachenie" << endl;
			EndOrNo();
		}
	}
}

void main() {
	work();
	EndOrNo();
}