using namespace std;

#include <stdio.h>
#include <stdint.h>
#include <sys/timeb.h>

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
	uint32_t quantidade = 10000000000;
	int i;
	float soma = 0;
    
	printf("\n\n************************************************************************\n");
	printf("***  *****  **        **  *********        ***         ***         *****\n");
	printf("***   ***   **  ********  ********  ******  **  *****  ***  ************\n");
	printf("***  * * *  **        **  ********  ******  **         ***         *****\n");
	printf("***  ** **  **  ********  ********  ******  **  *****************  *****\n");
	printf("***  *****  **  ********        ***        ***  **********         *****\n");
	printf("************************************************************************\n\n");
	
	printf("Numero de instrucoes: %d\n\n", quantidade);
	
	int start = getMilliCount();

    for(i = 1; i < quantidade; i++){
		soma += 0.9;
	}

	int elapsedMillis = getMilliSpan(start);

	printf("\n\nTempo \t%u milisegundos\t %f segundos", elapsedMillis, ((float) elapsedMillis / 1e3));
	
	printf("\n\n%.3f MFLOPS", ((float) (quantidade / ((float) elapsedMillis / 1e3))) / 1e6);

	printf("\n\n\n");
	
	printf("Aperte ENTER para fechar.");
	getchar();
	return 1;
}
