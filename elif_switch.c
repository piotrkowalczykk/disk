#include <stdio.h>

int main(void)
{
  
  char c;
  for(;;){  // wykonywanie nieskoĹczenie wiele razy
    printf("\nWprowadz cyfre od 0 do 5: \n");  
    scanf(" %c",&c); // wielokrotne wczytywanie pojedynczego znaku (jak pozbyÄ siÄ \n ?)
    if (c == '0'){
	printf("Wprowadzono: 0\n");
    } else if (c == '1') {
	printf("Wprowadzono: 1\n");
    } else if (c == '2') {
	printf("Wprowadzono: 2\n");
    } else if (c == '3') {
	printf("Wprowadzono: 3\n");
    } else if (c == '4') {
	printf("Wprowadzono: 4\n");
    } else if (c == '5') {
	printf("Wprowadzono: 5\n");
    } else if (c == 'q') { //wyjscie z programu
	printf("QUIT\n");
	break; //przerwanie petli for
    }  else {
	printf("Wprowadzono: znak spoza zakresu 0-5\n");
    }
}
return 0;
}
