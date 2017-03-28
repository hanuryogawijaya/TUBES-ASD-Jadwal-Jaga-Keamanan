#include <iostream>
#include <stdlib.h>
#include "parent.h"
#include "child.h"
#include "relasi.h"

using namespace std;

void mainMenu();
void insertParent();
void insertChild();
void viewParent();
void viewChild();
void findParent();
void findChild();
void connectRelasi();
void viewRelasi();
void searchRelasi();
void disconnectRelasi();
void deleteParent();
void deleteChild();
void sortRelasi();
void deleterparent();
void deleterchild();
void makasihpak();

List_p Lp;
List_c Lc;
List_r Lr;
address_p Pp = NULL;
address_p Prec_p = NULL;
address_c Pc = NULL;
address_c Prec_c = NULL;
address_r Pr = NULL;
infotype_p Xp;
infotype_c Xc;

int main() {
	createListParent(Lp);
	createListChild(Lc);
	createListRelasi(Lr);
	mainMenu();
	return 0;
}

void mainMenu() {
	int pilihan;
	do {
            cout << "                                     " << endl;
            cout << "-------------------------------------" << endl;
			cout << "-------- JADWAL JAGA KEAMANAN -------" << endl;
            cout << "------------- LINGKUNGAN ------------" << endl;
			cout << "-------------------------------------" << endl;
			cout << "       1. Insert Data Parent        |" << endl;
			cout << "       2. Insert Data Child         |" << endl;
			cout << "       3. View Data Parent          |" << endl;
			cout << "       4. View Data Child           |" << endl;
			cout << "       5. Find Parent               |" << endl;
			cout << "       6. Find Child                |" << endl;
			cout << "       7. Connect Relasi            |" << endl;
			cout << "       8. View Data Relasi          |" << endl;
			cout << "       9. Find Relasi               |" << endl;
			cout << "       10. Disconnect Relasi        |" << endl;
			cout << "       11. Delete Parent            |" << endl;
			cout << "       12. Delete Child             |" << endl;
			cout << "       13. Sort Relasi              |" << endl;
			cout << "       14. Delete Relasi by Parent  |" << endl;
			cout << "       15. Delete Relasi by Child   |" << endl;
			cout << "       0. Exit                      |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Input Menu : ";
			cin >> pilihan;
			switch (pilihan) {
				case 1: system("CLS");insertParent(); system("break"); break;
				case 2: system("CLS");insertChild(); system("break"); break;
				case 3: system("CLS");viewParent(); system("break"); break;
				case 4: viewChild(); system("break"); break;
				case 5: findParent(); system("break"); break;
				case 6: findChild(); system("break"); break;
				case 7: connectRelasi(); system("break"); break;
				case 8: viewRelasi(); system("break"); break;
				case 9: searchRelasi(); system("break"); break;
				case 10: disconnectRelasi(); system("break"); break;
				case 11: deleteParent(); system("break"); break;
				case 12: deleteChild(); system("break"); break;
				case 13: sortRelasi(); system("break"); break;
				case 14: deleterparent();system("break"); break;
				case 15: deleterchild();system("break");break;
				case 0: makasihpak(); system("break"); break;
			}
		} while(pilihan != 0);
}

void makasihpak() {
	cout << "\n...\n" << endl;
}

/**
* NIM : 1301164407
* Nama : Ikhsan Ramadhan B
* Operasi Parent, Disconnect, Search, Sort Relasi
**/

void insertParent() {
	cout << "Insert Data Parent\n" << endl;
	cout << "ID Pos     : ";
	cin >> Xp.id_pos;

	cout << "Nama Pos   : ";
	cin >> Xp.nama_pos;

	cout << "Alamat Pos : ";
	cin >> Xp.alamat_pos;

	cout << "RT         : ";
	cin >> Xp.no_rt;

	cout << "RW         : ";
	cin >> Xp.no_rw;

	cout << "Telp Pos   : ";
	cin >> Xp.telp_pos;
	Pp = alokasiParent(Xp);
	if(first(Lp) == NULL) {
		insertAscendingParent(Lp, Pp);
		cout << "Success!!" << endl;
	} else {
		if(findElmParent(Lp, Xp) == NULL) {
			insertAscendingParent(Lp, Pp);
			cout << "Success!!" << endl;
		} else {
			cout << "\nID " << Xp.id_pos << " ID Used,Please Re-Input\n" << endl;
		}
	}
}

void findParent() {
	cout << "Find Data Parent" << endl;
	cout << "ID Pos : ";
	cin >> Xp.id_pos;
	Pp = findElmParent(Lp, Xp);
	if(Pp == NULL) {
		cout << "Not Found" << endl;
	} else {
		printByIDParent(Lp, Pp);
	}
}

