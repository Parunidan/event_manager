#include<stdbool.h>

typedef void (*fptr)(void);

struct module{                                                         
        int id;                                                        
        int event_bmap;                                                
        fptr cb;                                                       
        struct module *next;                                           
        struct module *prev;                                           
};

void init_module(struct module *module);

struct module* insert_module();

void module1();

void module2();

void module3();

void module4();

void module5();

fptr get_fptr(int i);

bool is_digit(char c);

int get_evt_bmap(char *events);

void module_init();

void freeall_module();
