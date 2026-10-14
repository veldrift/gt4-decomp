/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned int u32;

struct VEntry1 {
    s16 delta;
    s16 index;
    s32 (*fn)(char *self, s32 idx);
};

struct VEntry2 {
    s16 delta;
    s16 index;
    void (*fn)(char *self, char *p);
};

static inline s32 changed(s32 c, u32 flags) {
    if (flags & 2) c = 1;
    if (flags & 4) c = 1;
    return c;
}

extern "C" s32 func_00377968(char *self, s32 a1, s32 a2, s32 idx, u32 flags, s32 *out)
{
    char *p = self + idx * 0x19C;
    char *p2 = p + 0x10;
    VEntry1 *e = (VEntry1 *)(*(char **)self + 0xD8);
    s32 s1 = *(s32 *)(p2 + 0x15C);
    s32 c = 0;
    s32 r = e->fn(self + e->delta, idx);
    if (r != s1) c = 1;
    if (flags & 2) c = 1;
    if (flags & 4) c = 1;
    if (!c) return 0;
    if (c) {
        VEntry2 *v = (VEntry2 *)(*(char **)s1 + 0x138);
        v->fn((char *)s1 + v->delta, p2);
        *(s32 *)(p2 + 0x12C) = s1;
        *out = 1;
        return 0;
    }
    return 0;
}
