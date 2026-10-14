struct Rec { char pad[0x20]; };
struct Obj {
    void *vt;
    char pad4[4];
    Rec recs[1000];
    char pad2[0x7D08 - 8 - 1000 * 0x20];
    char sub[0x81C8 - 0x7D08];
    int f81C8, f81CC;
    char p3[0x81E0 - 0x81D0];
    int f81E0;
    char p4[0x81F0 - 0x81E4];
    int f81F0, f81F4;
};
extern char D_00687AE0[];
extern "C" int func_0043A3F8(void *);
extern "C" void *func_0043DC20(void *);
extern "C" void func_0043E240(unsigned char *);
extern "C" void func_00434D80(void *);
extern "C" void func_004351A8(Obj *o) {
    int i;
    func_0043A3F8(o);
    o->vt = D_00687AE0;
    func_0043DC20(o->sub);
    for (i = 0; i <= 999; i++) func_00434D80(&o->recs[i]);
    o->f81C8 = -1;
    func_0043E240((unsigned char *)o->sub);
    o->f81CC = 0;
    o->f81E0 = 0;
    o->f81F0 = 0;
    o->f81F4 = 0;
}
