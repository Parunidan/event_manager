#define SETBIT(val, pos) (val |= 1 << (pos -1))
#define IFSET(val, pos) ((val >> (pos - 1)) & 1)
