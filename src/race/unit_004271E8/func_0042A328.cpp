typedef int s32;
typedef unsigned short u16;

struct Obj {
    u16 count;
    char pad2[2];
    s32 base;
    char pad8[8];
    s32 other;
};

extern "C" void func_0042A260(struct Obj *arg0, s32 arg1);

extern "C" void func_0042A328(struct Obj *arg0, s32 arg1)
{
    s32 s1 = 0;
    s32 a = arg0->base;
    s32 b = arg0->other;

    arg0->base = (a == 0) ? 0 : a + arg1;
    arg0->other = (b == 0) ? 0 : b + arg1;

    if (arg0->count != 0) {
        do {
            s32 off = s1 << 5;
            s1 += 1;
            func_0042A260((Obj *)(arg0->base + off), arg1);
        } while (s1 < (s32)arg0->count);
    }
}
