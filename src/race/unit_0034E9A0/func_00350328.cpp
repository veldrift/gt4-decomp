struct B { char p[0x608 - 0x104 + 0x104 - 0x104 + 0]; };
struct Blk { char p[0x608]; float m608; char m60C; char m60D; };
struct S { char p0[4]; void *conductor; char p1[0x104 - 8]; Blk b; };
extern "C" unsigned char DynamicsConductor__GetNumberOfPylonsToBeTouched(void *);
extern "C" void func_00350328(S *s, int k, int n, float f)
{
    Blk *b = &s->b;
    if (k != -1) {
        float v = 0.0f;
        switch (k) {
        case 0:
            v = f / 50000.0f;
            break;
        case 1:
            v = 2.0f * f;
            break;
        case 2:
            if (!DynamicsConductor__GetNumberOfPylonsToBeTouched(s->conductor)) return;
            v = f / 50.0f;
            if (v < 0.0f) v = -v;
            if (v < 0x1.999998p-3f) v = 0x1.999998p-3f;
            break;
        }
        if (v > 1.0f) v = 1.0f;
        if (v < 0x1.999998p-3f) v = 0.0f;
        if (b->m608 < v) {
            b->m608 = v;
            b->m60C = k;
            b->m60D = n;
        }
    }
}
