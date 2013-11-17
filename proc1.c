#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int execReturn;

int main()
{	
	
	int forkPid=9;  
	//Program başlangıcında bir kereliğine 
	//komut girdirebilmeyi sağlamak için forkPid değişkenine sıfırdan büyük değer verildi
	char path[256];
	pid_t pid_w;
	int statu;

	do
	{
		
		//Sadece ebevyen proses tarafından çalıştırılsın.
		if(forkPid > 0)
		{	
			printf("Komut giriniz> ");
			scanf("%s",path);
		}
		
		forkPid=fork();
		//fork() yavru proses için 0 değerini döndürürken
		//ebeveyn proses için yavru proses PID değeri döndürür.
	
		
		if(forkPid == 0) 
		{
			//yavru proses tarafından işletilecek komutlar			
			execReturn=execlp(path,path,NULL);
		
			if(execReturn==-1)
			{	
				printf("Komut ya da söz dizimi hatalı !\n");
			}	
		
			exit(0);
			
		}	
		else if(forkPid > 0)
		{
			//ebeyevn proses tarafıdan işletilecek komutlar
			pid_w=waitpid(forkPid,&statu,0);
			//ebeveyn proses içinde forkPid değeri, yavru proses PID olarak döndürülür.  

		}
		else 
		{
			printf("Fork sırasında hata oluştu \n");
		}	
		 	
		
	}
	while(execReturn==-1||execReturn==0);
	//execReturn değişkeni statik tanımlandığı için değeri 0 olarak güncelleniyor
	//Döngünün devamlılığı için execReturn değişkeninin 0 değerini alması da dahil edildi

}