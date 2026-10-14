/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
struct Obj {
    char pad0[4];
    int f4;
    char pad8[8];
    int f10;
    u16 *p14;
};
extern "C" void func_004B64E0(Obj *, void *, int) throw();
extern "C" int func_0057D9C0(const char *, ...) throw();
extern "C" void *func_005C15B0(int);
extern "C" void func_005C1628(void *) throw();

extern char D_006B0470[], D_006B0480[], D_006B0488[], D_006B0490[], D_006B0498[], D_006B04A0[];

static inline int len16(const u16 *p) {
    int n = 0;
    if (*p) {
        const u16 *cursor = p;
        do {
            cursor++;
            n++;
        } while (*cursor);
    }
    return n;
}

extern "C" void func_004B6880(Obj *o) {
    int n = 0;
    void *buf = func_005C15B0(o->f4 * 2);
    func_004B64E0(o, buf, o->f4);
    func_0057D9C0(D_006B0470, o->f10, buf);
    n = len16(o->p14);
    int i;
    for (i = 0; i < n; i++) {
        if (i == o->f10) func_0057D9C0(D_006B0480);
        func_0057D9C0(D_006B0488, o->p14[i] & 0x7F);
    }
    if (o->f10 == n) func_0057D9C0(D_006B0480);
    for (i = 0; i < len16(o->p14); i++) {
        unsigned int bits = o->p14[i];
        if ((bits >> 7) & 1) {
            func_0057D9C0(D_006B0490);
        } else {
            func_0057D9C0(D_006B0498);
        }
    }
    func_0057D9C0(D_006B04A0);
    func_005C1628(buf);
}
