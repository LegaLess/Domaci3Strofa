#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>

using namespace std;

template <typename T>
class Lista {

public:

	Lista() {}
	Lista(const Lista& l) { kopiraj(l); }
	Lista(Lista&& l) { premesti(l); }
	~Lista() { brisi(); }
	Lista<T>& operator=(const Lista& l) {
		if (this != &l) {
			brisi();
			kopiraj(l);
		}
		return *this;
	}

	Lista<T>& operator=(const Lista&& l) {
		if (this != &l) {
			brisi();
			premesti(l);
		}
		return *this;
	}

	Lista<T>& dodaj(T obj);
	
	void reset_tek() const { tek = prvi; }
	void sled() const { tek = tek->next; }
	bool check_tek() const { return tek; }
	T& get_tek() const { return tek->val; }

	void kopiraj(const Lista&);
	void premesti(Lista&);
	void brisi();

private:

	struct Elem {
		T val;
		Elem* next = nullptr;
		Elem(T& v) : val(v), next(nullptr) {}
	};

	Elem* prvi = nullptr;
	Elem* posl = nullptr;
	mutable Elem* tek = nullptr;

};

template<typename T>
inline Lista<T>& Lista<T>::dodaj(T obj)
{
	Elem* novi = new Elem(obj);

	if (!prvi) {
		prvi = novi;
		posl = novi;
	}
	else {
		posl->next = novi;
		posl = novi;
	}

	return *this;
}

template<typename T>
inline void Lista<T>::kopiraj(const Lista& l)
{
	for (l.reset_tek(); l.check_tek(); l.sled()) {
		dodaj(l.get_tek());
	}
}

template<typename T>
inline void Lista<T>::premesti(Lista& l)
{
	prvi = l.prvi;
	tek = l.tek;
	posl = l.posl;

	l.prvi = nullptr;
	l.tek = nullptr;
	l.posl = nullptr;
}

template<typename T>
inline void Lista<T>::brisi()
{
	Elem* tmp = nullptr;

	while (tmp = prvi) {
		prvi = prvi->next;
		delete tmp;
	}

	prvi = nullptr;
	posl = nullptr;
	tek = nullptr;
}

#endif
