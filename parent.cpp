#include "parent.h"
#include "relasi.h"

/* NIM : 1301164407
Nama : Ikhsan Ramadhan B */

void createListParent(List_p &L) {
	first(L) = NULL;
}

address_p alokasiParent(infotype_p x) {
	address_p P = new elmlist_p;
	info(P) = x;
	next(P) = NULL;
	return P;
}

void dealokasiParent(address_p &P) {
	delete P;
}


address_p findElmParent(List_p L, infotype_p x) {
	address_p P = first(L);
	do {
		if(info(P).id_pos == x.id_pos) {
			return P;
		}
		P = next(P);
	} while(P != NULL);
	return NULL;
}

void printInfoParent(List_p L) {
	if(first(L) == NULL) {
		cout << "Empty List!" << endl;
	} else {
		address_p P = first(L);
		cout << "List\n" << endl;
		while(P != NULL) {
			cout << "ID Pos     : " << info(P).id_pos << endl;
			cout << "Nama Pos   : " << info(P).nama_pos << endl;
			cout << "Alamat Pos : " << info(P).alamat_pos << ", RT " << info(P).no_rt << ", RW " << info(P).no_rw << endl;
			cout << "Telp Pos   : " << info(P).telp_pos << endl;
			P = next(P);
		}
	}
}

void printByIDParent(List_p L, address_p P) {
	cout << "List\n" << endl;
	cout << "ID Pos     : " << info(P).id_pos << endl;
    cout << "Nama Pos   : " << info(P).nama_pos << endl;
    cout << "Alamat Pos : " << info(P).alamat_pos << ", RT " << info(P).no_rt << ", RW " << info(P).no_rw << endl;
    cout << "Telp Pos   : " << info(P).telp_pos << endl;
	cout << endl;
}

void insertFirstParent(List_p &L, address_p P) {
	if(first(L) == NULL) {
		first(L) = P;
	} else {
		next(P) = first(L);
		first(L) = P;
	}
}

void insertAfterParent(List_p L, address_p Prec, address_p P) {
	next(P) = next(Prec);
	next(Prec) = P;
}


void insertLastParent(List_p &L, address_p P) {
	address_p Q = first(L);
	while(next(Q) != NULL) {
		Q = next(Q);
	}
	next(Q) = P;
}

void insertAscendingParent(List_p &L, address_p P) {
	address_p Q;
	if(first(L) == NULL || info(first(L)).id_pos > info(P).id_pos) {
		insertFirstParent(L, P);
	} else {
		Q = first(L);
		while(next(Q) != NULL && info(next(Q)).id_pos < info(P).id_pos) {
			Q = next(Q);
		}
		if(next(Q) == NULL) {
			insertLastParent(L, P);
		} else {
			insertAfterParent(L, Q, P);
		}
	}
}


void deleteFirstParent(List_p &L, address_p &P) {
	if(next(first(L)) == NULL) {
		P = first(L);
		next(P) = NULL;
	} else {
		P = first(L);
		first(L) = next(P);
		next(P) = NULL;
		dealokasiParent(P);
	}
}

void deleteLastParent(List_p &L, address_p &P) {
	address_p Q;
	Q = first(L);
	while(next(next(Q)) != NULL) {
		Q = next(Q);
	}
	P = next(Q);
	next(Q) = NULL;
	dealokasiParent(P);
}


void deleteAfterParent(List_p L, address_p Prec, address_p &P) {
	P = next(Prec);
	next(Prec) = next(P);
	next(P) = NULL;
	dealokasiParent(P);
}


void deleteByIDParent(List_p &L, infotype_p x) {
	address_p P, Q;
	if(first(L) == NULL) {
		cout << "Empty List!" << endl;
	} else {
		P = findElmParent(L, x);
		if(P == NULL) {
			cout << "ID Not Found" << endl;
		} else if(P == first(L)) {
			deleteFirstParent(L, P);
		} else if(next(P) == NULL && P != first(L)) {
			deleteLastParent(L, P);
		} else {
			Q = first(L);
			while(next(Q) != P) {
				Q = next(Q);
			}
			deleteAfterParent(L, Q, P);
		 }
		cout << "Success!!" << endl;
	}
}
