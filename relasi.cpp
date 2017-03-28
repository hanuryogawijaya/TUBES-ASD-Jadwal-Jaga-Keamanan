#include "relasi.h"
#include "parent.h"


void createListRelasi(List_r &L) {
	first(L) = NULL;
}

void dealokasiRelasi(address_r &P) {
	delete P;
}

address_r connectRelasi(address_p P, address_c C) {
    address_r Q = new elmlist_r;
    parent(Q) = P;
    child(Q) = C;
    next(Q) = NULL;
    return Q;
}

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
			P = next(P);
		}
	}
}

void printByValueRelasi(List_r &L, address_r P) {
	cout << "(" << info(parent(P)).id_pos << ")"
				<< info(parent(P)).nama_pos
				<< " -> "
				<< "(" << info(child(P)).id_satpam << ")"
				<< info(child(P)).nama_satpam << endl;
}

void insertFirstRelasi(List_c &L, address_c P) {
	if(first(L) == NULL) {
		first(L) = P;
	} else {
		next(P) = first(L);
		first(L) = P;
	}
}

void insertAfterRelasi(List_r L, address_r Prec, address_r P) {
	next(P) = next(Prec);
	next(Prec) = P;
}

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

void deleteRelasiByParent(List_r &L, address_p P) {
    address_r B, Q, Z;
        if(first(L)==NULL){
            cout<<"Empty List!"<<endl;
        }
        else{
            B=findrelasiparent(L, P);
        if(B==NULL){
            cout<<"ID Not Found"<<endl;
            }
        else{
            while(B!=NULL){
                if(B==first(L)){
                    deleteFirstRelasi(L,B);
                }
                else if (next(B)==NULL && B!=first(L)){
                    deleteLastRelasi(L,B);
                }
                else{
                    Q=first(L);
                    while (parent(next(Q)) != P) {
                        Q=next(Q);
                    }
                deleteAfterRelasi(L,Q,B);
                }
            B=findrelasiparent(L,P);
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

