#include<stdio.h>
#include<module.h>
#include<event_manager.h>
#include<bit_macro.h>

extern struct module *first, *last;

void register_event(int id, int evt_bmap, fptr cb){
	struct module *new = insert_module();
	new->id = id;
	new->event_bmap = evt_bmap;
	new->cb = cb;
	return;
}

void execute_event(int event){
	struct module *temp = first;
	while(temp != NULL){
		if (IFSET(temp->event_bmap, event)){
			temp->cb(event);
		}
		temp = temp->next;
	}
}
