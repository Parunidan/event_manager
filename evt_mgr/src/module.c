#include<stdio.h>
#include<stdlib.h>
#include<module.h>
#include<event_manager.h>

extern int n_evt;
extern struct module *first, *last;

void init_module(struct module *module){
	module->next = NULL;
	module->prev = NULL;
}

struct module* insert_module(){
	
	struct module *new_module = (struct module*)malloc(sizeof(struct module));
	init_module(new_module);

	if (first == NULL){
		first = new_module;
		last = new_module;
		return(new_module);
	}

	last->next = new_module;
	new_module->prev = last;
	new_module->next = NULL;
	last = new_module;

	return(new_module);
}

void module1(){
	printf("%s\n", __func__);
}

void module2(){
	printf("%s\n", __func__);
}

void module3(){
	printf("%s\n", __func__);
}

void module4(){
	printf("%s\n", __func__);
}

void module5(){
	printf("%s\n", __func__);
}

fptr get_fptr(int i){
	switch(i){
		case 1:
			return(&module1);
		case 2:
			return(&module2);
		case 3:
			return(&module3);
		case 4:
			return(&module4);
		case 5:
			return(&module5);
		default:
			return(NULL);
	}
}

void module_init(){
	int evt = 0, x = 0;
	for(int id = 1; id <= 5 ; id++){
		printf("Enter the events Module%d is interested in:\nEnter -1 when done\n", id);
		scanf("%d",&x);
		while((x != -1) && (x>0) && (x <= n_evt)){
			evt |= 1 << (x - 1);
			scanf("%d",&x);
		}
		register_event(id, evt, get_fptr(id));
		evt = 0;
	}
}

void freeall_module(){
	struct module *temp = first;
	while(first != NULL){
		first = temp->next;
		init_module(temp);
		free(temp);
		temp = first;
	}
	last = NULL;
	return;
}
