/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
typedef float f32;

struct Elem {
    char pad0[0x64];
    u16 flags;
    u16 index;
    f32 scale;
    char pad6C[0x4];
};

struct Group {
    char pad0[0x18];
    s32 count0;
    Elem *elems0;
    s32 count2;
    Elem *elems2;
    s32 count1;
    Elem *elems1;
};

struct Params {
    char pad0[0x1794];
    f32 unk1794;
    f32 unk1798;
    f32 unk179C;
};

struct Info {
    char pad0[0x80];
};

struct InfoHolder {
    char pad0[0x4];
    Info *info;
};

struct Car {
    char pad0[0x8];
    InfoHolder *holder;
};

struct Sub18 {
    char pad0[0x3C];
    f32 unk3C;
};

struct VEntry {
    short delta;
    short index;
    Group *(*fn)(void *);
};

struct VEntryF {
    short delta;
    short index;
    void (*fn)(void *, f32);
};

struct RaceCarModel {
    char pad0[0x4];
    Car *car;
    char *vtbl;
    char padC[0xC];
    Sub18 unk18;
    char pad58[0x1680 - 0x58];
    s32 unk1680;
};

/* The base class at offset 8 (its vtable pointer is RaceCarModel's); per-index factors. */
struct Base8 {
    char pad0[0x1670];
    f32 arr[1];
};

struct Vec4 {
    f32 v[4];
};

extern "C" s32 func_003446B8(Car *);
extern "C" s32 func_004515B0(Sub18 *);
extern "C" s32 Automobile__getDrawMode(Car *);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" Vec4 *func_003917D8(void);
extern "C" f32 func_003916E0(Vec4 *, f32, f32);
extern "C" void func_003B8EA0(void *, Elem *, f32);

extern "C" void RaceCarModel__virtual_36(RaceCarModel *self, void *drawer, f32 arg3) {
    s32 hasX;
    Sub18 *sub;
    Group *g;
    s32 notY;
    s32 n;
    s32 i;

    if (self->unk1680 == 0) {
        return;
    }
    sub = &self->unk18;
    hasX = func_003446B8(self->car) != 0;
    {
        VEntry *e = (VEntry *)(self->vtbl + 0x50);
        g = e->fn((char *)self + e->delta);
    }
    notY = func_004515B0(sub) ^ 1;
    func_004A53F8();
    {
        VEntryF *e = (VEntryF *)(self->vtbl + 0x108);
        e->fn((char *)self + e->delta, arg3);
    }
    {
        n = g->count0;
        for (i = 0; i < n; i++) {
            Elem *el = &g->elems0[i];
            u16 idx = el->index;
            if (idx != 0) {
                Vec4 *t = func_003917D8();
                f32 s = func_003916E0(&t[idx - 1], ((Base8 *)((char *)self + 8))->arr[idx - 1], el->scale);
                func_003B8EA0(drawer, el, s);
            } else {
                func_003B8EA0(drawer, el, 1.0f);
            }
        }
    }
    {
        f32 k = sub->unk3C;
        if (0.0f < k) {
            n = g->count1;
            for (i = 0; i < n; i++) {
                Elem *el = &g->elems1[i];
                if (notY && (el->flags & 2)) {
                    continue;
                }
                if (el->flags & 1) {
                    func_003B8EA0(drawer, el, k);
                } else if (hasX) {
                    func_003B8EA0(drawer, el, 1.0f);
                }
            }
        }
        n = g->count2;
        for (i = 0; i < n; i++) {
            Elem *el = &g->elems2[i];
            if (notY && (el->flags & 2)) {
                continue;
            }
            func_003B8EA0(drawer, el, 0.3f);
        }
    }
    func_004A5400();
}
