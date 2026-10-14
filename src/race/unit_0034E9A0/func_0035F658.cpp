struct VE {
    short adj;
    short pad;
    int (*fn)(void *);
};

struct VT {
    char pad0[0x310];
    VE e310;
};

struct Inner {
    char pad0[0x64];
    VT *vt;
};

struct Mid {
    char pad0[0x84];
    Inner *in;
};

struct Obj {
    Mid *m;
};

extern int D_006208B0;
extern float D_008439B8[12];
extern int D_00843A18;

extern "C" int func_0034C190(Obj *, int);
extern "C" void func_0035F420(int);
extern "C" int func_0035EDD8(float *);

extern "C" void func_0035F658(Obj *o) {
    if (D_006208B0 == 0) {
        Inner *in = o->m->in;
        VE *e = &in->vt->e310;
        int r = e->fn((char *)in + e->adj);
        func_0035F420(func_0034C190(o, r));
        float buf[6];
        for (int i = 0; i < 6; i++) {
            buf[i] = D_008439B8[i] + D_008439B8[i + 6];
        }
        D_00843A18 = func_0035EDD8(buf);
    }
}
