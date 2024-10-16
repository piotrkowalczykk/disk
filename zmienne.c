// //** zmienne.c - prosty program ilustrujący wykorzystanie i drukowanie zmiennych oraz
// //**             ewentualne problemy z precyzją przechowywania

// //** słowo USES informuje, że w pliku będą używane funkcje opisane w plikach nagłówkowych
#include <stdio.h> // USES - deklaracje funkcji wejścia/wyjścia
#include <math.h> // USES - deklaracje funkcji matematycznych

// //** definicja symbolu - w kodzie używany jest symbol, preprocesor zamienia każde wystąpienie
// //** symbolu w kodzie na podany łańcuch znaków
#define TOLERANCE 1e-12 // tolerancja - wartość względnej różnicy liczb (l1-l2)/l1
                        // //** poniżej której dwie liczby zmiennoprzecinkowe są uznawane za równe
// //** UWAGA: tolerancja powinna być różna dla float i double (tutaj wartość typowa dla double)

// //** bez użycia #define i nazwanych wartości (np. TOLERANCE - można jeszcze zwiekszyć czytelność nazwy)
// //** w kodzie pojawiają się tzw. "magic numbers" - liczby w kodzie, o których po pewnym czasie
// //** nikt nie wie co oznaczają, dlaczego tyle wynoszą, skąd się wzięły


