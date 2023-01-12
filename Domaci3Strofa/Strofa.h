#ifndef _STROFA_H_
#define _STROFA_H_

#include <iostream>
#include <string>
#include "Stih.h"

using namespace std;

class Strofa {

public:

	Strofa(int k) : kapacitet(k) {}

	int get_kap() const { return kapacitet; }

	Strofa& operator+=(Stih s);
	void operator-() { if (!stihovi.length()) return; stihovi.brisi_el(stihovi.length() - 1); }
	int operator+() const { return stihovi.length(); }
	Stih& operator[](int n) { return stihovi[n]; }
	const Stih& operator[](int n) const { return stihovi[n]; }
	void operator()(int, int);
	virtual bool operator*() const;
	friend ostream& operator<<(ostream& it, const Strofa& s) { return s.pisi(it); };

protected:

	virtual ostream& pisi(ostream&) const;
	virtual char get_oznaka() const = 0;
	char oznaka;
	Lista<Stih> stihovi;

private:

	int kapacitet;


};


#endif

