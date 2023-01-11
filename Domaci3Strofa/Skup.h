#ifndef _SKUP_H_
#define _SKUP_H_

#include <iostream>
#include <string>
#include "Lista.h"

using namespace std;

class Skup {

public:

	Skup(string s) { dodaj(s); }
	Skup(const Skup&) = delete;
	Skup& operator=(const Skup&) = delete;

	void ispis() {
		for (znakovi.reset_tek(); znakovi.check_tek(); znakovi.sled()) {
			cout << znakovi.get_tek();
		}
	}

	Skup& operator+=(char);
	bool operator()(char);

private:

	void dodaj(string&);

	Lista<char> znakovi;

};


#endif
