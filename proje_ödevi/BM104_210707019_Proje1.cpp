/*
AL� KEMAL C�M��T
210707019
B�LG�SAYAR M�HEND�SL���(�.�)
BM104 NESNEYE Y�NEL�K PROGRAMLAMA
BAHAR 2022
PROJE 1
AHMET CO�KUN�AY
*/
#include<cstdlib>
#include <iostream>
#include<ctime>
#include "BM104_210707019_Proje1.h"
using namespace std;
#include<string>
// consructor a verdi�imiz de�i�kenleri class da bulunan de�i�kenlere atar
BM104_210707109_Proje1::BM104_210707109_Proje1(int selectedElements, int minlimits, int maxlimits) {
	selectedElement = selectedElements;
	maxLimit = maxlimits;
	minLimit = minlimits;
}
// oyunu �al��t�rmak i�in �a�r�lacak f�ksiyondur
void BM104_210707109_Proje1::PlayGame() {
	RandomNumber();
	GuessControl();
}
// random say� olu�turmak i�in kullan�lacak fonksiyondur.Olu�turdupu random say�lar� diziye aktar�r
void BM104_210707109_Proje1::RandomNumber(){
	srand(time(0));
	for (int i = 0; i <selectedElement; i++) {
		randomNumberArray[i]= rand() % (maxLimit - minLimit + 1) + minLimit;
	}	
}
//tahmin kontrol i�lemlerinin ger�ekle�ti�i fonksiyondur
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
		{// t�m tahminlerin oldu�u k�mede yap�lan tahmnin varsa ayn� say�n�n girildi�i anla��l�r
			if (allGuess[c] == to_string(guess)) {
				cout <<endl<< ("Ayn� rakam� girdin ")<<""<<endl;
				cout << "Bir rakam tahmin edin :";
			}
		}
		allGuess[i].assign(to_string(guess));// tahminlerin hepsini diziye aktaran kod
		for (int j = 0; j <selectedElement; j++)
		{//tahmninin dizinn i�inde bulunup bulunamd���n� kontrol eden k�s�m
			if (randomNumberArray[j] == guess) {
				cout<<endl<<guess<< " Bulundu"<<endl;
				value--;// ekranda bilinmeyen say�lar i�in yaz�lan X lerin say�s�
				trueValue = 1;// do�ru yanl�� kontrol� yapabilmek i�in gereken de�i�ken
				trueGuessArray[win].assign(to_string(guess));// tahmini do�ru tahmninlerin oldu�u k�meye al�r
				win++;// ka� do�ru tahmin yapt��n� sayar
				ScreenOperations(value);	
			}
		}
		if (trueValue==0)
		{// tahmin bulunmassa buraya gier
			cout <<guess <<" Bulunamad�"<<endl;
			ScreenOperations(value);
		}
		if (win == selectedElement)
		{// yap�lan do�ru tahmin say�s� rastgele say� olan dizideki eleman say�s�na e�it ise oyunu kazan�r
			cout << endl << "Tebrikler KAZANDINIZ!" << endl;;
			break;
		}
	}
	if (win!=selectedElement)
	{
		cout <<endl<< "�zg�n�z KAYBETT�N�Z" << endl;
			for (int i = 0; i < selectedElement; i++)
			{
				cout << " "<<randomNumberArray[i];
			}	
	}
}
//dizi i�eri�ini ve bilinmeyenlerin yerine X yazd�racak fonksyon
void BM104_210707109_Proje1::ScreenOperations(int de�er) {
	cout << "Dizi i�eri�i : " << endl;
	for (int i = 0; i < de�er; i++)
	{
		cout  << " X ";
	}
	for (int k = 0; k <selectedElement; k++)
	{
		cout << " " << trueGuessArray[k]<<" ";
	}
}
	