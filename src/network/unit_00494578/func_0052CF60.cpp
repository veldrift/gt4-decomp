struct Opt { bool enable; int size; int c; };
struct Obj { int x; char pad4[0x44]; int h48, h4c; char pad50[0x28]; long h78; int h80; };
struct Table {
    char p0[8]; int (*f8)(); char pc[8];
    int (*f14)(Obj *, long, int, Opt *); char p18[0x2c];
    int (*f44)(long *); char p48[0x14];
    int (*f5c)(int, int *); char p60[0xc];
    void (*f6c)(long *);
};
extern Table *D_0064B4B0;
extern "C" int func_00538BF8(int *, int);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_0052CF60(Obj *o) {
    Opt opt;
    long val;
    int r = D_0064B4B0->f8();
    if (r != 0) return r;
    D_0064B4B0->f6c(&val);
    func_00538BF8(&o->h48, 0x5aa);
    if (o->h48 == 0) return 100;
    func_00538BF8(&o->h4c, 0x5aa);
    if (o->h4c == 0) return 100;
    func_005A48D8(&opt, 0, 12);
    opt.size = 0x5aa;
    opt.enable = true;
    r = D_0064B4B0->f14(o, val, o->h80, &opt);
    if (r != 0) return r;
    r = D_0064B4B0->f5c(o->x, &o->h80);
    if (r != 0) return r;
    return D_0064B4B0->f44(&o->h78);
}
