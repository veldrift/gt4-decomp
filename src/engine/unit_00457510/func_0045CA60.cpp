/* compiler: ee-gcc2.96-nogcse */
struct Elem {
    char pad1[0x3C4];
    float f3C4, f3C8, pad3CC, f3D0;
    char pad2[0x3F4 - 0x3D4];
    int f3F4, f3F8;
    char pad3[0x43C - 0x3FC];
    int f43C;
    char pad4[0x450 - 0x440];
    char *f450;
    char pad5[0x4DC - 0x454];
    float f4DC;
};
extern "C" int func_003451B8(char *);
extern "C" float func_00344680(char *, unsigned char *);
extern "C" void func_0045C5A8(Elem *) throw();
static inline float abs_(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" void func_0045CA60(Elem *p, float dt)
{
    if (func_003451B8(p->f450)) {
        int busy = ((p->f3F8 != 0) | (p->f3F4 != 0) | p->f43C) != 0;
        if (!busy) {
            int i = 0;
            char *t2 = (char *)p + 8;
            char *t1 = (char *)p + 0xC;
            int *q2 = (int *)((char *)p + 0x248);
            int *q1 = (int *)((char *)p + 0x244);
            int off = 0x20;
            do {
                if ((*(int *)(t2 + off) & 1) || *(int *)(t1 + off) || *q1 || *q2) { busy = 1; break; }
                off += 0x44;
                q1 = (int *)((char *)q1 + 0x2C);
                q2 = (int *)((char *)q2 + 0x2C);
                i++;
            } while (i < 8);
        }
        float one = 1.0f;
        if (abs_(p->f3C4) < one && abs_(p->f3C8) < one && dt < 0.1f && busy) {
            p->f3D0 += func_00344680(p->f450, 0) * 20.0f * p->f4DC;
            func_0045C5A8(p);
        }
    }
}
