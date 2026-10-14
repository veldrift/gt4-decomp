typedef int s32;
typedef float f32;

struct Obj2 {
    char *vtbl;
};

struct VEntryI {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VEntryFI {
    short delta;
    short index;
    f32 (*fn)(void *, s32);
};

struct VEntryV {
    short delta;
    short index;
    void (*fn)(void *, f32);
};

extern "C" void *func_003917D8(void);
extern "C" void func_004511E0(void *arg0, f32 fparg0);
extern "C" void func_00451370(void *arg0, f32 fparg0, s32 arg2);
extern "C" void func_004513B8(void *arg0, s32 arg1);
extern "C" void func_004513C0(void *arg0, s32 arg1, f32 fparg0);
extern "C" void func_00451408(void *arg0, s32 arg1, f32 fparg0);
extern "C" void func_00451550(void *arg0, s32 arg1, f32 fparg0);

extern "C" void RaceCarModel__virtual_02(void *arg0) {
    char *s3 = (char *)arg0;
    char *s1 = s3 + 0x18;
    Obj2 *s2 = *(Obj2 **)s3;
    s32 i = 0;
    s32 k;
    f32 f;
    f32 *p;
    {
        VEntryI *e = (VEntryI *)(s2->vtbl + 0x90);
        s32 dir = e->fn((char *)s2 + e->delta);
        func_00451370(s1, 0x1.111110p-6f, dir);
    }
    do {
        VEntryFI *e1 = (VEntryFI *)(s2->vtbl + 0xC8);
        f32 a = e1->fn((char *)s2 + e1->delta, i);
        func_004513C0(s1, i, a);
        VEntryFI *e2 = (VEntryFI *)(s2->vtbl + 0xC0);
        f32 b = e2->fn((char *)s2 + e2->delta, i);
        func_00451550(s1, i, b);
        i++;
    } while (i < 4);
    {
        f32 zero = 0.0f;
        i = 0;
        while (i < 4) {
            VEntryFI *e = (VEntryFI *)(s2->vtbl + 0xD0);
            f = e->fn((char *)s2 + e->delta, i);
            if (f < zero) {
                break;
            }
            func_00451408(s1, i, f);
            i++;
        }
    }
    {
        f32 dt = 0x1.111110p-6f;
        s32 v = *(s32 *)(s3 + 0x1680);
        p = (f32 *)(s3 + 0x1678);
        func_004513B8(s1, v);
        func_004511E0(s1, dt);
        k = 0;
        do {
            s32 off = k * 16;
            k++;
            *p = *p + dt;
            void *base = func_003917D8();
            if (*(f32 *)((char *)base + off) < *p) {
                void *base2 = func_003917D8();
                *p = *p - *(f32 *)((char *)base2 + off);
            }
            p++;
        } while (k < 2);
    }
    {
        VEntryV *e = (VEntryV *)(s2->vtbl + 0x18);
        e->fn((char *)s2 + e->delta, 0x1.111110p-6f);
    }
}
