#include<stdio.h>
#include<module.h>
#include<event_manager.h>


int n_evt;
struct module *first = NULL, *last = NULL;

int main(){
	int run = 1, x;
	printf("Enter the number of events:");
	scanf("%d",&n_evt);
	module_init();
	printf("Enter the events to be executed:\nEnter -1 when done\n");
	while(run){
		scanf("%d",&x);
		if(x != -1){
			if((x > 0) && (x <= n_evt))
				execute_event(x);
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
