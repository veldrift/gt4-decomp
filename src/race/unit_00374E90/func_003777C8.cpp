/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry1 {
    s16 delta;
    s16 index;
    s32 (*fn)(char *self, s32 idx);
};

struct VEntry2 {
    s16 delta;
    s16 index;
    void (*fn)(char *self, char *p, s32 b, s32 c);
};

extern "C" s32 func_003777C8(char *self, s32 a1, s32 a2, s32 idx, s32 flags, s32 *out)
{
    s32 result = 0;
    char *p = self + idx * 0x19C;
    char *p2 = p + 0x10;
    VEntry1 *e = (VEntry1 *)(*(char **)self + 0xD8);
    s32 prev = *(s32 *)(p2 + 0x16C);
    s32 cur = e->fn(self + e->delta, idx);
    if (cur != prev) flags |= 4;
    s32 b2 = flags & 2;
    flags &= 6;
    if (flags != 0) {
        char *x = *(char **)(p2 + 0x16C);
        s32 changed = 1;
        *(char **)(p2 + 0x12C) = x;
        VEntry2 *v = (VEntry2 *)(*(char **)x + 0x178);
        v->fn(x + v->delta, p2, b2 != 0, 0);
        *out = changed;
        result = 1;
    }
    return result;
}
