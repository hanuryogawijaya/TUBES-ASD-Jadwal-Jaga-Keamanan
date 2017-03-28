#ifndef CHILD_H_INCLUDED
#define CHILD_H_INCLUDED

/**
* NIM : 1301164153
* Nama : Muhammad Hanur Yoga Wijaya
**/

#include <iostream>
#include <string>
using namespace std;

#define first(L) L.first
#define last(L) L.last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev

struct satpam {
	string id_satpam;
	string nama_satpam;
	string umur;
	string jenis_kelamin;
	string shift;
	string no_telp;
};

typedef satpam infotype_c;
typedef struct elmList_c *address_c;

struct elmList_c {
	infotype_c info;
	address_c next;
	address_c prev;
};

struct List_c {
	address_c first;
	address_c last;
};

void createListChild(List_c &L);
address_c alokasiChild(infotype_c x);
void dealokasiChild(address_c &P);
void insertFirstChild(List_c &L, address_c P);
void insertLastChild(List_c &L, address_c P);
address_c findElmChild(List_c L, infotype_c x);
void deleteFirstChild(List_c &L, address_c &P);
void deleteLastChild(List_c &L, address_c &P);
void printInfoChild(List_c L);
void printByIDChild(List_c L, address_c C);
void insertAfterChild(List_c L, address_c Prec, address_c P);
void deleteAfterChild(List_c L, address_c Prec, address_c &P);
void insertAscendingChild(List_c &L, address_c P);
void deleteByIDChild(List_c &L, infotype_c x);

#endif

