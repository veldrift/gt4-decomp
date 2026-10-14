typedef unsigned char u8;
struct Ref { char p[0x18]; void *r18; };
struct Obj {
    char p0[8]; int state; char p1[4]; Ref *ref; char p2[0x64]; float f78;
    char p3[0x22]; u8 b9e; char p4[0xd]; float fac; char p5[2]; u8 bb2;
};
extern "C" void func_003FC168(Obj *, int, int, float, float, float, float, float);
extern "C" int func_003FD490(void *, int *, int *);
extern "C" int func_003FD528(void *, int *, float *, float *);
extern "C" int func_003FD590(void *, float *);

extern "C" void func_003FC320(Obj *o)
{
    if (o->state == 1) {
        int total;
        u8 used;
        float b, c;
        int *pu = (int *)&used;
        void *s = o->ref->r18;
        func_003FC168(o, 0, func_003FD490(s, pu, &total), 0x1.333332p-2f, 0.0f, 3.0f, 5.0f, 5.0f);
        float *pc = &c;
        func_003FC168(o, 1, func_003FD528(s, pu, &b, pc), 0x1.999998p-3f, 2.5f, 4.0f, 12.0f, 4.0f);
        o->b9e = used;
        func_003FC168(o, 2, func_003FD590(s, pc), 0x1.333332p-2f, 0x1.333332p-2f, 4.0f, 5.0f, 5.0f);
        o->bb2 = c > 0.0f;
        o->fac = c;
        char *base = (char *)o + 8;
        float *p = &o->f78;
        float m = 60.0f;
        int i = 2;
        do {
            float f = *p;
            p += 5;
            if (f < m) m = f;
            i--;
        } while (i >= 0);
        float *q = (float *)(base + 0x98);
        i = 2;
        do {
            i--;
            *q = m;
            q -= 5;
        } while (i >= 0);
    }
}
