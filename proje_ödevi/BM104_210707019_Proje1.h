/*
ALÝ KEMAL CÝMÞÝT
210707019
BÝLGÝSAYAR MÜHENDÝSLÝÐÝ(Ö.Ö)
BM104 NESNEYE YÖNELÝK PROGRAMLAMA
BAHAR 2022
PROJE 1
AHMET COÞKUNÇAY
*/
#include <iostream>
using namespace std;
#include<string>
class BM104_210707109_Proje1
{
public:
	BM104_210707109_Proje1(int, int, int );
	void PlayGame();
private:
	int randomNumberArray[20];//rstgele sayýlarý tutan dizi
	int selectedElement;//oynanacak eleman sayýsý
	int maxGuess;// oynanacak eleman sayýsý *2
	int maxLimit;//rastgele sayýnýn üst limiti
	int minLimit;//rsatgele sayýnýn alt limiti
	string trueGuessArray[20];// doðru tahmnileri tutan dizi
	void RandomNumber();//rastgele sayý üreten fonksiyon
	void GuessControl();//tahmin kontollerinin yapýldýðý dizi
	string allGuess[40];//tüm tahminlerin olduðu dizi
	void ScreenOperations(int);//ekran iþlemlerinin olduðu dizi
};
