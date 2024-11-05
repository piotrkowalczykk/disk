#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROZMIAR_TABLICY 10
#define ROZMIAR_TABLICY2 1000000
void main(void)
{

//K int tablica_int[ROZMIAR_TABLICY] = {0};

  // 1. inicjowanie tablicy w momencie definowania:


  // a. wszystkie wartości

//K	int tablica_int[ROZMIAR_TABLICY] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // b. początkowe wartości

//K	int tablica_int[ROZMIAR_TABLICY] = {1, 2, 3, 4, 5};

  // 2. nadanie wartości w pętli

//K	int tablica_int[ROZMIAR_TABLICY];

  // a. zależnych od wartości zmiennej sterujacej

/*	
	for(int i = 1; i <= ROZMIAR_TABLICY; i++){
		tablica_int[i-1] = i;	
	}
*/

  // b. wczytywanych z klawiatury za pomocą scanf

/*
	for(int i = 1; i <= ROZMIAR_TABLICY; i++){
		printf("Podaj %d element:",i);
		scanf("%d", &tablica_int[i-1]);	
	}
*/

  // 3. zamiana pętli for nadawania wartości na pętlę while

/*
	int i = 1;
	while (i <= ROZMIAR_TABLICY){
		tablica_int[i-1] = i;
		i++;
	}
*/

/*
	int i = 1;
	while (i <= ROZMIAR_TABLICY){
		printf("Podaj %d element:",i);
		scanf("%d", &tablica_int[i-1]);
		i++;
	}
*/


  // 4. zamiana poniższej pętli for na pętlę do
  // (jak zwykle najlepiej wykomentować starą pętlę i wpisać poniżej nową pętlę)

/*
  	for(int i=0; i<ROZMIAR_TABLICY; i++){
    		printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);
  	}
*/

/*	
	int i = 0;
	do{
		printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);
		i++;
	} while (i < ROZMIAR_TABLICY);
*/


  // 5. wyszukiwanie wartości maksymalnej w tablicy (pętla for)

/*
	int tablica_int[ROZMIAR_TABLICY] = {1, 33, 3, 24, 2, 87, 4, 83, 92, 10};
	int max = tablica_int[0];

	for(int i = 1; i < ROZMIAR_TABLICY; i++){
		if(tablica_int[i] > max)
			max = tablica_int[i];
	}
	printf("Maksymalna wartosc: %d \n", max);
*/

  // 6. obliczanie sumy elementów tablicy (pętla while)

/*
	int tablica_int[ROZMIAR_TABLICY] = {1, 33, 3, 24, 2, 87, 4, 83, 92, 10};
	int suma = 0;
	int i = 0;
	while(i < ROZMIAR_TABLICY){
		suma += tablica_int[i];
		i++;
	}
	printf("Suma elementow tablicy: %d \n", suma);
*/

  //-------------------------------- 3.0 ------------------------------------

  // 7. tablica z wartościami losowymi i wyszukiwanie zadanych wartości

  // a. nowa definicja tablicy (np. tablicy znaków)

	char tablica_char[ROZMIAR_TABLICY];

  // b. nadawanie wartości losowych wyrazom tablicy
  //    (np. liczby z zakresu 33-126, czyli odpowiadające znakom ASCII)
  //    -> odpowiednie wydruki

/*
	srand(time(NULL));
	int a = 33, b = 126;
	int randomowaLiczba = a + rand() % (b - a + 1);
	
	for(int i = 0; i < ROZMIAR_TABLICY; i++){
		tablica_char[i] = randomowaLiczba;
		randomowaLiczba = a + rand() % (b - a + 1);
	}
	
	for(int i=0; i<ROZMIAR_TABLICY; i++){
    		printf("Iteracja %d: tablica_char[%d] = %c \n", i, i, tablica_char[i]);
  	}
*/
	

  // c. sprawdzenie losowości - obliczenie wartości średniej w tablicy
  //    (w odpowiedniej pętli) - porównanie z teoretyczną średnią
  //    -> odpowiednie wydruki

/*
	int tablica_int[ROZMIAR_TABLICY];	
	srand(time(NULL));

	int a = 33, b = 126;
	float suma = 0; // long long dla tablica2
	
	for(int i = 0; i < ROZMIAR_TABLICY; i++){
		int randomowaLiczba = a + rand() % (b - a + 1);
		tablica_int[i] = randomowaLiczba;
		suma += tablica_int[i];	
	}

	printf("Srednia rzeczywista: %.15f \nSrednia teoretyczna %.15f \n", 
	(double)(suma/ROZMIAR_TABLICY), (double)((a+b)/2));


  // d. wyszukiwanie zadanej wartości
  //    -> odpowiednie wydruki w momencie znalezienia wartości
  //    np. "Znaleziono wartość %.. w %d elemencie tablicy\n", ...


  //  d1. wyszukanie tylko jednej (pierwszej) wartości - pętla while
  //      (lub pętla for i break)

/*
	int tablica_int[ROZMIAR_TABLICY] = {1, 33, 3, 24, 2, 87, 4, 83, 92, 10};
	int szukana;
	int czyZnaleziono = 0;

	printf("Podaj szukana wartosc:");
	scanf("%d", &szukana);

	for(int i = 0; i < ROZMIAR_TABLICY; i++){
		if (tablica_int[i] == (int)szukana){
			printf("Znaleziono wartość %d w %d elemencie tablicy\n", szukana, i+1);
			czyZnaleziono = 1;
			break;
		}
	}
	if(czyZnaleziono == 0)
		printf("Wartosc %d nie wystepuje jako element tablicy \n", szukana);
*/

  //  d2. wyszukanie (i wypisanie) wszytskich wartości - pętla for
  //      (lub pętla while)


	int tablica_int[ROZMIAR_TABLICY] = {1, 33, 2, 24, 2, 87, 4, 83, 2, 10};
	int szukana;
	int czyZnaleziono = 0;

	printf("Podaj szukana wartosc:");
	scanf("%d", &szukana);

	for(int i = 0; i < ROZMIAR_TABLICY; i++){
		if (tablica_int[i] == (int)szukana){
			printf("Znaleziono wartość %d w %d elemencie tablicy\n", szukana, i+1);
			czyZnaleziono = 1;
		}
	}
	if(czyZnaleziono == 0)
		printf("Wartosc %d nie wystepuje jako element tablicy \n", szukana);

  //-------------------------------- 4.0 ------------------------------------

  
}
