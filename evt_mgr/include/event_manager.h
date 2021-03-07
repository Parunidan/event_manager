void register_event(int id, int evt_bmap, fptr cb);

int ifset(int event, struct module *module);

void execute_event(int event);
