
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int exec;

int main()
{	
	//Program başlangıcında bir kereliğine 
	//komut girdirebilmeyi sağlamak için fork_pid değişkenine sıfırdan büyük değer verildi
	int fork_pid=9;
	int pid_w,statu;
	char path[100];

	//exec değişkeni statik,her seferinde değeri 0 olarak güncelleniyor
	//Döngünün sürekliliği  için exec değişkeninin 0 değerini alması da dahil edildi
	//Girilen komut işlenmez ise exec, -1 değerini alıyor
	while(!(exec>0))
	{
		
		//Sadece ebevyen proses tarafından çalıştırılsın.
		if(fork_pid > 0)
		{	
			printf("Komut giriniz> ");
			scanf("%s",path);
		}
		
		fork_pid=fork();
		//fork() yavru proses için 0 değerini döndürürken
		//ebeveyn proses için yavru proses PID değeri döndürür.
	
		
		if(fork_pid < 0) 
		{
			printf("Fork sırasında hata oluştu \n");
		}	
		else if(fork_pid == 0) 
		{
			//yavru proses tarafından işletilecek komutlar			
			exec=execlp(path,path,NULL);
		
			if(exec==-1)
			{	
				printf("Komut ya da söz dizimi hatalı !\n");
			}	
		
			exit(0);
		}	
		else
		{
			//ebeyevn proses tarafıdan işletilecek komutlar
			pid_w=waitpid(fork_pid,&statu,0);
			//ebeveyn proses içinde forkPid değeri, yavru proses PID olarak döndürülür.  

		}
	}
	
	
}