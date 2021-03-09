#include<stdio.h>
#include<module.h>
#include<event_manager.h>

extern struct module *first, *last;

void register_event(int id, int evt_bmap, fptr cb){
	struct module *new = insert_module();
	new->id = id;
	new->event_bmap = evt_bmap;
	new->cb = cb;
	return;
}

int ifset(int event, struct module *module){
	return((module->event_bmap >> (event - 1)) & 1);
}

void execute_event(int event){
	struct module *temp = first;
	while(temp != NULL){
		if (ifset(event, temp)){
			temp->cb(event);
		}
		temp = temp->next;
	}
}
