#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int execReturn;
int main()
{
	int pid,forkPid,childPid;
	char path[256];
	pid_t pid_w;
	int statu;
	do
	{
		execReturn=0;
		printf("Komut giriniz> ");
		scanf("%s",path);
		
		pid=getpid();
		printf("\nEbeveyn proses id: %d\n\n",pid );
		printf("\nProses çatallanıyor....  \n");
		forkPid=fork();
		printf("\nforkPid : %d\n",forkPid);
		


		if(forkPid == 0) 
		{
			//yavru proses tarafından işletilecek komutlar			
			printf("\nYavru proses alanı \n");
			childPid=getpid();
			printf("Yavru proses id: %d\n",childPid );
	
			printf("Şimdi komut işletilecek....\n");
			execReturn=execlp(path,path,NULL);
			if(execReturn==-1)
				printf("İşletilemedi.\n");
			exit(3);
				
			
			//while(1);
		}	
		else if(forkPid > 0)
		{
			//ebeyevn proses tarafıdan işletilecek komutlar 
			printf("\nEbeveyn proses alanı \n");

			printf("Ebeveyn proses id: %d\n",getpid());
			pid_w=waitpid(forkPid,&statu,WIFEXITED(statu));
			printf("Sonlanan proses id :%d\n",pid_w );
			if(WIFSTOPPED(statu))
				printf("Stopped by signal:=%d\n",WSTOPSIG(statu) );
			//while(1);

		}
		else 
		{
			printf("Fork sırasında hata oluştu \n");
		}	
		
		printf("Exec dönüş değeri: %d\n",execReturn );
		
		if(execReturn == -1)
			printf("Komut ya da söz dizimi hatalı !\n");
	}
	while(execReturn==-1||execReturn==0);
		



	

}