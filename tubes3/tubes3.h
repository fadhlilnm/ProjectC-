#ifndef TUBES2_H_INCLUDED
#define TUBES2_H_INCLUDED

#include <iostream>

using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define penumpang(P) (P)->penumpang
#define first(L) (L).first
#define last(L) (L).last

struct Penumpang{
    string name, from, to, ttime;
};

struct Bis{
    string origin, destination, time, busCode;
    int capacity;
};

typedef Penumpang infotypep;
typedef Bis infotypeb;
typedef struct elmPenumpang *adrPenumpang;
typedef struct elmBis *adrBis;

struct elmPenumpang{
    infotypep info;
    adrPenumpang next;
};

struct elmBis{
    infotypeb info;
    adrBis next;
    adrPenumpang penumpang;
};

// circular single linked list
struct ListBis{
    adrBis first;
};

// Membuat list bis
void createListBis(ListBis &LB);
// Insert data bis dari depan
void insertBis(ListBis &LB, string busCode, string origin, string destination, string time, int capacity);
// Mencari data bis
adrBis SearchBis(ListBis LB, string from, string to, string ttime);
// Insert data penumpang & menghubungkan data penumpang ke data bis
void insertPenumpang(ListBis &LB, string name, string from, string to, string ttime);
// Menghapus data bis dan penumpangnya
void deleteBis(ListBis &LB, string busCode);
// Mencari data penumpang pada bis tertentu
adrPenumpang SearchPenumpangFromBis(ListBis LB, string from, string to, string ttime, string name);
// Menghapus data penumpang pada bis tertentu
void deletePenumpang(ListBis &LB, string from, string to, string ttime ,string name);
// Show all data bis
void showAllBis(ListBis LB);
// Menampilkan seluruh data bis beserta penumpangnya
void showAllBisWithPenumpang(ListBis LB);
// Menampilkan bis yang memiliki penumpang paling sedikit
void showBisSedikitPenumpang(ListBis LB);

int selectMenu();

#endif // TUBES2_H_INCLUDED
