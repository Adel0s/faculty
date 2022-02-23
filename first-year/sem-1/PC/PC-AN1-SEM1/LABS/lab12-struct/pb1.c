/*
Să se scrie un program ce definește un tip de date utilizator ce modelează un număr complex și o serie de funcții ce realizeaza operațiile de bază cu numere complexe. Programul se va testa prin numere introduse de la tastatură
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<math.h>

typedef struct{
  int re;
  int im;
}COMPLEX;

COMPLEX adunare(COMPLEX x, COMPLEX y)
{
  COMPLEX rez;
  int suma_Re = 0;
  int suma_Im = 0;

  suma_Re = x.re + y.re;
  suma_Im = x.im + y.im;

  rez.re = suma_Re;
  rez.im = suma_Im;

  return rez;
}

COMPLEX scadere(COMPLEX x, COMPLEX y)
{
  COMPLEX rez;
  int dif_Re = 0;
  int dif_Im = 0;

  dif_Re = x.re - y.re;
  dif_Im = x.im - y.im;

  rez.re = dif_Re;
  rez.im = dif_Im;

  return rez;
}

COMPLEX inmultire(COMPLEX x, COMPLEX y)
{
  // z1 = a1+b1i   z2=a2+b2i
  COMPLEX rez;
  int produs_Re = 0;
  int produs_Im = 0;

  produs_Re = (x.re * y.re)-(x.im * y.im);
  produs_Im = (x.re * y.im) - (x.im*y.re);

  rez.re = produs_Re;
  rez.im = produs_Im;

  return rez;
}

int modul(COMPLEX z)
{
  return sqrt((z.re*z.re) + (z.im*z.im));
}

void afisare(COMPLEX x)
{
  printf("%d + %di\n", x.re, x.im);
}


int main(void)
{
  COMPLEX x,y,suma,diferenta,produs;
  int m;
  x.re=1;
  x.im=2;
  afisare(x);

  y.re=213;
  y.im=23;
  afisare(y);

  suma = adunare(x,y);
  afisare(suma);

  diferenta = scadere(x,y);
  afisare(diferenta);

  produs = inmultire(x,y);
  afisare(produs);

  m = modul(x);
  printf("|z| = %d\n",m);
  return 0;
}
