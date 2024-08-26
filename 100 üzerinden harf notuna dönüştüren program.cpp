
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<locale>
using namespace std;
struct Ogrenci {   // ��rencilerin bilgilerinin oldu�u struct.
	string adi;
	string soyadi;
	int no;
	int kisaSinav1;
	int kisaSinav2;
	int odev1;
	int odev2;
	int proje;
	int vize;
	int final;
	float y�l��i;
	float ba�ar�Notu;

	struct tarihler {  // tarih struct�n par�as� ve ayn� zamanda ayr� structt�r.
		int g�n;
		int ay;
		int y�l;
	};
	tarihler tarih;
};
Ogrenci ogrenciler[100];
string Notlar�harfaDonusturme(float notu) {		// girilen notlar� harf de�erine d�n��t�ren fonksiyon. ( Harf de�erleri internetten baz al�narak de�er verilmi�tir.
	string harfNot = "xx";
	if (notu >= 90 && notu <= 100)
		harfNot = "AA";
	else if (notu >= 85 && notu < 90)
		harfNot = "BA";
	else if (notu >= 80 && notu < 85)
		harfNot = "BB";
	else if (notu >= 70 && notu < 80)
		harfNot = "CB";
	else if (notu >= 60 && notu < 70)
		harfNot = "CC";
	else if (notu >= 55 && notu < 60)
		harfNot = "DC";
	else if (notu >= 50 && notu < 55)
		harfNot = "DD";
	else if (notu >= 40 && notu < 40)
		harfNot = "FD";
	else harfNot = "FF";
	return harfNot;
}  int ��renciadedi = 100;
void standartsapma() {
	float aritmetikO = 0, varyans = 0, varyansT = 0;
	for (int i = 0; i < ��renciadedi; i++) {
		aritmetikO = aritmetikO + (ogrenciler[i].ba�ar�Notu / ��renciadedi);
	}
	for (int i = 0; i < ��renciadedi; i++) {
		varyans = pow(ogrenciler[i].ba�ar�Notu - aritmetikO, 2);
		varyansT += varyans;
	}
	varyansT /= (��renciadedi - 1);
	varyansT = sqrt(varyansT);
	cout << "Standart Sapmas�: " << varyansT << endl;
}
bool do�rude�ergirildimi(int notu) {	// girilen not de�erlerinin 0 ile 100 aras�nda olup ulmad���n� kontrol eden fonksiyon			
	if (notu >= 0 && notu <= 100) return 1;
	else return 0;
}
void enBuyukNot() {   // girilen notlar aras�nda en b�y�k notu bulan fonksiyon
	int enBuyukNot = ogrenciler[0].ba�ar�Notu, a = 0;
	for (int i = 0; i < ��renciadedi; i++) {
		if (ogrenciler[a].ba�ar�Notu <= ogrenciler[i].ba�ar�Notu)
		{
			a = i;	enBuyukNot = ogrenciler[i].ba�ar�Notu;
		}
	}
	cout << "En y�ksek not: " << enBuyukNot;
}
void enKucukNot() { // girilen notlar aras�nda en k���k notu bulan fonksiyon
	int enKucukNot = ogrenciler[0].ba�ar�Notu, a = 0;
	for (int i = 0; i < ��renciadedi; i++) {
		if (ogrenciler[a].ba�ar�Notu >= ogrenciler[i].ba�ar�Notu)
		{
			a = i; enKucukNot = ogrenciler[i].ba�ar�Notu;
		}
	}
	cout << "En d���k not: " << enKucukNot;
}
void ogrenciYazdir() {  // ��rencileri yazd�rmak i�in kullan�lan fonksiyon
	for (int i = 0; i < ��renciadedi; i++) {
		if (i % 20 == 0) {
			system("pause");
			system("cls");
		}
		cout << "Ad� soyad� : " << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << endl;
		cout << "Numaras�: " << ogrenciler[i].no << endl;
		cout << "do�um tarihi:" << ogrenciler[i].tarih.g�n << "." << ogrenciler[i].tarih.ay << "." << ogrenciler[i].tarih.y�l << endl;
		cout << "K�sa s�nav 1: " << ogrenciler[i].kisaSinav1 << endl;
		cout << "K�sa s�nav 2: " << ogrenciler[i].kisaSinav2 << endl;
		cout << "�dev 1: " << ogrenciler[i].odev1 << endl;
		cout << "�dev 2: " << ogrenciler[i].odev2 << endl;
		cout << "Proje: " << ogrenciler[i].proje << endl;
		cout << "Vize: " << ogrenciler[i].vize << endl;
		cout << "Final: " << ogrenciler[i].final << endl;
		cout << "Y�l i�i ba�ar� puan�: " << ogrenciler[i].y�l��i << endl;
		cout << "Ba�ar� notu: " << ogrenciler[i].ba�ar�Notu << endl;
		cout << "Harf Notu: " << Notlar�harfaDonusturme(ogrenciler[i].ba�ar�Notu) << endl;
		cout << "********************************************************************" << endl;
	}
}
void s�n�fOrtalamas�() { //S�n�f ortalamas�n� bulan fonksiyon
	float toplamBasariNot = 0;
	for (int i = 0; i < ��renciadedi; i++) {
		toplamBasariNot += ogrenciler[i].ba�ar�Notu;
	}
	toplamBasariNot = toplamBasariNot / ��renciadedi;
	cout << toplamBasariNot;
}
void notaral���() {   // 2 ba�ar�  notu aras�nda ka� tane not oldu�unu bulan fonksiyon
	int belirlisay�1;
	int belirlisay�2;
	cout << "not aral���n� bulmak istedi�iniz 2 say�y� giriniz" << endl;
	cin >> belirlisay�1 >> belirlisay�2;
	for (int i = 0; i < ��renciadedi; i++)
		if (ogrenciler[i].ba�ar�Notu< belirlisay�1 && ogrenciler[i].ba�ar�Notu >belirlisay�2)
			cout << ogrenciler[i].adi << ogrenciler[i].soyadi << endl;
		else if (ogrenciler[i].ba�ar�Notu > belirlisay�1 && ogrenciler[i].ba�ar�Notu < belirlisay�2)
			cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << " " << ogrenciler[i].ba�ar�Notu << endl;
}
void nottanalt�() { // girilen bir ba�ar� notundan d���k ba�ar� notlar�n� bulan fonksiyon
	int belirlenensay�;
	cout << "hangi nottan a�a��da notlar� istiyorsunuz giriniz" << endl;
	cin >> belirlenensay�;
	for (int i = 0; i < ��renciadedi; i++)
		if (ogrenciler[i].ba�ar�Notu < belirlenensay�)
			cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << " " << ogrenciler[i].ba�ar�Notu << endl;
}
void nottan�st�() { // girilen bir ba�ar� notundan y�ksek ba�ar� notlar�n� bulan fonksiyon

	int belirlenensay�2;
	cout << "hangi nottan �stte notlar� istiyorsunuz giriniz" << endl;
	cin >> belirlenensay�2;
	for (int i = 0; i < ��renciadedi; i++) {
		if (ogrenciler[i].ba�ar�Notu > belirlenensay�2) {
			cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << " " << ogrenciler[i].ba�ar�Notu << endl;
		}
	}
}
int main() {
	setlocale(LC_ALL, "Turkish");
	int se�enekler;
	cout << "se�enek 1'i se�mek i�in 1'e se�enek 2'yi se�mek i�in 2'ye bas�n�z." << endl;
	cin >> se�enekler;
	while (se�enekler != 1 && se�enekler != 2) {
		cout << "Yanl�� bir se�enek se�tiniz l�tfen tekrar deneyiniz" << endl;
		cin >> se�enekler;
	}
	if (se�enekler == 1) { // se�enek 1 de de�erleri girdi�im 30 isim ve soyisim aras�ndan random belirledi�im 100 ki�iye yine random belirlenen not de�erlerini atad�m.
		float y�l��i = 0.0;
		float ba�ar�Notu = 0.0;
		int a = 0, b=0;
		srand(time(NULL));
		for (int i = 0; i < 100; i++) {
			
			string isim[30] = { "ahmet","mehmet ","ismail","zeynep", "irem", "k�bra","ilknur","sena","hasan","polat","memati","yakup","batuhan","tunahan","cengizhan","talha","yalk�n","elcan","berfin","erva","nisa","hira","ali","enes","muharrem","bedirhan","emirhan","yusuf","beyza","harun" };
			string soyisim[30] = { "demircioglu","bay�lm�s","ozkanl�","top","tasc�","gurak�n","agca","okumus","demir","celik","ozcelik","ak�n","yorgun","dincer","dinc","eris","kusku","albayrak","erdogan","ince","ozdag","yurdakul","uzun","k�sa","er","al","sert","tazim","eski","pehlivan", };
			ogrenciler[i].adi = isim[rand() % 30];
			ogrenciler[i].soyadi = soyisim[rand() % 30];
			ogrenciler[i].no = rand() % 101;
			ogrenciler[i].tarih.g�n = rand() % 30;
			ogrenciler[i].tarih.ay = rand() % 13;
			ogrenciler[i].tarih.y�l = rand() % 35 + 1970;
		}
			for (int i = 0; i <= 9; i++) {
				ogrenciler[i].kisaSinav1 = rand() % 41;
				ogrenciler[i].kisaSinav2 = rand() % 41;
				ogrenciler[i].odev1 = rand() % 41;
				ogrenciler[i].odev2 = rand() % 41;
				ogrenciler[i].proje = rand() % 41;
				ogrenciler[i].vize = rand() % 41;
				ogrenciler[i].final = rand() % 41;
			}
			for (int i = 10; i <= 59; i++) {
				ogrenciler[i].kisaSinav1 = rand() % 31 + 40;
				ogrenciler[i].kisaSinav2 = rand() % 31 + 40;
				ogrenciler[i].odev1 = rand() % 31 + 40;
				ogrenciler[i].odev2 = rand() % 31 + 40;
				ogrenciler[i].proje = rand() % 31 + 40;
				ogrenciler[i].vize = rand() % 31 + 40;
				ogrenciler[i].final = rand() % 31 + 40;
			}
			for (int i = 60; i <= 74; i++) {
				ogrenciler[i].kisaSinav1 = rand() % 11 + 70;
				ogrenciler[i].kisaSinav2 = rand() % 11 + 70;
				ogrenciler[i].odev1 = rand() % 11 + 70;
				ogrenciler[i].odev2 = rand() % 11 + 70;
				ogrenciler[i].proje = rand() % 11 + 70;
				ogrenciler[i].vize = rand() % 11 + 70;
				ogrenciler[i].final = rand() % 11 + 70;
			}
			for (int i = 75; i <= 99; i++) {
				ogrenciler[i].kisaSinav1 = rand() % 21 + 80;
				ogrenciler[i].kisaSinav2 = rand() % 21 + 80;
				ogrenciler[i].odev1 = rand() % 21 + 80;
				ogrenciler[i].odev2 = rand() % 21 + 80;
				ogrenciler[i].proje = rand() % 21 + 80;
				ogrenciler[i].vize = rand() % 21 + 80;
				ogrenciler[i].final = rand() % 21 + 80;
				for (int i = 0; i < 100; i++) {
					ogrenciler[i].y�l��i = (ogrenciler[i].vize * 0.5 + ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.1 + ogrenciler[i].odev2 * 0.1 + ogrenciler[i].proje * 0.16);
					ogrenciler[i].ba�ar�Notu = (ogrenciler[i].final * 0.45 + ogrenciler[i].y�l��i * 0.55);
				}
		}
		cout << "S�n�f listesini yazd�rmak i�in 1'e" << endl << "S�n�f�n en y�ksek notu i�in 2'ye" << endl << "S�n�f�n en d���k notu i�in 3'e" << endl;
		cout << "s�n�f�n ortalamas� i�in 4'e" << endl << "S�n�f�n standart sapmas� i�in 5 e" << endl << "Belirli bir ba�ar� notu a��rl���ndaki ��rencileri bulmak i�in 6'ya" << endl;
		cout << "Ba�ar� notu girdiniz de�erin alt�ndakileri bulmak i�in 7'ye" << endl << "Ba�ar� notu belirli bir de�erin �st�ndekileri bulmak i�in 8'e bas�n�z" << endl;
		int men�; cin >> men�;// men�leri fonksiyonlar arac�l��� ile olabildi�ince a��k ve anla��labilir tuttum
		if (men� == 1) {
			ogrenciYazdir();
		}
		if (men� == 2) {
			enBuyukNot();
		}
		if (men� == 3) {
			enKucukNot();
		}
		if (men� == 4) {
			s�n�fOrtalamas�();
		}
		if (men� == 5) {
			standartsapma();
		}
		if (men� == 6) {
			notaral���();
		}
		if (men� == 7) {
			nottanalt�();
		}
		if (men� == 8) {
			nottan�st�();
		}

	}

	if (se�enekler == 2) { // bu se�enekte ise veriler kullan�dan istenilip fonksiyonlar �zerine aktar�ld�	 

		cout << "ka� adet ��renci bilgisi girmek istersiniz" << endl;
		cin >> ��renciadedi;
		cout << "S�ras�yla ��renci veya ��rencilerin bilgilerini(isim,soyisim,��renci numaras�,do�um tarihi(g�n ay y�l ayr� ayr�)" << endl;
		cout << "k�sa s�nav1, k�sa s�nav 2,�dev1,�dev2,Proje,Vize,Final)giriniz." << endl;
		for (int i = 0; i < ��renciadedi; i++) {
			cin >> ogrenciler[i].adi;
			cin >> ogrenciler[i].soyadi;
			cin >> ogrenciler[i].no;
			cin >> ogrenciler[i].tarih.g�n;
			cin >> ogrenciler[i].tarih.ay;
			cin >> ogrenciler[i].tarih.y�l;
			cin >> ogrenciler[i].kisaSinav1;
			if (do�rude�ergirildimi(ogrenciler[i].kisaSinav1) == 0) {
				cout << "Yanl��";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].kisaSinav2;
			if (do�rude�ergirildimi(ogrenciler[i].kisaSinav2) == 0) {
				cout << "Yanl��";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].odev1;
			if (do�rude�ergirildimi(ogrenciler[i].odev1) == 0) {
				cout << "Yanl��";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].odev2;
			if (do�rude�ergirildimi(ogrenciler[i].odev2) == 0) {
				cout << "Yanl��";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].proje;
			if (do�rude�ergirildimi(ogrenciler[i].proje) == 0) {
				cout << "Yanl��";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].vize;
			if (do�rude�ergirildimi(ogrenciler[i].vize) == 0) {
				cout << "Yanl��";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].final;
			if (do�rude�ergirildimi(ogrenciler[i].final) == 0) {
				cout << "Yanl��";
				i = i - 1;
				continue;
			}
			ogrenciler[i].y�l��i = (ogrenciler[i].vize * 0.5 + ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.1 + ogrenciler[i].odev2 * 0.1 + ogrenciler[i].proje * 0.16);
			ogrenciler[i].ba�ar�Notu = (ogrenciler[i].final * 0.45 + ogrenciler[i].y�l��i * 0.55);
			cout << "..............." << endl;
		}
		cout << "S�n�f listesini yazd�rmak i�in 1'e" << endl << "S�n�f�n en y�ksek notu i�in 2'ye" << endl << "S�n�f�n en d���k notu i�in 3'e" << endl;
		cout << "s�n�f�n ortalamas� i�in 4'e" << endl << "S�n�f�n standart sapmas� i�in 5 e" << endl << "Belirli bir ba�ar� notu a��rl���ndaki ��rencileri bulmak i�in 6'ya" << endl;
		cout << "Ba�ar� notu girdiniz de�erin alt�ndakileri bulmak i�in 7'ye" << endl << "Ba�ar� notu belirli bir de�erin �st�ndekileri bulmak i�in 8'e bas�n�z" << endl;
		int men�; cin >> men�;
		if (men� == 1) {
			ogrenciYazdir();
		}
		if (men� == 2) {
			enBuyukNot();
		}
		if (men� == 3) {
			enKucukNot();
		}
		if (men� == 4) {
			s�n�fOrtalamas�();
		}
		if (men� == 5) {
			standartsapma();
		}
		if (men� == 6) {
			notaral���();
		}
		if (men� == 7) {
			nottanalt�();
		}
		if (men� == 8) {
			nottan�st�();
		}
	}
}
