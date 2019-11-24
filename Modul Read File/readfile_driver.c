
#include "readfile.h" 
#include <stdio.h>

	int main() {
		State GameState;
		printf("SELAMAT DATANG DI GAME OF THRONES\n");
		printf("Berikut adalah Peta Permainan awal: \n");
		ReadKonfigurasiFile(&GameState);
		return 0; }
