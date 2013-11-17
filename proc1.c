#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int execReturn;
int main()
{
	int forkPid=9;  
	//Program başlangıcında bir kereliğine komut girdirebilmeyi sağlamak için
	char path[256];
	pid_t pid_w;
	int statu;
	do
	{
		execReturn=0;

		if(forkPid > 0)
		{	
			printf("Komut giriniz> ");
			scanf("%s",path);
		}
		
		//printf("\nEbeveyn proses id: %d\n\n",getpid() );
		printf("\nProses çatallanıyor....  \n");
		forkPid=fork();
		//yavru proses için 0 değeri döndürülürken
		//ebeveyn proses için yavru proses PID değeri döndürülür
	
		
		if(forkPid == 0) 
		{
			//yavru proses tarafından işletilecek komutlar			
			printf("\nYavru proses alanı \n");
			//childPid=getpid();
			printf("Yavru proses id: %d\n",getpid() );
	
			printf("Şimdi komut işletilecek....\n");
			//pause(); 

			execReturn=execlp(path,path,NULL);

			if(execReturn==-1)
			{	
				printf("İşletilemedi.\n");
				printf("Komut ya da söz dizimi hatalı !\n");
			}	
		
			exit(0);
			
		}	
		else if(forkPid > 0)
		{
			//ebeyevn proses tarafıdan işletilecek komutlar 
			printf("\nEbeveyn proses alanı \n");
			printf("Ebeveyn proses id: %d\n",getpid());
			pid_w=waitpid(forkPid,&statu,0);
			//forkPid = yavru proses  PID

			if(pid_w > 0)
				printf("Sonlanan proses id :%d\n",pid_w );
			
			

		}
		else 
		{
			printf("Fork sırasında hata oluştu \n");
		}	
		 	
			
	}
	while(execReturn==-1||execReturn==0);
		

}