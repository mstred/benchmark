#include <iostream>
using namespace std;
#include <cstdlib>
#include <sys/timeb.h>
#include "windows.h"


int getMilliCount(){
	timeb tb;
	ftime(&tb);
	int nCount = tb.millitm + (tb.time & 0xfffff) * 1000;
	return nCount;
}

int getMilliSpan(int nTimeStart){
	int nSpan = getMilliCount() - nTimeStart;
	if(nSpan < 0)
		nSpan += 0x100000 * 1000;
	return nSpan;
}

int main(){

	uint32_t quantidade = 1000000000;
	int i = 1;
	int soma = 0;
    
    printf("\n\n");
	printf("****************************************\n**\n");
	printf("** Contador em milissegundos\t\t\tVersão para MIPS\n");
	printf("**\n***************************************\n\n");
	
	printf("Numero de tentativas: %d\n\n",quantidade);
	
	printf("Aperte ENTER para o inicio.");
	getchar();
	int start = getMilliCount();

   // Testando precisão do cálculo do tempo
   /*
    Sleep(2739);
   */

    for(i; i < quantidade; i++){
           soma = soma + 1;
           }

	int milliSecondsElapsed = getMilliSpan(start);

	printf("\n\nTempo = %u milisegundos", milliSecondsElapsed);

	printf("\n\n\n");
	
	printf("Aperte ENTER para fechar.");
	getchar();
	return 1;
}
