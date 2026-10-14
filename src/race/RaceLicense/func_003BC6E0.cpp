/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Org {
    char pad0[0x80];
    s32 unk80;
    char pad84[4];
    s32 unk88;
    char pad8C[0xF4 - 0x8C];
};

struct Ctl {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x38 - 0x18];
    f32 unk38;
};

struct Self {
    char pad0[0x6C];
    Org *unk6C;
    s32 unk70;
    char pad74[0xCF54 - 0x74];
    f32 unkCF54;
    char padCF58[0x24E88 - 0xCF58];
    f32 unk24E88, unk24E8C, unk24E90;
};

extern "C" s32 func_0034C190(s32, s32);
extern "C" s32 RaceEventQueue__get(void *, s32, s32 *, s32);
extern "C" void func_003FAB10(s32, f32, f32, f32, f32);
extern "C" void func_00409138(void *, s32);
extern "C" void func_00409168(void *, s32, s32, f32);
extern "C" s32 func_004097F8(void *);
extern "C" s32 func_00409828(void *);
extern "C" s32 func_00409860(void *);
extern "C" f32 func_00409878(void *);
extern "C" f32 func_00409888(void *);

extern "C" void func_003BC6E0(Self *self, f32 fp) {
    Ctl *c = (Ctl *)((char *)self + 0x24E5C);
    Org *org = self->unk6C;
    if (c->unk14 == 0) {
        s32 *p = &org->unk88;
        if (*p > 0) {
            func_00409138(c, 1);
        } else if (RaceEventQueue__get((char *)org + 0xF4, 10, 0, 0) != 0 && *p == 0) {
            func_00409138(c, 0);
        }
    }
    Ctl *c2 = (Ctl *)((char *)self + 0x24E5C);
    func_00409168(c2, self->unk70, self->unk6C->unk80, fp);
    if (func_00409860(c2) != 0) {
        func_003FAB10(func_0034C190(self->unk70, 0), self->unk24E88, self->unk24E8C, self->unk24E90, c2->unk38);
    }
    if (func_004097F8(c2) != 0) {
        self->unkCF54 = -1.0f / func_00409878(c2);
    }
    if (func_00409828(c2) != 0) {
        self->unkCF54 = 1.0f / func_00409888(c2);
    }
}
