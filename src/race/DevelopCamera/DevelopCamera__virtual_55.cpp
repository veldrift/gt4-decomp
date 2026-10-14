typedef int s32;
typedef float f32;

struct Entry { short delta, index; s32 (*fn)(void *, s32); };
struct Out {
    char pad0[4];
    s32 i4;
    f32 f8, fC, f10, f14, f18, f1C;
};
struct Item { char pad[0x18]; s32 i18; };
struct Cam {
    Entry *vt;
};

extern "C" void func_001C5D70(Out *);
extern "C" s32 func_003741A0(f32, f32) throw() __attribute__((const));
extern "C" void func_00374B58(Cam *, s32, f32 *, s32, f32, f32, f32);

extern "C" Out *DevelopCamera__virtual_55(Cam *self) {
    f32 v[4];
    s32 idx = *(s32 *)((char *)self + 0x9BC);
    Out *out = *(Out **)((char *)self + 0xC14);
    Item *item = *(Item **)((char *)self + idx * 0x19C + 0x20);
    func_001C5D70(out);
    if (item != 0) {
        s32 i18 = item->i18;
        Entry *e = (Entry *)((char *)self->vt + 0xD8);
        func_00374B58(self, e->fn((char *)self + e->delta, idx), v, i18, 0x1.333332p-3f, 0x1.999998p+0f, 1.4f);
        f32 a = v[0];
        f32 d = v[1];
        f32 b = v[2];
        f32 c = v[3];
        bool r0 = false;
        if (func_003741A0(a, d) == 0) r0 = true;
        if (func_003741A0(b, c) == 0) r0 = true;
        if (r0 == 0) {
            if (a <= -1.0f) a = -1.0f;
            if (a >= 1.0f) a = 1.0f;
            if (d <= -1.0f) d = -1.0f;
            if (d >= 1.0f) d = 1.0f;
            if (b <= -1.0f) b = -1.0f;
            if (b >= 1.0f) b = 1.0f;
            if (c <= -1.0f) c = -1.0f;
            if (c >= 1.0f) c = 1.0f;
            out->i4 = 3;
            out->f10 = a;
            out->f14 = b;
            out->f18 = d;
            out->f1C = c;
            out->f8 = (a + d) * 0.5f;
            out->fC = (b + c) * 0.5f;
        }
    }
    return out;
}
