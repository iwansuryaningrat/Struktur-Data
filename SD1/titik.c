#ifndef titik_C
#define titik_C

/************************************/
/* Program   : maintitik.c */
/* Deskripsi : aplikasi driver modul Titik */
/* NIM/Nama  : 240601191320027/Iwan Suryaningrat*/
/* Tanggal   : 03 September 2020*/
/***********************************/

#include <stdio.h>
#include <math.h>
#include "titik.h"

Titik makeTitik(int x, int y){
	
	Titik T;
	T.absis = x;
	T.ordinat = y;
	
	return T;
}

int getAbsis(Titik T){
    return T.absis;
}

int getOrdinat(Titik T){
    return T.ordinat;
}

void setAbsis(Titik *T, int xx){
    (*T).absis = xx;
}

void setOrdinat(Titik *T, int yy){
    (*T).ordinat = yy;
}

boolean isOrigin(Titik T){
	if((T.absis == 0) && (T.ordinat == 0)){
		return true;
	}
	else{
		return false;
	}
}

void geserXY(Titik *T, int dx, int dy){
	(*T).absis += dx;
	(*T).ordinat += dy;
}

void refleksiSumbuX(Titik *T){
	(*T).ordinat = -(*T).ordinat;
}

void refleksiSumbuY(Titik *T){
	(*T).absis = -(*T).absis;
}

int Kuadran(Titik T){
	if((T.absis > 0) && (T.ordinat > 0)){
		return 1;
	}
	else if((T.absis < 0) && (T.ordinat > 0)){
		return 2;
	}
	else if((T.absis < 0) && (T.ordinat < 0)){
		return 3;
	}
	else if((T.absis > 0) && (T.ordinat < 0)){
		return 4;
	}
}

float Jarak(Titik T1, Titik T2){
	return sqrt(((T2.absis - T1.absis) * (T2.absis - T1.absis)) + ((T2.ordinat - T1.ordinat) * (T2.ordinat - T1.ordinat)));
}

#endif
