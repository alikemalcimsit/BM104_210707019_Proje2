/*
ALİ KEMAL CİMŞİT 
210707019
BİLGİSAYAR MÜHENDİSLİĞİ(Ö.Ö)
BM104 NESNEYE YÖNELİK PROGRAMLAMA
BAHAR 2022
PROJE 1
AHMET COŞKUNÇAY
*/
#include <iostream>
using namespace std;
#include "BM104_210707019_Proje1.h"
#include <locale.h>

int main()
{// dizideki rakam sayısı ve rastgele sayıların alt , üst limit bilgisini constructora yollar
    setlocale(LC_ALL, "Turkish");
    int selectedElement;
    cout << "Dizideki rakam sayısını girin :";
    cin >> selectedElement;
    BM104_210707109_Proje1 nsn(selectedElement, 1, 10);
    nsn.PlayGame();
    return 0;
}

