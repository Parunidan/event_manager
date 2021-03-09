#include<stdio.h>
#include<stdlib.h>
#include<module.h>
#include<event_manager.h>
#include<stdbool.h>

extern int n_evt;
struct module *first = NULL, *last = NULL;

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

bool is_digit(char c){
        return((c >= 48) && (c <= 57));
}

int get_evt_bmap(char *events){
        int event = 0, event_bmap = 0, index = 0;
        char c = events[index];
        while(c != '\0'){
                if(is_digit(c)){
                        event = (event * 10) + (c - 48);
                }
                else if(event > 0){
                        event_bmap |= 1 << (event -1);
                        event = 0;
                }
                c = events[++index];
        }
        if(event > 0)
                event_bmap |= 1 << (event -1);
        return(event_bmap);
}

void module_init(){
	char events[100];
	for(int id = 1; id <= 5 ; id++){
		printf("Enter the events Module %d is interested in separated by commas:\n", id);
		scanf("%s", events);
		register_event(id, get_evt_bmap(events), get_fptr(id));
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
