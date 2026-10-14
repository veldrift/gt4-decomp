typedef int s32;
typedef float f32;

struct Inner {
    char pad0[0x18];
    s32 unk18;
};

struct Outer {
    char pad0[0x10];
    struct Inner *unk10;
};

extern "C" void func_003FCE70(f32 *self);
extern "C" void func_003FCEA8(f32 *self, f32 *position, void *other, f32 time);
extern "C" void func_003FD0A0(f32 *self, f32 *position, void *other, f32 time);
extern "C" void func_005F5040(f32 *self, f32 *out);

extern "C" s32 func_0037FA38(struct Outer *arg0, f32 *arg1, f32 *arg2) {
    f32 self[8];
    f32 a[4];
    f32 b[4];
    f32 *pa;
    f32 *pb;
    s32 r;
    s32 other;

    r = 0;
    if (arg0->unk10 != 0) {
        pa = a;
        pb = b;
        other = arg0->unk10->unk18;
        func_003FCE70(self);
        func_005F5040(arg1, pa);
        func_003FD0A0(self, pa, (void *)other, 0.0f);
        func_003FCEA8(self, pa, (void *)other, 1.0f);
        func_005F5040(arg2, pb);
        func_003FD0A0(self, pb, (void *)other, 0.0f);
        func_003FCEA8(self, pb, (void *)other, 1.0f);
        func_005F5040(pa, arg1);
        func_005F5040(pb, arg2);
        r = 1;
    }
    return r;
}
