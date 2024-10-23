#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES
#include <complex.h>

// sposób na łatwą zmianę typu dla wszystkich zmiennych w programie
#define SCALAR double
//#define SCALAR float

#define SMALL_NUMBER 1.e-20 // czy wystarczy jedna wartość dla float i dla double?
#define TOLERANCJA 1.e-6 //1.e-12 

// Testowanie: konstrukcji sterujących (a także nazw zmiennych,
// zakresów widoczności i czasu życia)
int main(void)
{
  // rozwiązanie równania kwadratowego ax^2 + bx + c = 0

  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

  // typ a, b, c ustalany poprzez symbol SCALAR
  SCALAR a, b, c;
  // rozważania o kontrakcie... (czy uwzględnia skończoną precyzję?)
  // input - uodpornianie na błędy wczytywania danych 
  printf("\nPodaj parametr a: "); scanf("%lf",&a); // adres! (miejsce na wpisanie wartości)
  printf("Podaj parametr b: "); scanf("%lf", &b); // uwaga: inny format dla float!
  printf("Podaj parametr c: "); scanf("%lf", &c);

  // if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie

    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
    exit(-1);

  }
  else{

    if(fabs(a) < SMALL_NUMBER) { // ROWNANIE LINIOWE
	SCALAR x = -c / b;
	printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", x);
	if(fabs(a*x*x + b*x + c) > TOLERANCJA){
	printf("Przekroczona TOLERANCJA\n");
	}
    }
    else{

      SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c; // problem jeśli delta bliskie b*b (w skończonej precyzji)
                           // wtedy odejmowanie b i sqrt(delta) traci cyfry znaczące

      if(delta<0){ //ZESPOLONE
	SCALAR re = -b / (2 * a);
    	SCALAR im = sqrt(-delta) / (2 * a);
    	printf("Dwa pierwiastki zespolone: x1 = %.12lf+ %.12lfi, x2 = %.12lf - %.12lfi\n", 
            re, im, re, im);
	
	if(fabs(a*(re + im*I)*(re + im*I) + b*(re + im*I) + c) > TOLERANCJA){
	    printf("Przekroczona TOLERANCJA dla x1 NIEPOPRAWNY WYNIK\n");
	}
	if(fabs(a*(re - im*I)*(re - im*I) + b*(re - im*I) + c) > TOLERANCJA){
	    printf("Przekroczona TOLERANCJA dla x2 NIEPOPRAWNY WYNIK\n");
	}

      } else if (fabs(delta) < SMALL_NUMBER){ //JEDNO ROZWIAZANIE

	SCALAR x = -b / (2 * a);
	printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", -b/(2*a) );
	if(fabs(a*x*x + b*x + c) > TOLERANCJA){
	printf("Przekroczona TOLERANCJA dla x0 NIEPOPRAWNY WYNIK\n");
	}

      } else { // DWA ROZWIAZANIA

	SCALAR temp = sqrt(delta);
	SCALAR x1 = (-b - temp) / (2*a);
	SCALAR x2 = (-b + temp) / (2*a);

	printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",
	       x1, x2);

	if(fabs(a*x1*x1 + b*x1 + c) > TOLERANCJA){
	printf("Przekroczona TOLERANCJA dla x1 NIEPOPRAWNY WYNIK\n");
	}
	if(fabs(a*x2*x2 + b*x2 + c) > TOLERANCJA){
	printf("Przekroczona TOLERANCJA dla x2 NIEPOPRAWNY WYNIK\n");
	}

      }  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu !
  }

	// ZESPOLONE: 20,20,20
	// DELTA = 0: 1 -4 4
	// DELTA > 0: 1 -5 6

  return(0);
}

