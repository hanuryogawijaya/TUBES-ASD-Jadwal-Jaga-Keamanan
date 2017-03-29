#include <iostream>
#include <stdlib.h>
#include "parent.h"
#include "child.h"
#include "relasi.h"
#include "menu.h"

address_p PP = NULL;
address_p Prec_P = NULL;
address_c PC = NULL;
address_c Prec_C = NULL;
address_r PR = NULL;
infotype_p XP;
infotype_c XC;
List_p LP;
List_c LC;
List_r LR;

void Menu() {
    createListParent(LP);
	createListChild(LC);
	createListRelasi(LR);
	int pilihan;
	 while(pilihan != 0){
            cout << "                                     " << endl;
            cout << "-------------------------------------" << endl;
			cout << "-------- JADWAL JAGA KEAMANAN -------" << endl;
            cout << "------------- LINGKUNGAN ------------" << endl;
			cout << "-------------------------------------" << endl;
			cout << "       1. Insert Data Pos           |" << endl;
			cout << "       2. Insert Data Satpam        |" << endl;
			cout << "       3. Lihat Data Pos            |" << endl;
			cout << "       4. Lihat Data Satpam         |" << endl;
			cout << "       5. Cari Pos                  |" << endl;
			cout << "       6. Cari Satpam               |" << endl;
			cout << "       7. Register Satpam Ke Pos    |" << endl;
			cout << "       8. Lihat Data Jaga           |" << endl;
			cout << "       9. Cari Data Jaga            |" << endl;
			cout << "       10. Unreg Satpam Ke Pos      |" << endl;
			cout << "       11. Delete Data Pos          |" << endl;
			cout << "       12. Delete Data Satpam       |" << endl;
			cout << "       13. Sort Data Jaga           |" << endl;
			cout << "       14. Delete Data Jaga (Pos)   |" << endl;
			cout << "       15. Delete Data Jaga (Satpam)|" << endl;
			cout << "       0. Keluar                    |" << endl;
			cout << "--------------------------------------" << endl;
			cout << "Input Menu : ";
			cin >> pilihan;
			switch (pilihan) {
				case 1: system("CLS");insertparent(); system("break"); break;
				case 2: system("CLS");insertchild(); system("break"); break;
				case 3: lihatparent(); system("break"); break;
				case 4: lihatchild(); system("break"); break;
				case 5: cariparent(); system("break"); break;
				case 6: carichild(); system("break"); break;
				case 7: sambungrelasi(); system("break"); break;
				case 8: lihatrelasi(); system("break"); break;
				case 9: carirelasi(); system("break"); break;
				case 10: putusrelasi(); system("break"); break;
				case 11: deleteparent(); system("break"); break;
				case 12: deletechild(); system("break"); break;
				case 13: sortrelasi(); system("break"); break;
				case 14: deleterparent();system("break"); break;
				case 15: deleterchild();system("break");break;
				case 0: makasihpak(); system("break"); break;
			}
		}
}

void makasihpak() {
	cout << "\n...\n" << endl;
}

/* NIM : 1301164407
Nama : Ikhsan Ramadhan B */

void insertparent() {
	cout << "Insert Data Parent\n" << endl;
	cout << "ID Pos     : ";
	cin >> XP.id_pos;

	cout << "Nama Pos   : ";
	cin >> XP.nama_pos;

	cout << "Alamat Pos : ";
	cin >> XP.alamat_pos;

	cout << "RT         : ";
	cin >> XP.no_rt;

	cout << "RW         : ";
	cin >> XP.no_rw;

	cout << "Telp Pos   : ";
	cin >> XP.telp_pos;
	PP = alokasiParent(XP);
	if(first(LP) == NULL) {
		insertAscendingParent(LP, PP);
		cout << "Success!!" << endl;
	} else {
		if(findElmParent(LP, XP) == NULL) {
			insertAscendingParent(LP, PP);
			cout << "Success!!" << endl;
		} else {
			cout << "\nID " << XP.id_pos << " ID Used,Please Re-Input\n" << endl;
		}
	}
}

void cariparent() {
	cout << "Find Data Parent" << endl;
	cout << "ID Pos : ";
	cin >> XP.id_pos;
	PP = findElmParent(LP, XP);
	if(PP == NULL) {
		cout << "Not Found" << endl;
	} else {
		printByIDParent(LP, PP);
	}
}

