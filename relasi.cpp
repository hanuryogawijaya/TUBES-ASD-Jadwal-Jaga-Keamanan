#include "relasi.h"
#include "parent.h"

/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

void createListRelasi(List_r &L) {
	first(L) = NULL;
}

/* NIM : 1301164407
Nama : Ikhsan Ramadhan B */
void dealokasiRelasi(address_r &P) {
	delete P;
}
/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

address_r connectRelasi(address_p P, address_c C) {
    address_r Q = new elmlist_r;
    parent(Q) = P;
    child(Q) = C;
    next(Q) = NULL;
    return Q;
}
/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

address_r findElmRelasi(List_r L, address_p P, address_c C) {
	address_r Q = first(L);
	while(Q != NULL) {
		if(parent(Q) == P && child(Q) == C) {
			return Q;
		}
		Q = next(Q);
	}
	return NULL;
}
/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

address_r findrelasichild(List_r &L, address_c C){
address_r Q = first(L);
	while(Q != NULL) {
		if(child(Q) == C) {
			return Q;
		}
		Q = next(Q);
	}
	return NULL;
}

/* NIM : 1301164407
Nama : Ikhsan Ramadhan B */
address_r findrelasiparent(List_r &L, address_p P){
address_r Q = first(L);
	while(Q != NULL) {
		if(parent(Q) == P) {
			return Q;
		}
		P = next(P);
	}
	return NULL;
}

/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

void printInfoRelasi(List_r &L) {
	if(first(L) == NULL) {
		cout << "List Kosong" << endl;
	} else {
		address_r P = first(L);
		cout << "Data" << endl;
		while(P != NULL) {
			cout << "ID Pos     : " << info(parent(P)).id_pos << endl;
            cout << "Nama Pos   : "<< info(parent(P)).nama_pos << endl;
            cout << "Petugas" << endl;
            cout << "ID Satpam  : "<< info(child(P)).id_satpam << endl;
            cout << "Nama Satpam: "<<info(child(P)).nama_satpam << endl;
            cout << endl;
			P = next(P);
		}
	}
}

/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

void printByValueRelasi(List_r &L, address_r P) {
            cout << "ID Pos     : " << info(parent(P)).id_pos << endl;
            cout << "Nama Pos   : "<< info(parent(P)).nama_pos << endl;
            cout << "Petugas" << endl;
            cout << "ID Satpam  : "<< info(child(P)).id_satpam << endl;
            cout << "Nama Satpam: "<<info(child(P)).nama_satpam << endl;
            cout << endl;
}

/* NIM : 1301164407
Nama : Ikhsan Ramadhan B */
void insertFirstRelasi(List_c &L, address_c P) {
	if(first(L) == NULL) {
		first(L) = P;
	} else {
		next(P) = first(L);
		first(L) = P;
	}
}

/* NIM : 1301164407
Nama : Ikhsan Ramadhan B */
void insertAfterRelasi(List_r L, address_r Prec, address_r P) {
	next(P) = next(Prec);
	next(Prec) = P;
}

/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

void insertLastRelasi(List_r &L, address_r P) {
	if(first(L) == NULL) {
		first(L) = P;
	} else {
		address_r Q = first(L);
		while(next(Q) != NULL) {
			Q = next(Q);
		}
		next(Q) = P;
	}
}

/* NIM : 1301164407
Nama : Ikhsan Ramadhan B */
void deleteFirstRelasi(List_r &L, address_r &P) {
	if(next(first(L)) == NULL) {
		P = first(L);
		first(L) = NULL;
        dealokasiRelasi(P);
	} else {
		P = first(L);
		first(L) = next(P);
		next(P) = NULL;
        dealokasiRelasi(P);
	}
}

/* NIM : 1301164407
Nama : Ikhsan Ramadhan B */
void deleteAfterRelasi(List_r L, address_r Prec, address_r &P) {
	if(Prec == first(L)) {
		deleteFirstRelasi(L, P);
	} else {
		P = next(Prec);
		next(Prec) = next(P);
		next(P) = NULL;
		dealokasiRelasi(P);
	}
}

/* NIM : 1301164407
Nama : Ikhsan Ramadhan B */
void deleteLastRelasi(List_r &L, address_r &P) {
	address_r Q;
	Q = first(L);
	while(next(next(Q)) != NULL) {
		Q = next(Q);
	}
	P = next(Q);
	next(Q) = NULL;
	dealokasiRelasi(P);
}


/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

void deleteRelasiByChild(List_r &L, address_c C) {
    address_r A, S, Z;
        if(first(L)==NULL){
            cout<<"Empty List!"<<endl;
        }
        else{
            A=findrelasichild(L, C);
        if(A==NULL){
            cout<<"ID Not Found"<<endl;
            }
        else{
            while(A!=NULL){
                if(A==first(L)){
                    deleteFirstRelasi(L,A);
                }
                else if (next(A)==NULL && A!=first(L)){
                    deleteLastRelasi(L,A);
                }
                else{
                    S=first(L);
                    while (child(next(S)) != C) {
                        S=next(S);
                    }
                deleteAfterRelasi(L,S,A);
                }
            A=findrelasichild(L,C);
            }
        }
        }
}

/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

void deleteRelasiByParent(List_r &L, address_p P) {
    address_r A, S, Z;
        if(first(L)==NULL){
            cout<<"Empty List!"<<endl;
        }
        else{
            A=findrelasiparent(L, P);
        if(A==NULL){
            cout<<"ID Not Found"<<endl;
            }
        else{
            while(A!=NULL){
                if(A==first(L)){
                    deleteFirstRelasi(L,A);
                }
                else if (next(A)==NULL && A!=first(L)){
                    deleteLastRelasi(L,A);
                }
                else{
                    S=first(L);
                    while (parent(next(S)) != P) {
                        S=next(S);
                    }
                deleteAfterRelasi(L,S,A);
                }
            A=findrelasiparent(L,P);
            }
        }
        }
}

void sortRelasi(List_r &L) {
    List_r S;
    address_r P, Q, Z;
    if(first(L) == NULL) {
        cout << "List Empty!" << endl;
    } else {
        createListRelasi(S);
        P = first(L);
        while(P != NULL) {
            Z = next(P);
            if((first(S) == NULL) || (info(parent(first(S))).id_pos > info(parent(P)).id_pos)) {
                next(P) = first(S);
                first(S) = P;
            } else {
                Q = first(S);
                while (next(Q) != NULL && info(parent(next(Q))).id_pos < info(parent(P)).id_pos) {
                    Q = next(Q);
                }
                next(P) = next(Q);
                next(Q) = P;
            }
            P = Z;
        }
        L = S;
        cout << "Success!!" << endl;
    }
}

/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

void disconnectRelasi(List_r &L, address_r P) {
    address_r Q;
    if(P == first(L)) {
        deleteFirstRelasi(L, P);
    } else if(next(P) == NULL) {
        deleteLastRelasi(L, P);
    } else {
        Q = first(L);
		while(next(Q) != P) {
			Q = next(Q);
		}
		deleteAfterRelasi(L, Q, P);
    }
}
