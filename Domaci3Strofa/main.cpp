#include <iostream>
#include <string>
#include "Katren.h"

using namespace std;

int main() {

	Stih s1;
	Stih s2;
	Stih s3;
	Stih s4;

	cin >> s1;
	cin >> s2;
	cin >> s3;
	cin >> s4;

	Katren katren;

	katren += s1;
	katren += s2;
	katren += s3;
	katren += s4;

	katren(1, 2);

	cout << katren;

	return 0;
}