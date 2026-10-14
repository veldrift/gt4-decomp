struct V { char pad[0x60]; int (*f60)(void *, int *); };
struct Sub {
    char pad[0x1C];
    void *m1C;
};
struct N {
    char pad[0x20];
};
struct O {
    int m0;
    char pad4[4];
    int m8;
    char padC[0x78 - 0xC];
    N *arr[2];
    Sub *m80;
};
extern "C" V *D_0064B4B0;
extern "C" int func_0051DDE8(Sub *);
extern "C" int func_0051DE30(O *);
extern "C" int func_00520230(int);
extern "C" void func_0053A860(void *);

extern "C" int func_0051D448(O *o) {
    int sp0 = 0;
    int r = D_0064B4B0->f60(o->m80->m1C, &sp0);
    if (r == 0) {
        unsigned int i = 0;
        if (sp0 != 0) {
            N **pp = &o->arr[0];
            do {
                N *p = *pp;
                pp++;
                if (p != 0) {
                    func_0053A860((char *)p + 0x20);
                    func_0053A860((char *)p + 0x28);
                    func_0053A860((char *)p + 0x34);
                }
                i++;
            } while (i < 2);
            if (func_00520230(o->m0) != 0) {
                r = func_0051DDE8(o->m80);
                if (r == 0) {
                    o->m8 = 3;
                    goto z;
                }
            } else {
                r = func_0051DE30(o);
                if (r == 0) {
                    o->m8 = 4;
                    goto z;
                }
            }
        } else {
        z:
            r = 0;
        }
    }
    return r;
}
