
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<locale>
using namespace std;
struct Ogrenci {   // öðrencilerin bilgilerinin olduðu struct.
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
	float yýlÝçi;
	float baþarýNotu;

	struct tarihler {  // tarih structýn parçasý ve ayný zamanda ayrý structtýr.
		int gün;
		int ay;
		int yýl;
	};
	tarihler tarih;
};
Ogrenci ogrenciler[100];
string NotlarýharfaDonusturme(float notu) {		// girilen notlarý harf deðerine dönüþtüren fonksiyon. ( Harf deðerleri internetten baz alýnarak deðer verilmiþtir.
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
}  int öðrenciadedi = 100;
void standartsapma() {
	float aritmetikO = 0, varyans = 0, varyansT = 0;
	for (int i = 0; i < öðrenciadedi; i++) {
		aritmetikO = aritmetikO + (ogrenciler[i].baþarýNotu / öðrenciadedi);
	}
	for (int i = 0; i < öðrenciadedi; i++) {
		varyans = pow(ogrenciler[i].baþarýNotu - aritmetikO, 2);
		varyansT += varyans;
	}
	varyansT /= (öðrenciadedi - 1);
	varyansT = sqrt(varyansT);
	cout << "Standart Sapmasý: " << varyansT << endl;
}
bool doðrudeðergirildimi(int notu) {	// girilen not deðerlerinin 0 ile 100 arasýnda olup ulmadýðýný kontrol eden fonksiyon			
	if (notu >= 0 && notu <= 100) return 1;
	else return 0;
}
void enBuyukNot() {   // girilen notlar arasýnda en büyük notu bulan fonksiyon
	int enBuyukNot = ogrenciler[0].baþarýNotu, a = 0;
	for (int i = 0; i < öðrenciadedi; i++) {
		if (ogrenciler[a].baþarýNotu <= ogrenciler[i].baþarýNotu)
		{
			a = i;	enBuyukNot = ogrenciler[i].baþarýNotu;
		}
	}
	cout << "En yüksek not: " << enBuyukNot;
}
void enKucukNot() { // girilen notlar arasýnda en küçük notu bulan fonksiyon
	int enKucukNot = ogrenciler[0].baþarýNotu, a = 0;
	for (int i = 0; i < öðrenciadedi; i++) {
		if (ogrenciler[a].baþarýNotu >= ogrenciler[i].baþarýNotu)
		{
			a = i; enKucukNot = ogrenciler[i].baþarýNotu;
		}
	}
	cout << "En düþük not: " << enKucukNot;
}
void ogrenciYazdir() {  // öðrencileri yazdýrmak için kullanýlan fonksiyon
	for (int i = 0; i < öðrenciadedi; i++) {
		if (i % 20 == 0) {
			system("pause");
			system("cls");
		}
		cout << "Adý soyadý : " << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << endl;
		cout << "Numarasý: " << ogrenciler[i].no << endl;
		cout << "doðum tarihi:" << ogrenciler[i].tarih.gün << "." << ogrenciler[i].tarih.ay << "." << ogrenciler[i].tarih.yýl << endl;
		cout << "Kýsa sýnav 1: " << ogrenciler[i].kisaSinav1 << endl;
		cout << "Kýsa sýnav 2: " << ogrenciler[i].kisaSinav2 << endl;
		cout << "Ödev 1: " << ogrenciler[i].odev1 << endl;
		cout << "Ödev 2: " << ogrenciler[i].odev2 << endl;
		cout << "Proje: " << ogrenciler[i].proje << endl;
		cout << "Vize: " << ogrenciler[i].vize << endl;
		cout << "Final: " << ogrenciler[i].final << endl;
		cout << "Yýl içi baþarý puaný: " << ogrenciler[i].yýlÝçi << endl;
		cout << "Baþarý notu: " << ogrenciler[i].baþarýNotu << endl;
		cout << "Harf Notu: " << NotlarýharfaDonusturme(ogrenciler[i].baþarýNotu) << endl;
		cout << "********************************************************************" << endl;
	}
}
void sýnýfOrtalamasý() { //Sýnýf ortalamasýný bulan fonksiyon
	float toplamBasariNot = 0;
	for (int i = 0; i < öðrenciadedi; i++) {
		toplamBasariNot += ogrenciler[i].baþarýNotu;
	}
	toplamBasariNot = toplamBasariNot / öðrenciadedi;
	cout << toplamBasariNot;
}
void notaralýðý() {   // 2 baþarý  notu arasýnda kaç tane not olduðunu bulan fonksiyon
	int belirlisayý1;
	int belirlisayý2;
	cout << "not aralýðýný bulmak istediðiniz 2 sayýyý giriniz" << endl;
	cin >> belirlisayý1 >> belirlisayý2;
	for (int i = 0; i < öðrenciadedi; i++)
		if (ogrenciler[i].baþarýNotu< belirlisayý1 && ogrenciler[i].baþarýNotu >belirlisayý2)
			cout << ogrenciler[i].adi << ogrenciler[i].soyadi << endl;
		else if (ogrenciler[i].baþarýNotu > belirlisayý1 && ogrenciler[i].baþarýNotu < belirlisayý2)
			cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << " " << ogrenciler[i].baþarýNotu << endl;
}
void nottanaltý() { // girilen bir baþarý notundan düþük baþarý notlarýný bulan fonksiyon
	int belirlenensayý;
	cout << "hangi nottan aþaðýda notlarý istiyorsunuz giriniz" << endl;
	cin >> belirlenensayý;
	for (int i = 0; i < öðrenciadedi; i++)
		if (ogrenciler[i].baþarýNotu < belirlenensayý)
			cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << " " << ogrenciler[i].baþarýNotu << endl;
}
void nottanüstü() { // girilen bir baþarý notundan yüksek baþarý notlarýný bulan fonksiyon

	int belirlenensayý2;
	cout << "hangi nottan üstte notlarý istiyorsunuz giriniz" << endl;
	cin >> belirlenensayý2;
	for (int i = 0; i < öðrenciadedi; i++) {
		if (ogrenciler[i].baþarýNotu > belirlenensayý2) {
			cout << ogrenciler[i].adi << " " << ogrenciler[i].soyadi << " " << ogrenciler[i].baþarýNotu << endl;
		}
	}
}
int main() {
	setlocale(LC_ALL, "Turkish");
	int seçenekler;
	cout << "seçenek 1'i seçmek için 1'e seçenek 2'yi seçmek için 2'ye basýnýz." << endl;
	cin >> seçenekler;
	while (seçenekler != 1 && seçenekler != 2) {
		cout << "Yanlýþ bir seçenek seçtiniz lütfen tekrar deneyiniz" << endl;
		cin >> seçenekler;
	}
	if (seçenekler == 1) { // seçenek 1 de deðerleri girdiðim 30 isim ve soyisim arasýndan random belirlediðim 100 kiþiye yine random belirlenen not deðerlerini atadým.
		float yýlÝçi = 0.0;
		float baþarýNotu = 0.0;
		int a = 0, b=0;
		srand(time(NULL));
		for (int i = 0; i < 100; i++) {
			
			string isim[30] = { "ahmet","mehmet ","ismail","zeynep", "irem", "kübra","ilknur","sena","hasan","polat","memati","yakup","batuhan","tunahan","cengizhan","talha","yalkýn","elcan","berfin","erva","nisa","hira","ali","enes","muharrem","bedirhan","emirhan","yusuf","beyza","harun" };
			string soyisim[30] = { "demircioglu","bayýlmýs","ozkanlý","top","tascý","gurakýn","agca","okumus","demir","celik","ozcelik","akýn","yorgun","dincer","dinc","eris","kusku","albayrak","erdogan","ince","ozdag","yurdakul","uzun","kýsa","er","al","sert","tazim","eski","pehlivan", };
			ogrenciler[i].adi = isim[rand() % 30];
			ogrenciler[i].soyadi = soyisim[rand() % 30];
			ogrenciler[i].no = rand() % 101;
			ogrenciler[i].tarih.gün = rand() % 30;
			ogrenciler[i].tarih.ay = rand() % 13;
			ogrenciler[i].tarih.yýl = rand() % 35 + 1970;
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
					ogrenciler[i].yýlÝçi = (ogrenciler[i].vize * 0.5 + ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.1 + ogrenciler[i].odev2 * 0.1 + ogrenciler[i].proje * 0.16);
					ogrenciler[i].baþarýNotu = (ogrenciler[i].final * 0.45 + ogrenciler[i].yýlÝçi * 0.55);
				}
		}
		cout << "Sýnýf listesini yazdýrmak için 1'e" << endl << "Sýnýfýn en yüksek notu için 2'ye" << endl << "Sýnýfýn en düþük notu için 3'e" << endl;
		cout << "sýnýfýn ortalamasý için 4'e" << endl << "Sýnýfýn standart sapmasý için 5 e" << endl << "Belirli bir baþarý notu aðýrlýðýndaki öðrencileri bulmak için 6'ya" << endl;
		cout << "Baþarý notu girdiniz deðerin altýndakileri bulmak için 7'ye" << endl << "Baþarý notu belirli bir deðerin üstündekileri bulmak için 8'e basýnýz" << endl;
		int menü; cin >> menü;// menüleri fonksiyonlar aracýlýðý ile olabildiðince açýk ve anlaþýlabilir tuttum
		if (menü == 1) {
			ogrenciYazdir();
		}
		if (menü == 2) {
			enBuyukNot();
		}
		if (menü == 3) {
			enKucukNot();
		}
		if (menü == 4) {
			sýnýfOrtalamasý();
		}
		if (menü == 5) {
			standartsapma();
		}
		if (menü == 6) {
			notaralýðý();
		}
		if (menü == 7) {
			nottanaltý();
		}
		if (menü == 8) {
			nottanüstü();
		}

	}

	if (seçenekler == 2) { // bu seçenekte ise veriler kullanýdan istenilip fonksiyonlar üzerine aktarýldý	 

		cout << "kaç adet öðrenci bilgisi girmek istersiniz" << endl;
		cin >> öðrenciadedi;
		cout << "Sýrasýyla öðrenci veya öðrencilerin bilgilerini(isim,soyisim,öðrenci numarasý,doðum tarihi(gün ay yýl ayrý ayrý)" << endl;
		cout << "kýsa sýnav1, kýsa sýnav 2,Ödev1,Ödev2,Proje,Vize,Final)giriniz." << endl;
		for (int i = 0; i < öðrenciadedi; i++) {
			cin >> ogrenciler[i].adi;
			cin >> ogrenciler[i].soyadi;
			cin >> ogrenciler[i].no;
			cin >> ogrenciler[i].tarih.gün;
			cin >> ogrenciler[i].tarih.ay;
			cin >> ogrenciler[i].tarih.yýl;
			cin >> ogrenciler[i].kisaSinav1;
			if (doðrudeðergirildimi(ogrenciler[i].kisaSinav1) == 0) {
				cout << "Yanlýþ";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].kisaSinav2;
			if (doðrudeðergirildimi(ogrenciler[i].kisaSinav2) == 0) {
				cout << "Yanlýþ";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].odev1;
			if (doðrudeðergirildimi(ogrenciler[i].odev1) == 0) {
				cout << "Yanlýþ";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].odev2;
			if (doðrudeðergirildimi(ogrenciler[i].odev2) == 0) {
				cout << "Yanlýþ";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].proje;
			if (doðrudeðergirildimi(ogrenciler[i].proje) == 0) {
				cout << "Yanlýþ";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].vize;
			if (doðrudeðergirildimi(ogrenciler[i].vize) == 0) {
				cout << "Yanlýþ";
				i = i - 1;
				continue;
			}
			cin >> ogrenciler[i].final;
			if (doðrudeðergirildimi(ogrenciler[i].final) == 0) {
				cout << "Yanlýþ";
				i = i - 1;
				continue;
			}
			ogrenciler[i].yýlÝçi = (ogrenciler[i].vize * 0.5 + ogrenciler[i].kisaSinav1 * 0.07 + ogrenciler[i].kisaSinav2 * 0.07 + ogrenciler[i].odev1 * 0.1 + ogrenciler[i].odev2 * 0.1 + ogrenciler[i].proje * 0.16);
			ogrenciler[i].baþarýNotu = (ogrenciler[i].final * 0.45 + ogrenciler[i].yýlÝçi * 0.55);
			cout << "..............." << endl;
		}
		cout << "Sýnýf listesini yazdýrmak için 1'e" << endl << "Sýnýfýn en yüksek notu için 2'ye" << endl << "Sýnýfýn en düþük notu için 3'e" << endl;
		cout << "sýnýfýn ortalamasý için 4'e" << endl << "Sýnýfýn standart sapmasý için 5 e" << endl << "Belirli bir baþarý notu aðýrlýðýndaki öðrencileri bulmak için 6'ya" << endl;
		cout << "Baþarý notu girdiniz deðerin altýndakileri bulmak için 7'ye" << endl << "Baþarý notu belirli bir deðerin üstündekileri bulmak için 8'e basýnýz" << endl;
		int menü; cin >> menü;
		if (menü == 1) {
			ogrenciYazdir();
		}
		if (menü == 2) {
			enBuyukNot();
		}
		if (menü == 3) {
			enKucukNot();
		}
		if (menü == 4) {
			sýnýfOrtalamasý();
		}
		if (menü == 5) {
			standartsapma();
		}
		if (menü == 6) {
			notaralýðý();
		}
		if (menü == 7) {
			nottanaltý();
		}
		if (menü == 8) {
			nottanüstü();
		}
	}
}
