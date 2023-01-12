#ifndef _STIH_H_
#define _STIH_H_

#include <iostream>
#include <string>
#include "Rec.h"

using namespace std;

class Stih {

public:

	Stih& operator+=(Rec r) { tekst.dodaj(r); return *this; }
	int operator+() const { return tekst.length(); }
	int operator~() const;
	Rec& operator[](int);
	const Rec& operator[](int) const;
	void operator()(int n) { tekst.brisi_el(n); }
	void operator()(Rec& r, int n) { tekst.insert_el(r, n); }
	friend bool operator^(const Stih& s1, const Stih& s2) { return s1.tekst.get_last() ^ s2.tekst.get_last(); }
	friend istream& operator>>(istream&, Stih&);
	friend ostream& operator<<(ostream&, const Stih&);

private:

	Lista<Rec> tekst;

};



#endif
