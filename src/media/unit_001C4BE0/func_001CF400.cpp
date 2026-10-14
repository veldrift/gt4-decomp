typedef unsigned int u32;
struct H { u32 k0; u32 k4; char d[0xE8]; };
struct VE { short delta; short index; int (*fn)(void *, char *, void *, int); };
struct Blob { char d[0xE8]; };
struct Self { char p[0x68]; Blob b; };
struct Obj { char *tbl; };
extern "C" char *func_001CF3C0(void *, char *);
extern "C" int func_001CF7D0(Self *);
extern "C" int func_00575E60(int, int);
extern "C" void free(int);
extern "C" void func_001D4D10(H *arg0, int arg1, u32 arg2, int arg3, float f0, float f1);
extern "C" int func_001CF400(Self *self, Obj *obj) {
    char buf[0x50];
    func_001CF3C0(self, buf);
    H *h = (H *)func_00575E60(0x40, func_001CF7D0(self));
    *(Blob *)h->d = self->b;
    func_001D4D10(h, 0xE8, 0, 1, 0x1.41b2f2p-2f, 0x1.dfe4p-2f);
    int k = func_001CF7D0(self);
    VE *e = (VE *)(obj->tbl + 0x80);
    int r = e->fn((char *)obj + e->delta, buf, h, k) == 0;
    free((int)h);
    return r;
}
