struct A {
    char p0[0x18];
    int f18;
    char p1[0x2C - 0x1C];
    char sub[0x7C - 0x2C];
    char arr[0x1A8 - 0x7C];
    float f1a8;
};
struct L { int vt; float v[19]; };
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void func_004A5CC0(int, void *);
extern "C" int func_004283D0(void *, int);
extern "C" void func_00428670(void *, int, void *, int, float, float);
extern "C" void func_00428568(void *, int, float, int, float);
extern "C" void func_004523B0(float, float, float);
extern "C" void func_004523E8(float, float, float, float);
extern "C" void func_00452408(float);
extern "C" void func_001D6700(void *, void *);
extern char D_00661FD8[];

extern "C" void func_001D6C98(A *a) {
    float z[4];
    L l;
    void *sub = a->sub;
    func_005A48D8(z, 0, 0x10);
    z[3] = 1.0f;
    func_004A5CC0(0, z);
    L *pl = &l;
    pl->vt = (int)D_00661FD8;
    if (func_004283D0(sub, a->f18) != 0) {
        func_00428670(sub, a->f18, pl, 0, a->f1a8, 0.0f);
        char *p = a->arr;
        func_00428568(sub, a->f18, a->f1a8, 0, 0.0f);
        int i = 1;
        func_004523B0(-l.v[0], -l.v[1], -l.v[2]);
        func_004523E8(0.0f, 0.0f, 0.0f, 1.0f);
        func_00452408(1.0f);
        float *m = l.v;
        do {
            char *q = p;
            p += 0x40;
            float *mm = m;
            m += 4;
            i--;
            func_001D6700(q, mm);
        } while (i >= 0);
    }
}
