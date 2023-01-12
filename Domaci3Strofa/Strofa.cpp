#include <iostream>
#include <string>
#include "Strofa.h"

using namespace std;

Strofa& Strofa::operator+=(Stih s)
{
    if (stihovi.length() == kapacitet) return *this;
    if (stihovi.length() != 0 && ~stihovi.get_tek() != ~s) return *this;

    stihovi.dodaj(s);

    return *this;
}


void Strofa::operator()(int i, int j)
{
    Stih tmp = stihovi[i];

    stihovi[i] = stihovi[j];
    stihovi[j] = tmp;

}

bool Strofa::operator*() const
{
    for (int i = 0; i < stihovi.length() - 1; i++) {
        if (!(stihovi[i] ^ stihovi[i + 1])) return false;
    }

    return true;
}

ostream& Strofa::pisi(ostream& it) const
{
    for (stihovi.reset_tek(); stihovi.check_tek(); stihovi.sled()) {
        it << stihovi.get_tek() << endl;
    }

    return it;
}
