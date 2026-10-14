/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E { char p0[0x50]; float m50; char p1[0xA4 - 0x54]; int mA4; float mA8; float mAC; char mB0; char mB1; char p2[0xEC - 0xB2]; };
struct T { float m0; float m4; char p[0x50 - 8]; float m50; float m54; };
struct P { char p0[4]; T *t; };
struct Q { char p[0x32]; unsigned char m32; };
struct S { char p0[4]; char *owner; char p1[8]; Q *q; char p2[0x164 - 0x14]; E e[1]; };
extern "C" int TireWearParameters__isWearAvailable(void *);
extern "C" int TireWearParameters__isHeatAvailable(void *);
extern "C" void func_00362E58(S *s, int i)
{
    float one = 1.0f;
    E *e = (E *)((char *)s + i * 0xEC + 0x164);
    e->m50 = one;
    e->mAC = 0.0f;
    e->mB1 = 0;
    e->mB0 = 0;
    e->mA4 = 0;
    e->mA8 = 0.0f;
    T *t = (T *)(s->owner + 4);
    if (TireWearParameters__isWearAvailable(t)) {
        e->mAC = t->m0;
        if (!TireWearParameters__isHeatAvailable(t)) {
            if (e->mAC < 0.0f)
                e->mB1 = -0x3F;
            else
                e->mB1 = 0;
        }
        e->m50 = 1.0f - t->m4;
    }
    if (TireWearParameters__isHeatAvailable(t)) {
        float f = t->m50;
        e->mA8 = f;
        if (f < 0.0f)
            e->mB1 = -0x3F;
        else
            e->mB1 = 0;
        e->m50 = e->m50 * (1.0f - t->m54);
    }
    if (s->q->m32 == 4) {
        e->mA8 = 0.0f;
        e->mAC = 0.0f;
        e->mB1 = 0;
        e->m50 = 1.0f;
    }
}
