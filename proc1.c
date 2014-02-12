
#include "proc1.h"
int exec;

int main()
{	
	//Program başlangıcında bir kereliğine 
	//komut girdirebilmeyi sağlamak için fork_pid değişkenine sıfırdan büyük  değer verildi
	//1 değeri init prosesine ait olduğu için bu PID'nin bir proses verilmesi mümkün değildir.
	int fork_pid=1;
	int pid_w,statu;
	char executable_path[60];

	//exec değişkeni statik,her seferinde değeri 0 olarak güncelleniyor
	//Döngünün sürekliliği  için exec değişkeninin 0 değerini alması da dahil edildi
	//Girilen komut işlenmez ise exec, -1 değerini alıyor
	while(1)
	{
		
		//Sadece ebevyen proses tarafından çalıştırılsın.
		if(fork_pid > 0)
		{	
			printf("Komut giriniz> ");
			scanf("%s",executable_path);
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
			exec=execlp(executable_path,executable_path,NULL);

			
		
			if(exec==-1)
			{	
				printf("Komut ya da söz dizimi hatalı !\n");
			}	
		
			exit(EXIT_SUCCESS);
		}	
		else
		{
			
			//ebeyevn proses tarafıdan işletilecek komutlar
			pid_w=waitpid(fork_pid,&statu,0);
			//fork_pid, yavru prosesi gösteriyor.

		}
	}
	
	
}