#include "tubes3.h"

int main()
{
    cout << "RASHAD IZZA ANDREDI (1301213309) | FADHLIL NAUFAL MAHARDIAN (1301213034)" << endl;
    ListBis LB;
    createListBis(LB);

    insertBis(LB, "B1", "Jakarta", "Surabaya", "06:00", 50);
    insertBis(LB, "B2", "Jakarta", "Bandung", "07:00", 40);
    insertBis(LB, "B3", "Surabaya", "Jakarta", "08:00", 45);
    insertBis(LB, "B4", "Bandung", "Jakarta", "09:00", 35);

    insertPenumpang(LB, "Alice", "Jakarta", "Surabaya", "06:00");
    insertPenumpang(LB, "Charlie", "Surabaya", "Jakarta", "08:00");
    insertPenumpang(LB, "David", "Jakarta", "Surabaya", "06:00");
    insertPenumpang(LB, "Eve", "Bandung", "Jakarta", "09:00");
    insertPenumpang(LB, "Frank", "Bandung", "Jakarta", "09:00");
    insertPenumpang(LB, "Austin", "Bandung", "Jakarta", "09:00");


//    // Show all buses with passengers
//    showAllBisWithPenumpang(LP, LB);
//
//    cout << "=====================================================" <<endl;
//    // Delete a bus and its passengers
//    deleteBis(LB, LP, "B2");
////
//    // Show all buses with passengers
//    showAllBisWithPenumpang(LP, LB);
////
//    // Show bus with the least passengers
//    showBisWithTheLeastPenumpang(LP, LB);

    string busCode, origin, destination, time;
    int capacity;
    string name, from, to, ttime;

    int i = 1;
    int n;
    int pilihan = selectMenu();

    while (pilihan!=0){
        cout << endl;
        if (pilihan==1){
            cout << "Jumlah bis yang ditambahkan: ";
            cin >> n;
            while (i<=n){
                cout << "Kode Bis: ";
                cin >> busCode;
                cout << "Asal: ";
                cin >> origin;
                cout << "Tujuan: ";
                cin >> destination;
                cout << "Jam Keberangkatan: ";
                cin >> time;
                cout << "Kapasitas: ";
                cin >> capacity;
                cout << endl;
                insertBis(LB, busCode, origin, destination, time, capacity);
                i++;
            }
        } else if(pilihan==2){
            showAllBis(LB);
        } else if(pilihan==3){
            cout << "Masukkan kode bis yang ingin dihapus : ";
            cin >> busCode;
            deleteBis(LB, busCode);
        } else if(pilihan==4){
            cout << "Asal: ";
            cin >> from;
            cout << "Tujuan: ";
            cin >> to;
            cout << "Jam Keberangkatan: ";
            cin >> ttime;
            adrBis B1 = SearchBis(LB, from, to, ttime);
            if(B1==NULL){
                cout << endl;
                cout << "Data bis tidak ditemukan" << endl;
                cout << endl;
            } else {
                cout << endl;
                cout << "Hasil data yang dicari" << endl;
                cout << "Kode Bis\t: " << info(B1).busCode << endl;
                cout << "Asal\t\t: " << info(B1).origin << endl;
                cout << "Tujuan\t\t: " << info(B1).destination << endl;
                cout << "Jam\t\t: " <<info(B1).time << endl;
                cout << "Kapasitas\t: " <<info(B1).capacity << endl;
                cout << endl;
            }
        } else if(pilihan==5){
            cout << "Nama: ";
            cin >> name;
            cout << "Dari: ";
            cin >> from;
            cout << "Ke: ";
            cin >> to;
            cout << "Jam Keberangkatan: ";
            cin >> ttime;
            insertPenumpang(LB, name, from, to, ttime);
        } else if(pilihan==6){
            showAllBisWithPenumpang(LB);
        } else if(pilihan==7){
            cout << "Nama: ";
            cin >> name;
            cout << "Kode Bis: ";
            cin >> busCode;
            adrBis B2 = first(LB);
            while(info(B2).busCode!=busCode && B2!=NULL){
                B2 = next(B2);
            }
            if (info(B2).busCode==busCode){
                adrPenumpang P = SearchPenumpangFromBis(LB, info(B2).origin, info(B2).destination, info(B2).time, name);
                if(P!=NULL){
                    cout << endl;
                    cout << "Hasil data yang dicari" << endl;
                    cout << "Nama\t: " << info(P).name << endl;
                    cout << "Dari\t: " << info(P).from << endl;
                    cout << "Ke\t: " << info(P).to << endl;
                    cout << "Jam\t: " <<info(P).ttime << endl;
                    cout << endl;
                } else {
                    cout << endl;
                    cout << "Data penumpang tidak ditemukan" << endl;
                    cout << endl;
                }
            } else {
                cout << endl;
                cout << "Kode bis tidak ditemukan" << endl;
                cout << endl;
            }
        } else if(pilihan==8){
            cout << "Masukkan nama yang ingin dihapus : ";
            cin >> name;
            cout << "Dari: ";
            cin >> from;
            cout << "Tujuan: ";
            cin >> to;
            cout << "waktu: ";
            cin >> ttime;
            deletePenumpang(LB, from, to, ttime, name);
        } else if(pilihan==9){
            showBisSedikitPenumpang(LB);
        } else{
            cout << "Input menu tidak valid!" << endl;
            cout << endl;
        }
        pilihan = selectMenu();
    }
    cout << "Anda Telah Keluar Dari Program" << endl;

    return 0;
}