void viewParent() {
	printInfoParent(Lp);
}

void deleteParent() {
	cout << "Delete Data Parent\n" << endl;
	cout << "Input ID Parent : ";
	cin >> Xp.id_pos;
	deleteByIDParent(Lp, Xp);
}

void deleterparent() {
    cout << "Find Data Parent" << endl;
	cout << "ID Pos : ";
	cin >> Xp.id_pos;
	Pp = findElmParent(Lp, Xp);
        deleteRelasiByParent(Lr, Pp);
}

void disconnectRelasi() {
	cout << "Input ID Parent" << endl;
	cout << "ID Pos : ";
	cin >> Xp.id_pos;
	Pp = findElmParent(Lp, Xp);
	cout << "Input ID Child" << endl;
	cout << "ID Satpam : ";
	cin >> Xc.id_satpam;
	Pc = findElmChild(Lc, Xc);
	if(Pp == NULL || Pc == NULL) {
		cout << "Not Found" << endl;
	} else {
        Pr = findElmRelasi(Lr, Pp, Pc);
		disconnectRelasi(Lr, Pr);
	}
}

void searchRelasi() {
	cout << "Input ID Parent" << endl;
	cout << "ID Pos : ";
	cin >> Xp.id_pos;
	Pp = findElmParent(Lp, Xp);
	cout << "Input ID Child" << endl;
	cout << "ID Satpam : ";
	cin >> Xc.id_satpam;
	Pc = findElmChild(Lc, Xc);
	if(Pp == NULL || Pc == NULL) {
		cout << "Not Found" << endl;
	} else {
        Pr = findElmRelasi(Lr, Pp, Pc);
        if(Pr != NULL) {
        	cout << "Found!" << endl;
        } else {
        	cout << "Not Found!" << endl;
        }
	}
}

void sortRelasi() {
	sortRelasi(Lr);
}


/**
* NIM : 1301164153
* Nama : Muhammad Hanur Yoga Wijaya
* Operasi Child, Connect, View, Insert Relasi
**/

void insertChild() {
	cout << "Insert Child" << endl;
	cout << "ID Satpam      : ";
	cin >> Xc.id_satpam;
	cout << "Nama Satpam    : ";
	cin >> Xc.nama_satpam;
	cout << "Umur           : ";
	cin >> Xc.umur;
	cout << "Jenis Kelamin  : ";
	cin >> Xc.jenis_kelamin;
	cout << "Shift          : ";
	cin >> Xc.shift;
	cout << "No Telp        : ";
	cin >> Xc.no_telp;
	Pc = alokasiChild(Xc);
	if(first(Lc) == NULL) {
		insertAscendingChild(Lc, Pc);
	} else {
		if(findElmChild(Lc, Xc) == NULL) {
			insertAscendingChild(Lc, Pc);
		} else {
			cout << "\nID " << Xc.id_satpam << " ID Used, Please Re-Input!\n" << endl;
		}
	}
}

void findChild() {
	cout << "Find Data" << endl;
	cout << "ID Satpam : ";
	cin >> Xc.id_satpam;
	Pc = findElmChild(Lc, Xc);
	if(Pc == NULL) {
		cout << "Not Found" << endl;
	} else {
		printByIDChild(Lc, Pc);
	}
}

void viewChild() {
	printInfoChild(Lc);
}

void deleteChild() {
	cout << "Delete Data Child\n" << endl;
	cout << "Input ID Satpam : ";
	cin >> Xc.id_satpam;
	deleteByIDChild(Lc, Xc);
}

void connectRelasi() {
	cout << "Input ID Parent" << endl;
	cout << "ID Pos : ";
	cin >> Xp.id_pos;
	Pp = findElmParent(Lp, Xp);
	cout << "Input ID Child" << endl;
	cout << "ID Satpam : ";
	cin >> Xc.id_satpam;
	Pc = findElmChild(Lc, Xc);
	if(Pp == NULL || Pc == NULL) {
		cout << "Not Found" << endl;
	} else {
        Pr = findElmRelasi(Lr, Pp, Pc);
        if(Pr == NULL) {
		    insertLastRelasi(Lr, connectRelasi(Pp, Pc));
        } else {
            cout << "Used!" << endl;
        }
	}
}

void viewRelasi() {
	printInfoRelasi(Lr);
}

void deleterchild() {
  cout << "Find Data Child" << endl;
	cout << "ID Satpam : ";
	cin >> Xc.id_satpam;
	Pc = findElmChild (Lc, Xc);
        deleteRelasiByChild(Lr, Pc);
}