// //** zwrot kodu błędu lub sukcesu (zwyczajowo kod sukcesu -> 0)
int main(void)
{

  /* 1. STANDARDOWE DEKLARACJE-DEFINICJE I WYPISYWANIE WARTOŚCI ZMIENNYCH */

  // //** definicje
     int n; // nazwy zmiennych - znaczące, niekoniecznie krótkie, z dużymi i małymi literami
          // nazwy krótkie, nieznaczące dla zmiennych pomocniczych stosowanych lokalnie
     char znak_do_testowania;

  // //** podstawianie wartości - inicjowanie
    n = 7; // instrukcja przypisania - stałe liczbowe i podstawowe operacje
    znak_do_testowania = 'a'; // stała znakowa

    printf("\nwartość zmiennej n = %d, wartość zmiennej znak_do_testowania = %c\n",
  	 n, znak_do_testowania );

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zdefiniowanie po jednej zmiennej każdego z omawianych na wykładzie typów - w tym typów
  // //**   z określeniami: short, long, unsigned
  // //** - podstawienie do każdej zmiennej dowolnie wybranej, poprawnej wartości
  // //** - zdefiniowanie połączone z nadaniem wartości (zainicjowniem) ponownie dla jednej zmiennej
  // //**   każdego z omawianych na wykładzie typów
  // //** - wypisanie wartości zdefiniowanych zmiennych na ekranie w oknie terminala: dobranie odpowiedniego
  // //**   symbolu formatowania dla każdego typu - sprawdzenie poprawności działania (czyli wydrukowania
  // //**   nadanej wartości)
  // //** - sprawdzenie efektu błędnego użycia symbolu formatowania: kiedy wydruk przestaje być poprawny
  // //**   (np. zmienna typu unsigned drukowana jako int, zmienna float drukowana jako int itd., itp,)
  
	// Zadanie

	_Bool zBool;
	zBool = 0;
	_Bool zBool2 = 0;

	char zChar;
	zChar = 'c';
	char zChar2 = 'c';

	int zInt;
	zInt = 1;
	int zInt2 = 1;

	float zFloat;
	zFloat = 3.0f;
	float zFloat2 = 3.0f;

	double zDouble;
	zDouble = 2.0;
	double zDouble2 = 2.0;

	short int zShortInt;
	zShortInt = 4;
	short int zShortInt2 = 4;

	long double zLongDouble;
	zLongDouble = 5.0L;
	long double zLongDouble2 = 5.0L;

	unsigned int zUnsignedInt;
	zUnsignedInt = 6;
	unsigned int zUnsignedInt2 = 6;

	signed int zSignedInt;
	zSignedInt = -7;
	signed int zSignedInt2 = -7;

	printf("\n Zmienna zBool = %d \n Zmienna zChar = %c \n Zmienna zInt = %d \n Zmienna zFloat = %f \n Zmienna zDouble = %f \n Zmienna zShortInt = %hd \n Zmienna zLongDouble = %Lf \n Zmienna zUnsignedInt = %u \n Zmienna zSignedInt = %d \n", zBool, zChar, zInt, zFloat, zDouble, zShortInt, zLongDouble, zUnsignedInt, zSignedInt);

	// printf("Test uzycia blednego symbolu formatowania: \n Zmienna float jako int = %d", zFloat);

  /* 2. PROSTE OPERACJE */

  // //** operatory i ich priorytety
    int m;
    m = 2 * n + 3;
    int o = 2 * (n + 3); // definicja z inicjowaniem
    printf("\nn = %d, (2 * n + 3) = %d != (2 * (n + 3)) = %d\n", n, m, o);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - napisanie kilku (2-3) wyrażeń arytmetycznych, w których wynik zależał będzie od kolejności
  // //**   zapisu i priorytetów wykonywanych operacji - testowanie poprawnego użycia nawiasów

	// Zadanie

	int wyrazenie1 = 3 * 3 + 2;
	int wyrazenie2 = 3 * (3 + 2);
	int wyrazenie3 = 3 + (3 + 2) * (9-1);

	printf("\n Wyrazenie 1: 3*3+2 = %d \n Wyrazenie 2: 3*(3+2) = %d \n Wrazenie 3: 3+(3+2)*(9-1) = %d \n", wyrazenie1, wyrazenie2, wyrazenie3);

  // //** operatory jednoargumentowe i ich priorytety
    int p = n++;  
    n--; // powrót do początkowej wartości n
    int q = ++n;  
    n--; // powrót do początkowej wartości n
    printf("\nn = %d, wynik podstawienia: 'p = n++;' - %d, wynik podstawienia: 'q = ++n;' - %d \n\n", 
  	 n, p, q);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - napisanie kilku (2-3) wyrażeń arytmetycznych z operatorami jednoargumentowymi, w których wynik
  // //** zależał będzie od priorytetów wykonywanych operacji - testowanie poprawnego użycia nawiasów

	// Zadanie

	int liczba1 = 5;
	int liczba2 = (liczba1++) + 2;
	liczba1--;
	int liczba3 = (++liczba1) + 2;
	printf(" Liczba obliczona postinkrementacja = %d \n Liczba obliczona preinkrementacja = %d \n", liczba2, liczba3);

  
  // //** operatory / - dzielenie całkowite i % - modulo
    n = 1574;
    m = n % 7;
    o = n / 7;
    printf("\nn = %d, n/7 = %d, reszta - n%%7 = %d, n = (n/7)*7 + (n%%7) = %d\n",
    	 n, o, m, o*7+m);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - napisanie kilku (2-3) wyrażeń arytmetycznych z funkcją modulo:
  // //**   - sprawdzanie podzielności jednych liczb przez inne
  // //**   - dzielenie z resztą i uzyskiwanie pierwotnej wartości (dla innych liczb niż w przykładzie
  // //**     powyżej)

	// Zadanie

	int dzielenie1 = 8%2;
	int dzielenie2 = 9%2;
	int liczba4 = 1234;
	int liczba5 = liczba4 % 7;
	int liczba6 = liczba4 / 7;

	printf("\n 8 %% 2 == %d reszta rowna 0 wiec 8 jest podzielne przez 2 \n 9 %% 2 == %d reszta rozna od 0 wiec 9 nie jest podzielne przez 2\n", dzielenie1, dzielenie2);
	printf("\n liczba4 = %d, liczba4/7 = %d, reszta - liczba4%%7 = %d, liczba4 = (liczba4/7)*7 + (liczba4%%7) = %d\n", liczba4, liczba6, liczba5, liczba6 * 7 + liczba5);


  /* 3. DEFINICJE STAŁYCH SYMBOLICZNYCH */

  // //**** UWAGA: definicje symboli #define powinny być na początku pliku (po #include) !!!!!!!!!!
           // //** kompilator w pierwszej fazie działania zastąpi wszystkie wystąpienia
           // //** symboli odpowiednimi wyrażeniami z #define
  #define SIEDEM 7 // wystąpienia symbolu SIEDEM są w kodzie zamieniane na 7
    int r = SIEDEM; // w assemblerze r jest zmienną - ma adres, SIEDEM znika zamienione na 7
    printf("\nr = %d, stała SIEDEM = %d\n", r, SIEDEM); 

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - nadanie wartości kilku symbolom - wartości powinny być stałymi różnych typów liczbowych
  // //** - podstawienie do zmiennych wartości za pomocą symboli okreslonych w #define i wydrukowanie
  // //**   wartości zmiennych (UWAGA: po podstawieniu za symbol napisu stanowiącego zapis liczby,
  // //**   funkcjonuje on w kodzie jako liczba określonego typu - jak w przykładzie powyżej - drukując
  // //**   go należy odpowiednio dobrać formatowanie)

	// Zadanie
	#define PI 3.14
	#define E 2.72
	#define MAX_LICZBA 100
	#define MIN_LICZBA 0

	float liczbaPI = PI;
	double liczbaE = E;
	int max = MAX_LICZBA;
	int min = MIN_LICZBA;

	printf("\n Liczba PI = %f \n Liczba E = %f \n max = %d \n min = %d \n", liczbaPI, liczbaE, max, min);

    
  /* 4. ZMIENNE ZMIENNOPRZECINKOWE: FLOAT I DOUBLE */

  // //**** UWAGA na dokładność:
  // //** wygodne wyrażanie w postaci liczby cyfr znaczących:
  // //** x = 123456789.123456789123456
  // //**   - dla liczb pojedynczej precyzji co najmniej 6 cyfr znaczących 
  // //**       pierwsze cyfry 123456 - na pewno sensowne, reszta cyfr może być bez znaczenia (śmieci)
  // //**         (czyli zapisana w zmiennej liczba to ok. 1234560000 +/- 10000),
  // //**   - dla liczb podwójnej precyzji co najmniej 15 cyfr znaczących
  // //**       123456789.123456 - na pewno sensowne 
  // //**         (zapisana liczba to ok. 123456789.123456 +/- 0.0000001)
 
  // //** definicja z inicjowaniem 
    float f = 1.0f/3.0f;  // zapis stałej float z literką f
    float g = 1.0f/3.0; 
    double d = 1.0/3.0; 
    double e = 1.0f/3.0; 

  
    printf("\nliczby zmiennoprzecinkowe:\n");
    printf("float  -  f = 1.0f/3.0f = %f  (dokładnie: %20.15f)\n", f, f);
    printf("float  -  g = 1.0f/3.0  = %f  (dokładnie: %20.15f)\n", g, g);
    printf("double -  d =  1.0/3.0  = %lf  (dokładnie: %20.15lf)\n", d, d);
    printf("double -  e = 1.0f/3.0  = %lf  (dokładnie: %20.15lf)\n", e, e);
    int s = 1/3;
    printf("(liczba całkowita s = 1/3 = %d - dzielenie całkowite)\n", s);
    int t = 1.0/3.0;
    printf("(liczba całkowita t = 1.0/3.0 = %d - obcięcie przy konwersji)\n", t);
    printf("\n");
    printf("float  -  f = 1.0f/3.0f = %e  (dokładnie: %20.15e)\n", f, f);
    printf("double -  d =  1.0/3.0  = %le  (dokładnie: %20.15le)\n", d, d);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zdefiniowanie kilku zmiennych typów float i double oraz nadanie im wartości
  // //**   za pomocą stałych typu float i double
  // //** - wydrukowanie wartości zdefiniowanych i zainicjowanych zmiennych z wystarczającą liczbą cyfr,
  // //**   tak aby zobaczyć jaka jest dokładność (jaki jest błąd wartości zmiennej w stosunku do podstawianej 
  // //**   matematycznej wartości (może to dotyczyć także prostych ułamków dziesiętnych, np. 0.1, 0.2, 0.3)  

	// Zadanie

	float f1 = 1.0f / 6.0f;
    	float f2 = 0.1f;
    	float f3 = 2.5f;
   	double d1 = 1.0 / 6.0;
   	double d2 = 0.1;
   	double d3 = 2.5;
	
    	printf("\n f1 = 1.0f / 6.0f = %f  (dokładnie: %20.15f)\n", f1, f1);
    	printf(" f2 = 0.1f = %f  (dokładnie: %20.15f)\n", f2, f2);
    	printf(" f3 = 2.5f = %f  (dokładnie: %20.15f)\n", f3, f3);
    	printf(" d1 = 1.0 / 6.0 = %lf (dokładnie: %20.15lf)\n", d1, d1);
   	printf(" d2 = 0.1 = %lf (dokładnie: %20.15lf)\n", d2, d2);
    	printf(" d3 = 2.5 = %lf (dokładnie: %20.15lf)\n", d3, d3);
  //-------------------------------------------- 3.0 --------------------------------------------


  /* 5. OPERATORY RELACJI I WARTOŚCI LOGICZNE  */

  // //** wartość logiczna wyrażeń - obliczanie i zapis w zmiennych
    int a =  n<m ;
    _Bool b = n<m || n>m ;
    printf("\nWartość logiczna wyrażenia: %d<%d wynosi %d (int a = n<m = %d)\n", 
  	 n, m, n<m, a);
    printf("\nWartość logiczna wyrażenia: %d<%d lub %d>%d wynosi %d (_Bool b = n<m||n>m = %d)\n", 
  	 n, m, n, m, (n<m)||(n>m), b);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - skonstruowanie kilku złożonych wyrażeń logicznych, które będą np. sprawdzać zasady rachunku zdań:
  // //**   (p lub q) i r  =? (p i r) lub (q i r) - czy jest to równoważne
  // //**   (p i q) lub r  =? (p lub r) i (q lub r) - czy jest to równoważne
  // //** - jaka jest kolejność operacji i wynik w przypadku usuwania kolejnych nawiasów

	// Zadanie
	p = 3>1;
	q = 2<1;
	r = 1;
	printf("\n p = %d q = %d r = %d", p, q, r);
	_Bool bool1 = ((p || q) && r) == ((p && r) || (q && r));
	printf("\n Wartosc wyrazenia: ((p || q) && r) == ((p && r) || (q && r)) wynosi %d \n", bool1);
	_Bool bool2 = ((p && q) || r) == ((p || r) && (q || r));
	printf(" Wartosc wyrazenia: ((p && q) || r) == ((p || r) && (q || r)) wynosi %d \n", bool2);
	// W przypadku usuniecia nawiasow pierwszenstwo wykonywania ma && zarowono po lewej jak i prawej stronie


  /* 6. Operatory oraz niejawne i jawne konwersje typów  */
  
   e = f; // e typu double, f typu float 
   d = 1111 + 1000 * n; // d = (double) ...;
   n = f + 2.5; // n = (int) ...;
   printf("\nNiejawne i jawne konwersje typów:\n");
   printf("n = %d, f = %f, d = %lf, e = %le\n\n", n, f, d, e);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zapisanie kilku wyrażeń z operacjami na zmiennych różnych typów i zapisie do zmiennej
  // //** - sprawdzenie otrzymanego wyniku: jakich konwersji dokonał kompilator?
  // //** - zapisanie kilku wyrażeń z jawną konwersją typów, obserwacja otrzymanych wyników (np.
  // //**   dla kilku wariantów podstawienia do f:  n / 3 , (double) n / 3 ,  n / 3.0 , (double) (n / 3)

	// Zadanie
	double liczbaDouble;
	double liczbaDouble2;
	int liczbaInt = 121;
	float liczbaFloat = 2.5f;
	printf(" liczbaInt = %d liczbaFLoat = %f \n", liczbaInt, liczbaFloat);
	liczbaDouble = liczbaFloat; //niejawna float -> double
 	printf(" Niejawna konwersja: liczbaDouble = liczbaFloat \n");
	printf(" liczbaDouble = %f \n", liczbaDouble);
	liczbaDouble2 = 2 * liczbaInt + 200; //niejawna int -> double
	printf(" Niejawna konwersja: liczbaDouble2 = 2 * liczbaInt + 200\n");
	printf(" liczbaDouble2 = %f \n", liczbaDouble2);
	liczbaInt = (int)liczbaFloat; //jawna float -> int
	printf(" Jawna konwersja: liczbaInt = (int)liczbaFloat; \n");
	printf(" liczbaInt = %d \n", liczbaInt);
	

  
 
    /* 7. DEFINICJE STAŁYCH SYMBOLICZNYCH (CD.) */

  // //** UWAGA: definicje symboli #define powinny być na początku pliku (po #include) !!!!!!!!!!
  // //** najlepszym sposobem na "magic numbers" jest umieszczenie ich na początku pliku
  // //** zakodowanych w postaci "stałych nazwanych" (RAZEM Z ODPOWIEDNIMI KOMENTARZAMI), np.:
   #define JednaTrzeciaFloat (1.0f/3.0f) // 1/3 z dokładnością float (czasem nazwa zastępuje komentarz)
   #define JednaTrzecia (1.0/3.0) // uwaga na odczyt przy podstawieniu (rola nawiasów)
           // //** brak nawiasów może spowodować problemy z kolejnością wykonywania operacji
           // //** 3.0*1.0/3.0 może być różne od 3.0*(1.0/3.0)
           // //** (3*1)/3 jest na pewno różne od 3*(1/3)
           // //** 3*1/3 może być różne od 3*(1/3)


  // //** Precyzja stałych i zmiennych
  // //** (uwaga na mozliwe modyfikacje dokonywane przez kompilator (np. (1.0f/3.0f)*3.0f -> 1.0)
    d = JednaTrzecia * 3.0;
    e = JednaTrzeciaFloat * 3.0;
    printf("\nPrecyzja stałych i niejawne konwersje:\n");
    printf("(1.0/3.0)*3.0: \tJednaTrzecia -> d = %20.15lf; \n\t\tJednaTrzeciaFloat -> e = %20.15lf\n", d, e);

  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zdefiniowanie symbolu zawierającego wyrażenie arytmetyczne bez użycia nawiasu
  // //**   (np. #define JednaTrzecia (1.0/3.0) ) i znalezienie zastosowania prowadzącego do błędu
  // //**   (np. dla symbolu powyżej operacja: (1.0/3.0) / JednaTrzecia ), obserwacja wyniku
  // //** - wyjaśnienie źródła błędu
  // //** - własne przykłady dla powyższej sytuacji

	// Zadanie
	
	#define JednaTrzeciaTest 1.0/3.0
	// Blad wynika z tego, ze kolejnosc dzialan w C jest ustalana na podstawie priorytetu operatorow. Bez uzycia 		nawiasow, wyrazenia moga być interpretowane w bledny sposob;
	double wynik = 3/JednaTrzeciaTest;
	printf("\n Wynik 3/JednaTrzeciaTest = %f jest to nie prawda poniewaz 3 / 1/3 = 9 \n", wynik);

  //-------------------------------------------- 4.0 --------------------------------------------
  
  // //** WŁASNE EKSPERYMENTY
  // //** ze zmiennymi całkowitymi, operatorami i ich priorytetami
  // //** np. sprawdzenie efektu operacji m+n, m++n, m+++n, m++++n, m+++++n, m+++n++++, itd.
  //printf("\nn = %d, m = %d\n", n, m);
  //o = m...n;
  //printf("\tpo operacji o = m...n = %d: n = %d, m = %d\n", o, n, m);


  /* 7. PROBLEMY Z PRECYZJĄ LICZB ZMIENNOPRZECINKOWYCH */

  //  printf("\nProblemy z precyzją zmiennych float i double:\n");

  // //** kłopoty z precyzją:
  //  float fx1 = 1.23e7;
  //  float fx2 = 1.23e-7;

  //  printf("\nfloat: fx1 = %20.15lf, fx2 = %20.15lf, \n", fx1, fx2);
  //  if( (fx1+fx2)-fx1 == fx2 ){
  //    printf("\n(fx1+fx2)-fx1 == fx2 (dla float)\n");
  //  }
  //  else {
  //    printf("\n(fx1+fx2)-fx1 != fx2 (dla float) ( (fx1+fx2)-fx1 = %.15lf )\n",
  //  	   (fx1+fx2)-fx1);
  //  }

  // //** kłopoty z precyzją:
  //  double dx1 = 1.23e7;
  //  double dx2 = 1.23e-7;


  //  printf("\ndouble: dx1 = %20.15lf, dx2 = %20.15lf, \n",
  //  	 dx1, dx2);
  //  if( (dx1+dx2)-dx1 == dx2 ){
  //    printf("\n(dx1+dx2)-dx1 == dx2 (dla double)\n");
  //  }
  //  else {
  //    printf("\n(dx1+dx2)-dx1 != dx2 (nawet dla double!) ( (dx1+dx2)-dx1 = %.15lf )\n",
  //  	   (dx1+dx2)-dx1);
  //  }
 

  // //** obsługa błędów - temat rzeka
  // //** wariant prosty:

  // //** chcemy obliczyć 1 / ( (fx1+fx2)-fx1 ) - powinno być równe 1/fx2

  // //** próba uniknięcia dzielenia przez zero:
  // //** if( fx2 != 0.0 ){ - błędy: 1. (fx1+fx2)-fx1 != fx2, 2. porównanie float

  // //** poprawna próba uniknięcia dzielenia przez zero lub utraty precyzji:
  // //** (należy wcześniej odkomentować definicje stałej nazwanej TOLERANCE na początku pliku)
  //  if( fabs ((fx1+fx2)-fx1) < TOLERANCE){
  //    printf("\nPróba dzielenia przez liczbę bliską zero! Przerwanie programu!\n");    
    //return(-1); 
    // //** lub exit(-1) - exit przerywa wykonanie całego programu, nie tylko aktualnej funkcji    
  //  }

  //  float fx3 = 1.0f / ((fx1+fx2)-fx1); // powinno byc równe 1/fx2...
  //  printf("\n1.0f / ((fx1+fx2)-fx1) = %20.15lf\n", fx3);
  
  //  double dx3 = 1.0 / ((dx1+dx2)-dx1); // powinno byc równe 1/dx2...
  //  printf("\n1.0/((dx1+dx2)-dx1) = %.12lf  != 1.0/dx2 = %.12lf\n", dx3, 1.0/dx2);
  //  printf("Zostały tylko trzy cyfry znaczące na skutek skończonej precyzji...\n");

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu jego działania)
  // //**(opis działania kodu z wyjaśnieniem przyczyn problemów z precyzją powinien znaleźć sie w sprawozdaniu)
  // //** - zadania rozszerzające z tematu laboratorium  
  
  printf("\nProgram dotarł do końca\n");
  return(0);
}

