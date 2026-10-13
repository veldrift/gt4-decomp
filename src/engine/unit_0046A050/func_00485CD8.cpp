typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    s32 count;
    s32 base;
};

extern "C" void func_00485CA8(int *p, int base);

extern "C" void func_00485CD8(Obj *arg0, s32 arg1)
{
    if (arg0->unk0 != 0) {
        arg0->unk0 = arg0->unk0 + arg1;
    }

    s32 *t = &arg0->base;

    if (*t != 0) {
        *t = *t + arg1;
    }

    s32 s1 = 0;

    if (arg0->count > 0) {
        do {
            s32 off = s1 << 3;
            s1 += 1;
            func_00485CA8((int *)(arg0->base + off), arg1);
        } while (s1 < arg0->count);
    }
}
