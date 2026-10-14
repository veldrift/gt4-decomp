/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { char p0[8]; float tab[0x1A0 / 4]; char pad[0x1AC - 0x8 - 0x1A0]; char m1AC[0x2E]; unsigned char m1DA; };
struct V12 { float a, b, c; };
struct Data { char p[0x3B8]; V12 ent[0x18]; char q[0xFD0 - 0x3B8 - 0x18 * 12]; float tab[8]; };
struct Obj { unsigned char m0, m1; char pad[0x12]; unsigned char m14[8]; unsigned char m1C[8]; };
struct Slot {
    char p0[4]; float m4;
    char p1[0x48 - 8]; float m48; float m4C; float m50;
    char p2[0x89 - 0x54]; unsigned char m89;
    char p3[0xDD - 0x8A]; unsigned char mDD;
    char p4[0xEC - 0xDE];
};
struct Self { char p0[4]; int m4; char p1[8]; Data *m10; };
extern "C" Obj *func_00359510(Data *);
extern "C" int func_00356EF0(void *, int) throw();
extern "C" Item *func_00360F80(Data *, int, int);
extern "C" float func_003573A8(Data *, int, float) throw();
extern "C" float func_00359830(void *, float);
extern "C" float func_00467470(void *, int);

extern "C" void func_00357418(Self *self) {
    int i = 0;
    char *b = (char *)self + 0x104;
    Data *d = self->m10;
    Obj *o = func_00359510(d);
    int f7 = func_00356EF0(self, self->m4 + 4);
    float diff = *(float *)(b + 0x56C) - *(float *)(b + 0x578);
    if (o->m1 != 0) {
    Slot *p = (Slot *)((char *)self + 0x164);
    do {
        unsigned s5 = 0;
        Item *it = func_00360F80(d, i, p->m89);
        if (i < o->m1) s5 = o->m14[i];
        float f = p->m48;
        p->mDD = it->m1DA;
        f = f * func_00359830(it->m1AC, func_003573A8(d, i, f));
        if (f7) f = f * p->m50;
        f = f * d->tab[s5];
        float x;
        if (o->m0 != 1) {
            x = 0.0f;
            unsigned t = o->m1C[i];
            if (t == 0) x = -diff;
            else {
                unsigned u = t ^ 1;
                if (u == 0) x = diff;
            }
            x = x + p->m4;
        } else {
            x = 0.0f;
        }
        p->m4C = f * it->tab[p->m89] * func_00359830(&d->ent[s5], x);
        p->m4C = p->m4C * func_00467470(self, p->m89);
        i++; p++;
    } while (i < o->m1);
    }
}
