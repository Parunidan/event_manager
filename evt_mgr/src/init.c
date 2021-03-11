#include<stdio.h>
#include<module.h>
#include<event_manager.h>


int n_evt;

int main(){
	int run = 1, event;
	printf("Enter the number of events:");
	scanf("%d",&n_evt);
	module_init();
	printf("Enter the events to be executed:\nEnter -1 when done\n");
	while(run){
		scanf("%d",&event);
		if(event != -1){
			if((event > 0) && (event <= n_evt))
				execute_event(event);
			else
				printf("Enter Valid Event\n");
		}
		else{
			freeall_module();
			run = 0;
		}
	}
	return(0);
}
