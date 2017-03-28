#ifndef PARENT_H_INCLUDED
#define PARENT_H_INCLUDED

/**
* NIM : 1301164407
* Nama : Ikhsan Ramadhan B
**/

#include <iostream>
#include <string>
using namespace std;

#define first(L) L.first
#define info(P) P->info
#define next(P) P->next

struct pos {
	string id_pos;
	string nama_pos;
	string alamat_pos;
	string no_rt;
	string no_rw;
	string telp_pos;
};

typedef pos infotype_p;
typedef struct elmlist_p *address_p;

struct elmlist_p {
	infotype_p info;
	address_p next;
};

struct List_p {
	address_p first;
};

void createListParent(List_p &L);
address_p alokasiParent(infotype_p x);
void dealokasiParent(address_p &P);
void insertFirstParent(List_p &L, address_p P);
void insertLastParent(List_p &L, address_p P);
address_p findElmParent(List_p L, infotype_p x);
void deleteFirstParent(List_p &L, address_p &P);
void deleteLastParent(List_p &L, address_p &P);
void printInfoParent(List_p L);
void printByIDParent(List_p L, address_p P);
void insertAfterParent(List_p L, address_p Prec, address_p P);
void deleteAfterParent(List_p L, address_p Prec, address_p &P);
void insertAscendingParent(List_p &L, address_p P);
void deleteByIDParent(List_p &L, infotype_p x);

#endif
