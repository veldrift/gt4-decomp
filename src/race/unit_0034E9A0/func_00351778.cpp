/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[1]; unsigned char m1; };
struct Slot {
    float m0; char p0[0x28 - 4]; float m28; float m2C;
    char p1[0x89 - 0x30]; unsigned char m89;
    char p2[0xEC - 0x8A];
};
struct Self { char p[0x10]; void *m10; char q[0x164 - 0x14]; Slot s[8]; };
extern "C" Obj *func_00359510(void *);
extern "C" void *func_00360F80(void *, int, int);
extern "C" float func_0057D1F0(float);
extern "C" float func_0057D2B8(float) throw();
extern "C" void func_003513F8(Slot *, void *, void *, float) throw();

extern "C" void func_00351778(Self *self) {
    unsigned i = 0;
    void *d = self->m10;
    Obj *o = func_00359510(d);
    if (__builtin_expect(o->m1, 0)) {
        Slot *p = self->s;
        do {
            void *it = func_00360F80(d, i, p->m89);
            i++;
            float a = p->m0;
            float x = func_0057D1F0(a) * p->m28;
            float y = func_0057D2B8(a) * p->m2C;
            Slot *q = p;
            p++;
            func_003513F8(q, d, it, x - y);
        } while (i < o->m1);
    }
}
