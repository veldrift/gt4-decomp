/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { char p0[0x31]; unsigned char b31; unsigned char b32; };
struct Car {
    char p0[4];
    int i4;
    char p8[8];
    Info *info;
};
struct Obj2 { char p0[1]; unsigned char cnt; };

extern "C" void func_00350ED0(void *) throw();
extern "C" void func_003511A0() throw();
extern "C" void func_00351850(void *) throw();
extern "C" void func_003518E8(void *) throw();
extern "C" void func_003519B8(void *) throw();
extern "C" void func_00351DC8(void *) throw();
extern "C" void func_00351EB0(void *) throw();
extern "C" void func_00351FA8(void *) throw();
extern "C" void func_00352408(void *) throw();
extern "C" void func_00352848(void *, int) throw();
extern "C" void func_00352C90(void *, int) throw();
extern "C" void func_003534A0(void *) throw();
extern "C" Obj2 *func_00359510(void *);
extern "C" int func_00368398(void *);
extern "C" void func_003694D0(void *);
extern "C" void func_0036D230(void *);
extern "C" void func_0036D2F8(void *);
extern "C" void func_0036D818(void *);
extern "C" void func_0036E4B8(void *);
extern "C" int func_003F1F78(void *);
extern "C" int func_003F1F88(void *);

extern "C" void func_003535B0(Car *c) {
    func_003511A0();
    func_003534A0(c);
    func_00351850(c);
    int f = 0;
    char *a = (char *)c + 0x104;
    signed char t = *(signed char *)(a + 0x466);
    if (t == 1 || (t == 2 || *(unsigned char *)(a + 0x467) != 0))
        f = 1;
    if (f) {
        Info *inf = c->info;
        signed char v = *(signed char *)((char *)inf->b31 + c->i4 + 0xF830);
        if (v != 0) {
            float s = (float)v * 0.01f + 1.0f;
            Obj2 *o = func_00359510(inf);
            int k = 0;
            if (o->cnt != 0) {
                char *q = (char *)c + 0x164;
                do {
                    k++;
                    *(float *)(q + 0x60) = *(float *)(q + 0x60) * s;
                    *(float *)(q + 0x58) = *(float *)(q + 0x58) * s;
                    q += 0xEC;
                } while (k < o->cnt);
            }
        }
    }
    func_003518E8(c);
    func_00352408(c);
    func_00351FA8(c);
    func_0036D230(c);
    func_0036D2F8(c);
    func_0036D818(c);
    func_0036E4B8(c);
    if (func_00368398((char *)c->info + 0x234) != 0) {
        func_003694D0(c);
        func_00351EB0(c);
    } else if (func_003F1F78((char *)c->info + 0x234) != 0) {
        func_003519B8(c);
        func_00351EB0(c);
    } else if (func_003F1F88((char *)c->info + 0x234) != 0) {
        func_003519B8(c);
        func_00351DC8(c);
    } else if (c->info->b32 == 2) {
        func_003519B8(c);
        func_00351EB0(c);
    } else {
        func_003519B8(c);
        func_00351DC8(c);
    }
    func_00350ED0(c);
    unsigned char cnt = func_00359510(c->info)->cnt;
    float sum = 0.0f;
    if (cnt != 0) {
        unsigned int n = cnt;
        float *p = (float *)((char *)c + 0x1AC);
        do {
            float x = *p;
            p = (float *)((char *)p + 0xEC);
            n--;
            sum += x;
        } while (n != 0);
    }
    int r = 1;
    if (sum != 0.0f)
        r = 0;
    func_00352848(c, r);
    return func_00352C90(c, r);
}
