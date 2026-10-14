struct R { char pad[8]; float f8, fC; };
struct S { char pad[0xC4]; int fC4; };
extern "C" R *func_0025BF60(void);

extern "C" void func_002E96C0(S *self, float *a, float *b) {
    R *r = func_0025BF60();
    if (self->fC4 != 0) {
        *a = r->f8;
        *b = r->fC;
    } else {
        *a = r->fC;
        *b = r->f8;
    }
}
