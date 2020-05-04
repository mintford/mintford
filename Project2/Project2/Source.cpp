#include <iostream>
#include <math.h>
using namespace std;
int main() {
	//                параметры схемы
	double R1 = 30, R2 = 25, R3 = 50, R4 = 1.88, R5 = 15, R6 = 60; // сопротивление
	double C = 20E-6, L = 5.57E-3; // реактивные элементы
	double a = (R4 + (R1 * R2) / (R1 + R2) + (R5 + R6) * R3 / (R3 + R5 + R6));
	double b = (R5 + R6) / (R3 + R5 + R6);
	double d = R2 / (R1 + R2);
	double g = 1 / (R3 + R5 + R6);
	double    pi = 3.1415;
	double    f = 40; // частота
	double  w = 2 * pi * f;
	//                начальные условия
	double t, t0 = 0, t1 = 0.01, t2 = 0.02; // время
	double n = 1000, h = (t2 - t0) / n; // число и шар деления  
	double E0 = 15;
	double I0 = 0, I1, U0 = 0, U1;// напряжение и токи
	cout << "---  t0 ----   " << endl;
	cout << "t     \t I        \t U     " << endl;
	int AA = 1, B = 20; // показывать каждое  B
	for (t = t0; t <= t1; t = t + h) {    // до переключения
		I1 = I0 + h * 1 / L * (E0 * sin(w * t + pi) * d - I0 * a - U0 * b);
		U1 = U0 + h * 1 / C * (I1 * b - U0 * g);
		I0 = I1; U0 = U1;
		AA++;
		if (AA == B) {
			AA = 1;
			cout << t << "\t" << I0 << "\t" << U0 << endl;
		}
	};
	cout << "---  t1 ----   " << endl;
	cout << "t     \t I        \t U     " << endl;
	for (; t <= t2; t = t + h) {    // после  переключения
		I1 = I0 + h * (1 / L * (-I0 * a - U0 * b));
		U1 = U0 + h * 1 / C * (I1 * b - U0 * g);
		I0 = I1; U0 = U1;
		AA++;
		if (AA == B) {
			AA = 0;
			cout << t << "\t" << I0 << "\t" << U0 << endl;
		}
	}
	cout << "---  t2 ----   " << endl;
	cin.get();
	return 0;
};