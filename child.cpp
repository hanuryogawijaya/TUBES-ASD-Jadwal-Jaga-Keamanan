#include "child.h"

/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

void createListChild(List_c &L) {
	first(L) = NULL;
	last(L) = NULL;
}

address_c alokasiChild(infotype_c x) {
	address_c P = new elmList_c;
	info(P) = x;
	next(P) = NULL;
	prev(P) = NULL;
	return P;
}

void dealokasiChild(address_c &P) {
	delete P;
}

address_c findElmChild(List_c L, infotype_c x) {
	address_c P = first(L);
	do {
		if(info(P).id_satpam == x.id_satpam) {
			return P;
		}
		P = next(P);
	} while(P != NULL);
	return NULL;
}

void printInfoChild(List_c L) {
	if(first(L) == NULL) {
		cout << "List Kosong" << endl;
	} else {
		address_c P = first(L);
		cout << "Daftar Satpam" << endl;
		while(P != NULL){
			cout << "ID             :" << info(P).id_satpam << endl;
			cout << "Nama           :" << info(P).nama_satpam << endl;
			cout << "Umur           :" << info(P).umur << endl;
			cout << "Jenis Kelamin  :" << info(P).jenis_kelamin << endl;
			cout << "Shift          :" << info(P).shift << endl;
			cout << "No Telp        :" << info(P).no_telp << endl;
			cout << endl;
			P = next(P);
		}
	}
}

void printByIDChild(List_c L, address_c P) {
            cout << "Data Satpam\n" << endl;
            cout << "ID  		    :" << info(P).id_satpam << endl;
			cout << "Nama 	        :" << info(P).nama_satpam << endl;
			cout << "Umur  	        :" << info(P).umur << endl;
			cout << "Jenis Kelamin  :" << info(P).jenis_kelamin << endl;
			cout << "Shift	        :" << info(P).shift << endl;
			cout << "No Telp	    :" << info(P).no_telp << endl;
			cout << endl;
}

void insertFirstChild(List_c &L, address_c P) {
	if (first(L) == NULL){
		first(L) = P;
		last(L) = P;
	} else {
		next(P) = first(L);
		next(last(L)) = P;
		first(L) = P;
	}
}

void insertAfterChild(List_c L, address_c Prec, address_c P) {
	next(P) = next(Prec);
	prev(P) = Prec;
	prev(next(Prec)) = P;
	next(Prec) = P;
}


void insertLastChild(List_c &L, address_c P) {
	if(first(L) == NULL){
		insertFirstChild(L,P);
	} else {
		prev(P) = last(L);
		next(last(L)) = P;
		last(L) = P;
	}
}

void insertAscendingChild(List_c &L, address_c P) {
	address_c Q;
	if(first(L) == NULL || info(first(L)).id_satpam > info(P).id_satpam) {
		insertFirstChild(L, P);
	} else {
		Q = first(L);
		while(next(Q) != NULL && info(next(Q)).id_satpam < info(P).id_satpam) {
			Q = next(Q);
		}
		if(next(Q) == NULL) {
			insertLastChild(L, P);
		} else {
			insertAfterChild(L, Q, P);
		}
	}
}


void deleteFirstChild(List_c &L, address_c &P) {
	if (first(L) == NULL) {
		first(L) = NULL;
		last(L) = NULL;
    }else if (next(first(L))==NULL){
        first(L) = NULL;
		last(L) = NULL;
	} else {
		P = first(L);
		first(L) = next(P);
		next(P) = NULL;
		prev(first(L)) = NULL;
		}
}

void deleteLastChild(List_c &L, address_c &P) {
	if(first(L) == NULL){
		first(L) = NULL;
		last(L) = NULL;
    }else if (next(first(L))==NULL){
        first(L) = NULL;
		last(L) = NULL;
	} else {
		P = last(L);
		last(L) = prev(last(L));
		prev(P) = NULL;
		next(last(L)) = NULL;
	}
}

void deleteAfterChild(List_c L, address_c Prec, address_c &P) {
	P = next(Prec);
	next(Prec) = next(P);
	prev(next(P)) = Prec;
	prev(P) = NULL;
	next(P) = NULL;
}


void deleteByIDChild(List_c &L, infotype_c x) {
	address_c P, Q;
	if(first(L) == NULL) {
		cout << "Empty List!" << endl;
	} else {
		P = findElmChild(L, x);
		if(P == NULL) {
			cout << "ID Not Found" << endl;
		} else if(P == first(L)) {
			deleteFirstChild(L, P);
		} else if(P == last(L)) {
			deleteLastChild(L, P);
		} else {
			Q = first(L);
			while(next(Q) != P) {
				Q = next(Q);
			}
			deleteAfterChild(L, Q, P);
		 }
		cout << "Success!!" << endl;
	}
}
