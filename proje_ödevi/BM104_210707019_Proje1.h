/*
AL� KEMAL C�M��T
210707019
B�LG�SAYAR M�HEND�SL���(�.�)
BM104 NESNEYE Y�NEL�K PROGRAMLAMA
BAHAR 2022
PROJE 1
AHMET CO�KUN�AY
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
	int randomNumberArray[20];//rstgele say�lar� tutan dizi
	int selectedElement;//oynanacak eleman say�s�
	int maxGuess;// oynanacak eleman say�s� *2
	int maxLimit;//rastgele say�n�n �st limiti
	int minLimit;//rsatgele say�n�n alt limiti
	string trueGuessArray[20];// do�ru tahmnileri tutan dizi
	void RandomNumber();//rastgele say� �reten fonksiyon
	void GuessControl();//tahmin kontollerinin yap�ld��� dizi
	string allGuess[40];//t�m tahminlerin oldu�u dizi
	void ScreenOperations(int);//ekran i�lemlerinin oldu�u dizi
};
