struct Obj;
struct O {
    char p0[4];
    O *self;
    int f8;
    char pc[4];
    unsigned short f10;
    char pe[2];
    int f14;
    int f18;
};
extern "C" void func_00491C50(int, int, int);
static inline void adj(int *p, int a) { if (*p) *p += a; }
extern "C" void func_00491B30(O *o) {
    int d = (int)o - (int)o->self;
    if (d != 0) {
        o->self = o;
        adj(&o->f8, d);
        adj(&o->f18, d);
        if (o->f14) {
            adj(&o->f14, d);
            int i = 0;
            if (o->f10 != 0) {
                do {
                    int *e = (int *)o->f14 + i;
                    adj(e, d);
                    func_00491C50(((int *)o->f14)[i], d, o->f18);
                    i++;
                } while (i < o->f10);
            }
        }
    }
}
