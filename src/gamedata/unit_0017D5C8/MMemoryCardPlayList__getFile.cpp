/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;

struct Obj;
struct VEnt {
    short adj;
    short pad;
    s32 (*fn)(Obj *);
};
struct VTab {
    char pad[0x58];
    VEnt e;
};
struct Obj {
    s32 pad0;
    VTab *vt;
};

struct Hdr {
    char pad[0x10];
    s32 v10;
};

struct Owned {
    char pad[0x14];
    s32 f14;
};

extern "C" void func_001740F0(void *, int);
extern "C" void mMemoryCardFile__structor_0(void *, void *);
extern "C" void func_0017D268(void *, int) throw();
extern "C" void func_0017D2C0(void *) throw();
extern "C" s8 func_001CD860(void *);
extern "C" void *func_001D1340(s32, int, void *);
extern "C" char *func_001D3800(int);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" char *func_005A609C(char *, const char *);

extern "C" void MMemoryCardPlayList__getFile(Owned **out, int unused, int count, Obj **pobj) {
    Hdr *a[4];
    char sp10[0x40];
    Owned *sp50[4];
    func_0017D2C0(a);
    if (count > 0) {
        Obj *o = *pobj;
        VEnt *e = &o->vt->e;
        int idx = e->fn((Obj *)((char *)o + e->adj));
        if (idx >= 0) {
            Hdr *h = a[0];
            char *pt = sp10;
            func_001D1340(h->v10, idx, pt);
            char *s = func_001D3800(func_001CD860(pt));
            if (s != 0) {
                func_005A609C(s + 0x24, pt);
                Owned **ps = sp50;
                mMemoryCardFile__structor_0(ps, s);
                ps[0]->f14 = 1;
                if (out != ps) {
                    Owned *nv = ps[0];
                    if (nv != 0)
                        func_003285A8(nv);
                    if (*out != 0)
                        func_003285F8(*out);
                    *out = nv;
                }
                func_001740F0(ps, 2);
            }
        }
    }
    func_0017D268(a, 2);
}
