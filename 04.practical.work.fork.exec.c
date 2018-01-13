#include <unistd.h>
#include <stdio.h>
int main(){
	int pid = fork();
	if (pid == 0){
		int pid2 = fork();
		if (pid2 == 0){
			char *args[] = {"/bin/ps","-ef",NULL};
			execvp("/bin/ps",args);
		} else{
			char *args[] = {"free","-h",NULL};
			execvp("free",args);
		}
	}
	return 0;
}
