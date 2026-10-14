struct Cam { char pad[0x1E668]; int mode; char pad1[4]; float f1E670; float f1E674; float f1E678; float f1E67C; };
struct F6 { float a, b, c, d, e, f; };
static inline void initF(F6 *p, float a, float b, float c, float d, float e, float f) { p->a = a; p->b = b; p->c = c; p->d = d; p->e = e; p->f = f; }
extern "C" void func_0033DE30(void *, void *);
extern "C" void func_003EFC10(void *, float, float, float, float, float);
extern "C" void func_003EFCE8(void *, float, float, float, float, float, float);
extern "C" void func_003EFD80(void *, void *);

extern "C" void func_003C7DA8(Cam *o)
{
    float m[8];
    F6 c;
    func_003EFC10(m, o->f1E674, o->f1E67C, o->f1E670, o->f1E678, 5500.0f);
    switch (o->mode) {
    case 2:
        m[5] = 0.0f;
        break;
    case 1: {
        initF(&c, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f);
        func_003EFCE8(&c, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0x1.333332p-1f);
        func_003EFD80(m, &c);
        break;
    }
    case 4: {
        initF(&c, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f);
        func_003EFCE8(&c, 1.5f, 0x1.e66666p-1f, 0x1.333332p-1f, 0.0f, 1.0f, 0x1.333332p-2f);
        func_003EFD80(m, &c);
        break;
    }
    }
    func_0033DE30(o, m);
}
