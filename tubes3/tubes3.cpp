#include "tubes3.h"

// Create bis list
void createListBis(ListBis &LB){
    first(LB) = NULL;
}

// Insert data bis dari depan
void insertBis(ListBis &LB, string busCode, string origin, string destination, string time, int capacity){
    adrBis P = new elmBis;
    info(P).busCode = busCode;
    info(P).origin = origin;
    info(P).destination = destination;
    info(P).time = time;
    info(P).capacity = capacity;
    penumpang(P) = NULL;
    next(P) = NULL;

//    if(first(LB)==NULL){
//        first(LB) = P;
//
//    } else{
//        next(P) = first(LB);
//        first(LB) = P;
//    }

// algoritma dibawah adalah insert first dengan CSLL, tapi tidak bisa di run, padahal sudah sesuai algoritmanya
    if(first(LB)==NULL){
        first(LB) = P;
        next(P) = first(LB);
    } else{
        adrBis Q = first(LB);
        while(next(Q)!=first(LB)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(LB);
        first(LB) = P;
    }
}

// Mencari data bis
adrBis SearchBis(ListBis LB, string from, string to, string ttime){
    adrBis P = first(LB);
    while(next(P) != first(LB)){
        if(info(P).origin == from && info(P).destination == to && info(P).time == ttime){
            return P;
        }
        P = next(P);
    }
    return NULL;
}

// Insert data penumpang & menghubungkan data penumpang ke data bis
void insertPenumpang(ListBis &LB, string name, string from, string to, string ttime){
    adrPenumpang Q = new elmPenumpang;
    info(Q).name = name;
    info(Q).from = from;
    info(Q).to = to;
    info(Q).ttime = ttime;
    next(Q) = NULL;

    adrBis P = SearchBis(LB, from, to, ttime);
    if(P != NULL){
        adrPenumpang R = penumpang(P);
        if(R == NULL){
            penumpang(P) = Q;
        } else {
            while(next(R) != NULL){
                R = next(R);
            }
            next(R) = Q;
        }
        //info(P).capacity = info(P).capacity - 1;
    }
//    else {
//        cout << endl;
//        cout << "!!! Jadwal bis tidak ada yang cocok !!!" << endl;
//        cout << endl;
//    }
}

// Menghapus data bis dan penumpangnya
void deleteBis(ListBis &LB, string busCode){
    adrBis P = first(LB);
    if(info(P).busCode == busCode){
        first(LB) = next(P);
        next(P) = NULL;
        //P = NULL;
    } else {
        while(next(P) != NULL && info(next(P)).busCode != busCode){
            P = next(P);
        }
        if(next(P) != NULL){
            adrBis Q = next(P);
            next(P) = next(Q);
            next(Q) = NULL;
            //Q = NULL;
        }
    }
    cout << endl;
    cout << "Data bis berhasil dihapus" << endl;
    cout << endl;
}

// Mencari data penumpang pada bis tertentu
adrPenumpang SearchPenumpangFromBis(ListBis LB, string from, string to, string ttime, string name){
    adrBis P = SearchBis(LB, from, to, ttime);
    if (P!=NULL){
        adrPenumpang Q = penumpang(P);
            while(Q != NULL){
                if(info(Q).name == name){
                    return Q;
                }
                Q = next(Q);
            }
    }
    return NULL;
}

// Menghapus data penumpang pada bis tertentu
void deletePenumpang(ListBis &LB, string from, string to, string ttime ,string name){
    adrBis P = SearchBis(LB, from, to, ttime);
    if(P != NULL){
        adrPenumpang Q = SearchPenumpangFromBis(LB, from, to, ttime, name);
        if(Q != NULL){
            if(penumpang(P) == Q){
                penumpang(P) = next(Q);
            }
            else{
                adrPenumpang R = penumpang(P);
                while(next(R) != Q){
                    R = next(R);
                }
                next(R) = next(Q);
            }
        }
        //info(P).capacity = info(P).capacity - 1;
    } else{
        cout << "Data Penumpang tidak ditemukan" << endl;
    }
}

// Show all data bis
void showAllBis(ListBis LB){
    adrBis P = first(LB);
    cout << "---------------------------------------------------------" << endl;
    cout << "Kode Bis   Asal         Tujuan\t\tWaktu\tKapasitas" << endl;
    cout << "---------------------------------------------------------" << endl;
    while(next(P) != first(LB)){
        cout << "   "<< info(P).busCode << "\t" << "   "<< info(P).origin << "\t" << info(P).destination << "   \t" << info(P).time << "\t" << info(P).capacity << endl;
        P = next(P);
    }
    cout << "   "<< info(P).busCode << "\t" << "   "<< info(P).origin << "\t" << info(P).destination << "   \t" << info(P).time << "\t" << info(P).capacity << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
}

// Menampilkan seluruh data bis beserta penumpangnya
void showAllBisWithPenumpang(ListBis LB){
    adrBis P = first(LB);
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Kode Bis   Asal         Tujuan\t\tWaktu\tKapasitas\tPenumpang" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    while(next(P)!=first(LB)){
        cout << "   "<< info(P).busCode << "\t" << "   "<< info(P).origin << "\t" << info(P).destination << "   \t" << info(P).time << "      " << info(P).capacity << endl;
        adrPenumpang Q = penumpang(P);
        while(Q != NULL){
            cout << "\t\t\t\t\t\t\t\t" << info(Q).name << endl;
            Q = next(Q);
        }
        cout << "_________________________________________________________________________" << endl;
        cout << endl;
        P = next(P);
    }
    cout << "   "<< info(P).busCode << "\t" << "   "<< info(P).origin << "\t" << info(P).destination << "   \t" << info(P).time << "      " << info(P).capacity << endl;
}

