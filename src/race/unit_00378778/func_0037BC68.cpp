/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef short s16;
typedef int s32;
typedef long long s64;

#define LO ((((-0x100LL << 0x10) | 0xFFFF) << 0x10) | 0xFFFF)

struct VEntry { s16 delta; s16 index; void *(*fn)(void *); };
struct Inner { char pad0[8]; VEntry *vtbl; };
struct Mid { char pad0[0x2880]; Inner *unk2880; };
struct Rec { char pad0[0x1C]; s32 flags; };
struct Res { char pad0[0x40]; s32 count; Rec *arr; };
struct Obj {
    char pad0[0x180];
    s32 m180;
    char pad1[0x18C - 0x184];
    Mid *m18C;
    char pad2[0x268 - 0x190];
    s64 m268;
};

extern "C" void func_0037BC68(Obj *self, s32 step, s32 mask) {
    s32 cnt0 = step != 0;
    self->m268 = self->m268 & LO;
    s32 idx = self->m180 + step;
    self->m180 = 0;
    if (self->m18C != 0) {
        Inner *in = self->m18C->unk2880;
        VEntry *e = (VEntry *)((char *)in->vtbl + 0x50);
        Res *r = (Res *)e->fn((char *)in + e->delta);
        s32 n = r->count;
        if (n > 0) {
            s32 cnt = cnt0;
            if (cnt < n) {
                for (; cnt < n; cnt++, idx += step) {
                    if (idx == 0x14) {
                        self->m180 = idx;
                        self->m268 = (self->m268 & LO) | (0x8000LL << 0x11);
                        return;
                    }
                    if (idx == 0x19) {
                        self->m180 = idx;
                        self->m268 = self->m268 & LO;
                        return;
                    }
                    if (idx < 0)
                        idx = n - 1;
                    if (idx >= n)
                        idx = 0;
                    Rec *rec = r->arr + idx;
                    if ((rec->flags & mask) == 0) {
                        if (mask != 0) {
                            continue;
                        }
                    }
                    self->m180 = idx;
                    self->m268 = (self->m268 & LO) | ((s64)((rec->flags >> 1) & 1) << 0x20);
                    return;
                }
            }
        }
    }
}
