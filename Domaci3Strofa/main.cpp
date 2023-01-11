#include <iostream>
#include <string>
#include "Rec.h"

using namespace std;

int main() {

	Rec rec1("sok");
	Rec rec2("srp");

	cout << (rec1^rec2) << endl;

	return 0;
}