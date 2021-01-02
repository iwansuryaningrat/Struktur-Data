/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 240601191320027/Iwan Suryaningrat*/
/* Tanggal   : 03 September 2020*/
/***********************************/

#include <stdio.h>
#include <math.h>
#include "titik.c"

int main() {
	// Kamus Main
	Titik P;
	Titik P1;
	Titik P2;

	// Algoritma
	printf("Halo, ini driver modul Titik \n");

	P = makeTitik(3, 4);
	P1 = makeTitik(0, 0);
	P2 = makeTitik(-3, 4);

	setAbsis(&P, 3);
	setOrdinat(&P, 4);
	printf("\n Titik P = (%d, %d)", P.absis, P.ordinat);

	printf("\n Absis Titik P = %d", getAbsis(P));

	printf("\n Ordinat Titik P = %d", getOrdinat(P));

	printf("\n Apakah Titik P adalah origin? %c", isOrigin(P));
	printf("\n Apakah Titik P1 adalah origin? %c", isOrigin(P1));

	geserXY(&P, 2, 5);
	printf("\n Titik P setelah digeser menjadi (%d, %d)", P.absis, P.ordinat);

	refleksiSumbuX(&P);
	printf("\n Refleksi Titik P terhadap Sumbu X = (%d, %d)", P.absis, P.ordinat);

	refleksiSumbuY(&P);
	printf("\n Refleksi Titik P terhadap Sumbu Y = (%d, %d)", P.absis, P.ordinat);

	printf("\n Titik P berada pada kuadran %d", Kuadran(P));

	printf("\n Jarak Titik P1 dan P2 = %.2f", Jarak(P1, P2));

	return 0;
}