void lihatparent() {
	printInfoParent(LP);
}

void deleteparent() {
	cout << "Delete Data Parent\n" << endl;
	cout << "Input ID Parent : ";
	cin >> XP.id_pos;
	deleteByIDParent(LP, XP);
}

void deleterparent() {
    cout << "Find Data Parent" << endl;
	cout << "ID Pos : ";
	cin >> XP.id_pos;
	PP = findElmParent(LP, XP);
        deleteRelasiByParent(LR, PP);
}

void putusrelasi() {
	cout << "Input ID Parent" << endl;
	cout << "ID Pos : ";
	cin >> XP.id_pos;
	PP = findElmParent(LP, XP);
	cout << "Input ID Child" << endl;
	cout << "ID Satpam : ";
	cin >> XC.id_satpam;
	PC = findElmChild(LC, XC);
	if(PP == NULL || PC == NULL) {
		cout << "Not Found" << endl;
	} else {
        PR = findElmRelasi(LR, PP, PC);
		disconnectRelasi(LR, PR);
	}
}

void carirelasi() {
	cout << "Input ID Parent" << endl;
	cout << "ID Pos : ";
	cin >> XP.id_pos;
	PP = findElmParent(LP, XP);
	cout << "Input ID Child" << endl;
	cout << "ID Satpam : ";
	cin >> XC.id_satpam;
	PC = findElmChild(LC, XC);
	if(PP == NULL || PC == NULL) {
		cout << "Not Found" << endl;
	} else {
        PR = findElmRelasi(LR, PP, PC);
        if(PR != NULL) {
        	cout << "Found!" << endl;
        } else {
        	cout << "Not Found!" << endl;
        }
	}
}

void lihatrelasi() {
	printInfoRelasi(LR);
}

void sortrelasi() {
	sortRelasi(LR);
}


/* NIM : 1301164153
Nama : Muhammad Hanur Yoga Wijaya */

void insertchild() {
	cout << "Insert Child" << endl;
	cout << "ID Satpam      : ";
	cin >> XC.id_satpam;

	cout << "Nama Satpam    : ";
	cin >> XC.nama_satpam;

	cout << "Umur           : ";
	cin >> XC.umur;

	cout << "Jenis Kelamin  : ";
	cin >> XC.jenis_kelamin;

	cout << "Shift          : ";
	cin >> XC.shift;

	cout << "No Telp        : ";
	cin >> XC.no_telp;

	PC = alokasiChild(XC);
	if(first(LC) == NULL) {
		insertAscendingChild(LC, PC);
	}
	else {
		if(findElmChild(LC, XC) == NULL) {
			insertAscendingChild(LC, PC);
		}
		else {
			cout << "\nID " << XC.id_satpam << " ID Used, Please Re-Input!\n" << endl;
		}
	}
}

void carichild() {
	cout << "Find Data" << endl;
	cout << "ID Satpam : ";
	cin >> XC.id_satpam;
	PC = findElmChild(LC, XC);
	if(PC == NULL) {
		cout << "Not Found" << endl;
	} else {
		printByIDChild(LC, PC);
	}
}

void lihatchild() {
	printInfoChild(LC);
}

void deletechild() {
	cout << "Delete Data Child\n" << endl;
	cout << "Input ID Satpam : ";
	cin >> XC.id_satpam;
	deleteByIDChild(LC, XC);
}

void sambungrelasi() {
	cout << "Input ID Parent" << endl;
	cout << "ID Pos : ";
	cin >> XP.id_pos;
	PP = findElmParent(LP, XP);
	cout << "Input ID Child" << endl;
	cout << "ID Satpam : ";
	cin >> XC.id_satpam;
	PC = findElmChild(LC, XC);
	if(PP == NULL || PC == NULL) {
		cout << "Not Found" << endl;
	} else {
        PR = findElmRelasi(LR, PP, PC);
        if(PR == NULL) {
		    insertLastRelasi(LR, connectRelasi(PP, PC));
        } else {
            cout << "Used!" << endl;
        }
	}
}

void deleterchild() {
  cout << "Find Data Child" << endl;
	cout << "ID Satpam : ";
	cin >> XC.id_satpam;
	PC = findElmChild (LC, XC);
        deleteRelasiByChild(LR, PC);
}
