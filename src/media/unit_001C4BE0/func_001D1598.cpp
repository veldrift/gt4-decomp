extern "C" void *func_001CBFE0(void *);
extern "C" void func_001CC060(void *, int);
extern "C" int func_001CC528(void *, void *);
extern "C" int func_001CFFF8(void *, void *, void *, int);
extern "C" void free(int);
extern "C" char *func_005A609C(char *, void *);
extern char D_00660FC0[];
extern char D_006611F0[];
extern char D_006614F8[];
extern const int D_00621C98;

struct Obj {
    char p[0x24];
    char sub[0x24];
    unsigned short flags;
    char q[2];
    char *vptr;
    char r[4];
    int f54, f58, f5c, f60;
    char tail[0xFC];
};
struct Args { int a, b; };

#define DTOR() do { \
    o.vptr = v1; \
    if (o.f54 != 0) free(o.f54); \
    o.vptr = v2; \
    func_001CC060(&o, 0); \
} while (0)

extern "C" int func_001D1598(void *arg0, void *arg1, int arg2) {
    Args args;
    Obj o;
    args.a = arg2;
    int g = D_00621C98;
    args.b = g;
    func_001CBFE0(&o);
    char *v2 = D_006614F8;
    char *v1 = D_006611F0;
    o.vptr = D_00660FC0;
    o.f54 = 0;
    o.f58 = 0;
    o.f5c = 0;
    o.f60 = 0;
    func_005A609C(o.sub, arg1);
    int ok = func_001CC528(&o, arg0);
    if (ok != 0) {
        unsigned fl = o.flags;
        if ((fl >> 2) & 1) {
            DTOR();
            return 1;
        }
    }
    if (ok == 0 || func_001CFFF8(&o, arg0, &args, 0) != 0) {
        DTOR();
        return -1;
    }
    DTOR();
    return 0;
}
