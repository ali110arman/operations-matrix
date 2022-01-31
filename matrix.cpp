#include <conio.h>
#include <iostream>
using namespace std;
class matrix {
private:
	int satr1, sotoon1, satr2, sotoon2;
	int name1[100][100], name2[100][100], name3[100][100];
		
public:
	matrix();
	void reedmatrix2();
	void gam();
	void zarb();
	void tranahadeh();
	void determinan();
};
 matrix::matrix() {
	cout << "tedad satr ra vared konid:"<<endl;
	cin >> satr1;
	cout << "tedad sotoon ra vared konid:" << endl;
	cin >>sotoon1;
	system("cls");
	for (int i = 0; i < satr1; i++)
		for (int j = 0; j < sotoon1; j++)
			cin >> name1[i][j];
}
void matrix::reedmatrix2() {
	cout << "tedad satr ra vared konid:" << endl;
	cin >> satr2;
	cout << "tedad sotoon ra vared konid:" << endl;
	cin >> sotoon2;
	system("cls");
	for (int i = 0; i < satr2; i++)
		for (int j = 0; j < sotoon2; j++)
			cin >> name2[i][j];
}
void matrix::gam() {
	cout << endl;
	if (satr1 != satr2) {
		cout << "do matrix motanazer nistatnd";
		return;
	}
	if (sotoon1 != sotoon2) {
		cout << "do matrix motanazer nistatnd";
		return;
	}
	for (int i = 0, k = 0; i < satr1; i++, k++) {
		for (int j = 0, l = 0; j < sotoon1; j++, l++) {
			name3[i][j] = name1[i][j] + name2[k][l];
			cout << name3[i][j] << " ";
		}
		cout << endl;
	}
}
void matrix::zarb() {
	cout << endl;
	if (sotoon1 != satr2) {
		cout << "sotoon matrix aval ba satr matrix dovom barabar nist";
		return;
	}
	for (int i = 0; i < satr1; i++) {
		for (int j = 0; j < sotoon2; j++) {
			name3[i][j] = 0;
			for (int k = 0; k < sotoon1; k++)
				name3[i][j] += name1[i][k] * name2[k][j];
			cout << name3[i][j] << " ";
		}
		cout << endl;
	}
}
void matrix::tranahadeh() {
	for (int i = 0; i < satr1; i++)
		for (int j = 0; j < sotoon1; j++) 
			name3[j][i] = name1[i][j];
	cout << endl;
	for (int i = 0; i < sotoon1; i++) {
		for (int j = 0; j < satr1; j++) 
			cout << name3[i][j] << " ";
		cout << endl;
	}
}
void matrix::determinan() {
	if (satr1 == 2) 
		cout << name1[0][0] * name1[1][1] - name1[0][1] * name1[1][0];
	if (satr1 > 2) {
		int n = satr1, m = sotoon1 + 2, sum = 0, sum2 = 0, zarb = 1, zarb2 = 1;
		for (int i = 0; i < satr1; i++)
			for (int j = 0; j < sotoon1; j++)
				name3[i][j] = name1[i][j];
		for (int i = 0; i < satr1; i++)
			for (int j = 0; j < 2; j++)
				name3[i][sotoon1 + j] = name1[i][j];
		for (int i = 0; i < 3; i++) {
			zarb = 1;
			for (int u = 0 + i, g = 0; g < satr1; u++, g++)
				zarb *= name3[g][u];
			sum += zarb;
		}
		for (int i = 0; i < 3; i++) {
			zarb2 = 1;
			for (int u = satr1 + i - 1, g = 0; g < satr1; u--, g++)
				zarb2 *= name3[g][u];
			sum2 += zarb2;
		}
		cout <<"determinan is:"<<endl <<sum - sum2;
	}
}

void main() {
	matrix a;
	a.tranahadeh();
	a.determinan();
}

