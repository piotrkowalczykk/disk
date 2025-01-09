#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// 9.a znalezienie za pomocą: man 3 bsearch lub man 3 qsort typu funkcji porównującej
//     dwa elementy tablicy 
// 9.b deklaracja (za pomocą właściwego prototypu) funkcji porównującej
// 9.c definicja funkcji - najlepiej na końcu pliku
// 9.d wywołanie funkcji sortowania qsort w funkcji main

#define ROZMIAR_TABLICY 10 // można potem zwiększyć do np. 1000 po wykomentowaniu wydruków

// funkcja wyszukiwania zadanej wartości (klucz) w tablicy (tab_int)
int* binsearch_iter(// funkcja zwraca wskaźnik do znalezionego elementu w przypadku sukcesu
		    // lub kod niepowodzenia NULL w przypadku braku elementu w tablicy
	      int klucz,     // wyszukiwana wartość
	      int tab_int[], // tablica liczbowa
	      int n          // długość tablicy
	       );

// funkcja wyszukiwania zadanej wartości (klucz) w podtablicy tablicy (tab_int)
// od indeksu początkowego (pocz) do indeksu końcowego (kon)
int* binsearch_rekur(//funkcja zwraca wskaźnik do znalezionego elementu w przypadku sukcesu
		     //lub kod niepowodzenia NULL w przypadku braku elementu w tablicy
	      int klucz,     // wyszukiwana wartość
	      int tab_int[], // tablica liczbowa
	      int pocz,      // indeks poczatkowego elementu podtablicy
	      int kon        // indeks końcowego elementu podtablicy
	       );

//9 Funkcja compare
int compare(const void* a, const void* b);

void zapis_do_pliku(const char* nazwa_pliku, int tab_int[], int n);
void odczyt_z_pliku(const char* nazwa_pliku, int tab_int[], int n);

int main(int argc, char* argv[])
{
  int i;
  int* tablica_int = malloc(ROZMIAR_TABLICY*sizeof(int));
  srand(time(NULL)); // inicjowanie generatora liczb losowych aktualnym czasem

  for(i=0; i<ROZMIAR_TABLICY; i++){
    tablica_int[i] = rand()%1000; // losowa liczba z zakresu 0-999
    printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);
  }

  zapis_do_pliku(argv[1], tablica_int, ROZMIAR_TABLICY);

  int* odczytana_tablica = malloc(ROZMIAR_TABLICY * sizeof(int));
  odczyt_z_pliku(argv[1], odczytana_tablica, ROZMIAR_TABLICY);

  qsort(odczytana_tablica, ROZMIAR_TABLICY, sizeof(int), compare);

	
  printf("\nPosortowana tablica:\n");
  for(i=0; i<ROZMIAR_TABLICY; i++){
    printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, odczytana_tablica[i]);
  }

  // 11 i 12.
  //for(;;){
    //int k;
    //printf("Podaj liczbę całkowitą 0-999\n"); scanf("%d", &k);

    // wywołanie wyszukiwania funkcją binsearch_iter (później binsearch_rekur)
    // int* wsk_el = binsearch_iter(k, tablica_int, ROZMIAR_TABLICY);
    
    //if(wsk_el==NULL) printf("Nie znaleziono...\n");
    //else{
    //  int indeks = wsk_el - tablica_int;
    //  printf("Znaleziono na pozycji %d (%d == %d == %d)\n",
    //	     wsk_el - tablica_int, k, *wsk_el, tablica_int[indeks]);
    //}

  
  // wywołanie wyszukiwania zgodnie z prototypem bsearch */

  // porównanie wartości zwróconych przez bsearch i binsearch_iter (binsearch_rekur)

  // odpowiednie wydruki
  
  // } 

}


// funkcja wyszukiwania wartości (wyszukiwana_liczba) w tablicy (tab_int)
int* binsearch_iter(// funkcja zwraca wskaźnik do znalezionego elementu w przypadku sukcesu
		    // lub kod niepowodzenia NULL w przypadku braku elementu w tablicy
		   int wyszukiwana_liczba,   // wyszukiwana wartość
		   int tab_int[], // tablica liczbowa
		   int n    // długość tablicy
		    )
{

  int low = 0; // dolny (lewy) indeks aktualnie przeszukiwanej pod-tablicy
  int high = n-1; // górny (prawy) indeks aktualnie przeszukiwanej pod-tablicy

  // dopóki jest jeszcze coś do przeszukania
  while (low <= high) {
    // znajdź środek przeszukiwanej tablicy
    int mid = (low+high) / 2;
    // jeśli element może być w lewej części
    if (wyszukiwana_liczba < tab_int[mid]){
      // zmień górny indeks na dotychczasowy środek 
      high = mid - 1;
    // jeśli element może być w prawej części
    } else if (wyszukiwana_liczba > tab_int[mid]) {
      // zmień dolny indeks na dotychczasowy środek 
      low = mid + 1;
    } else {
      // wartość znaleziona
      //return mid;
      return &tab_int[mid];
    }
  }
  // jeśli low > high - koniec przeszukiwania
  return NULL; // wartość nie znaleziona
}


int compare(const void* a, const void* b){
	int int_a = *((int*)a);
	int int_b = *((int*)b);

	if(int_a < int_b) return -1;
	else if (int_a > int_b) return 1;
	else return 0;
}

void zapis_do_pliku(const char* nazwa_pliku, int tab_int[], int n)
{

	FILE* file = fopen(nazwa_pliku, "w");
	if(file == NULL){
		fprintf(stderr, "Nie mozna otworzyc pliku do zapisu: %s", nazwa_pliku);
	}
	
	for(int i = 0; i < n; i++){
		fprintf(file, "%d \n", tab_int[i]);	
	}
	fclose(file);
}

void odczyt_z_pliku(const char* nazwa_pliku, int tab_int[], int n)
{
	FILE* file = fopen(nazwa_pliku, "r");
	if(file == NULL){
		fprintf(stderr, "Nie mozna otworzyc pliku do odczytu: %s", nazwa_pliku);
	
	}
	for(int i = 0; i < n; i++){
		if(fscanf(file, "%d", &tab_int[i]) != 1){
			fprintf(stderr, "Blad odczytu z pliku: %s \n", nazwa_pliku);	
		}	
	}
	fclose(file);
}














