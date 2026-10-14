extern char D_006AE490[];
extern char D_006AE498[];

struct Ent {
    char pad[0x16];
    unsigned char b16;
};

struct Self {
    char pad0[0xC];
    int c;
    char pad10[4];
    struct Ent *p14;
    int f18;
};

extern "C" void func_00490148(void *self);
extern "C" void func_0057DA20(int arg0, int arg1, ...);
extern "C" int func_00491D90(void *buf);
extern "C" void func_00491B30(int v);
extern "C" int func_00491C10(int a, unsigned char b);
extern "C" void func_00491DE0(void);

extern "C" int func_004900B8(struct Self *arg0, int arg1) {
    char buf[128];
    int r;
    unsigned char b;
    if (arg0->c != 0) {
        func_00490148(arg0);
    }
    func_0057DA20((int)buf, (int)D_006AE490, (int)D_006AE498, arg1);
    r = func_00491D90(buf);
    arg0->c = r;
    func_00491B30(r);
    b = 0;
    if (arg0->p14 != 0) {
        b = arg0->p14->b16;
    }
    arg0->f18 = func_00491C10(arg0->c, b);
    func_00491DE0();
    return arg0->c;
}
