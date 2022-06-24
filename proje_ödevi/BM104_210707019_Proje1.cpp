/*
ALÝ KEMAL CÝMÞÝT
210707019
BÝLGÝSAYAR MÜHENDÝSLÝÐÝ(Ö.Ö)
BM104 NESNEYE YÖNELÝK PROGRAMLAMA
BAHAR 2022
PROJE 1
AHMET COÞKUNÇAY
*/
#include<cstdlib>
#include <iostream>
#include<ctime>
#include "BM104_210707019_Proje1.h"
using namespace std;
#include<string>
// consructor a verdiðimiz deðiþkenleri class da bulunan deðiþkenlere atar
BM104_210707109_Proje1::BM104_210707109_Proje1(int selectedElements, int minlimits, int maxlimits) {
	selectedElement = selectedElements;
	maxLimit = maxlimits;
	minLimit = minlimits;
}
// oyunu çalýþtýrmak için çaðrýlacak föksiyondur
void BM104_210707109_Proje1::PlayGame() {
	RandomNumber();
	GuessControl();
}
// random sayý oluþturmak için kullanýlacak fonksiyondur.Oluþturdupu random sayýlarý diziye aktarýr
void BM104_210707109_Proje1::RandomNumber(){
	srand(time(0));
	for (int i = 0; i <selectedElement; i++) {
		randomNumberArray[i]= rand() % (maxLimit - minLimit + 1) + minLimit;
	}	
}
//tahmin kontrol iþlemlerinin gerçekleþtiði fonksiyondur
void BM104_210707109_Proje1::GuessControl(){
	maxGuess = selectedElement*2;
	int guess;
	int win = 0;
	int value = selectedElement;
	ScreenOperations(value);
	for (int i = 0; i < maxGuess; i++)
	{
		int trueValue = 0;
		cout<<endl << "Bir rakam tahmin edin :";
		cin >> guess;
		for (int c = 0; c < maxGuess; c++)
		{// tüm tahminlerin olduðu kümede yapýlan tahmnin varsa ayný sayýnýn girildiði anlaþýlýr
			if (allGuess[c] == to_string(guess)) {
				cout <<endl<< ("Ayný rakamý girdin ")<<""<<endl;
				cout << "Bir rakam tahmin edin :";
			}
		}
		allGuess[i].assign(to_string(guess));// tahminlerin hepsini diziye aktaran kod
		for (int j = 0; j <selectedElement; j++)
		{//tahmninin dizinn içinde bulunup bulunamdýðýný kontrol eden kýsým
			if (randomNumberArray[j] == guess) {
				cout<<endl<<guess<< " Bulundu"<<endl;
				value--;// ekranda bilinmeyen sayýlar için yazýlan X lerin sayýsý
				trueValue = 1;// doðru yanlýþ kontrolü yapabilmek için gereken deðiþken
				trueGuessArray[win].assign(to_string(guess));// tahmini doðru tahmninlerin olduðu kümeye alýr
				win++;// kaç doðru tahmin yaptýýný sayar
				ScreenOperations(value);	
			}
		}
		if (trueValue==0)
		{// tahmin bulunmassa buraya gier
			cout <<guess <<" Bulunamadý"<<endl;
			ScreenOperations(value);
		}
		if (win == selectedElement)
		{// yapýlan doðru tahmin sayýsý rastgele sayý olan dizideki eleman sayýsýna eþit ise oyunu kazanýr
			cout << endl << "Tebrikler KAZANDINIZ!" << endl;;
			break;
		}
	}
	if (win!=selectedElement)
	{
		cout <<endl<< "Üzgünüz KAYBETTÝNÝZ" << endl;
			for (int i = 0; i < selectedElement; i++)
			{
				cout << " "<<randomNumberArray[i];
			}	
	}
}
//dizi içeriðini ve bilinmeyenlerin yerine X yazdýracak fonksyon
void BM104_210707109_Proje1::ScreenOperations(int deðer) {
	cout << "Dizi içeriði : " << endl;
	for (int i = 0; i < deðer; i++)
	{
		cout  << " X ";
	}
	for (int k = 0; k <selectedElement; k++)
	{
		cout << " " << trueGuessArray[k]<<" ";
	}
}
	