// Menampilkan bis yang memiliki penumpang paling sedikit
void showBisSedikitPenumpang(ListBis LB){
    adrBis P = first(LB);
    int minPenumpang = 9999999;
    adrBis minBis;
    while(P != NULL){
        int count = 0;
        adrPenumpang Q = penumpang(P);
        while(Q != NULL){
            count++;
            Q = next(Q);
        }
        if(count < minPenumpang){
            minPenumpang = count;
            minBis = P;
        }
        P = next(P);
    }
    cout << "Bis Dengan Penumpang Paling Sedikit" << endl;
    cout << "Kode Bis\t: " << info(minBis).busCode << endl;
    cout << "Asal\t\t: " << info(minBis).origin << endl;
    cout << "Tujuan\t\t: " << info(minBis).destination << endl;
    cout << "Waktu\t\t: " << info(minBis).time << endl;
    cout << "Sisa Kapasitas\t: " << info(minBis).capacity << endl;
    cout << "Total Penumpang\t: " << minPenumpang << endl;
    cout << endl;
}

int selectMenu(){
    cout << "==============" << endl;
    cout << "---- Menu ----" << endl;
    cout << "==============" << endl;
    cout << endl;
    cout << "1. Insert data bis dari depan" << endl;
    cout << "2. Show all data bis " << endl;
    cout << "3. Menghapus data bis dan penumpangnya " << endl;
    cout << "4. Mencari data bis" << endl;
    cout << "5. Insert data penumpang" << endl;
    cout << "6. Menampilkan seluruh data bis beserta penumpangnya " << endl;
    cout << "7. Mencari data penumpang pada bis tertentu" << endl;
    cout << "8. Menghapus data penumpang pada bis tertentu" << endl;
    cout << "9. Menampilkan bis yang memiliki penumpang paling sedikit" << endl;
    cout << "0. Exit" <<endl;
    cout << endl;
    cout << "Masukkan Menu: ";
    int input = 0;
    cin >> input;
    return input;
}
