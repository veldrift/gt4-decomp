/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Item {
    char pad0[4];
    f32 f4;
    s32 i8;
};

struct Holder {
    s32 pad0[2];
    s32 h8;
};

struct Handle {
    Holder *obj;
};

struct Self {
    char pad0[8];
    s32 unk8;
};

extern "C" void func_0021B340(void *, s32);
extern "C" void func_0021B528(void *, f32, f32);
extern "C" void func_00427698(s32);
extern "C" void func_00427820(void *);
extern "C" void GT4_Motion__MotionSetPlayer__set(void *, s32, s32);
extern "C" void func_00428AD8(void *, s32, s32, s32, f32, f32);
extern "C" f32 func_0042A100(void *, s32);
extern "C" f32 func_0042A190(void *, s32);
extern "C" s32 ModelSet2__texLOD(s32);
extern "C" s32 ModelSet2__texLevel(s32);
extern "C" void func_00456918(f32);
extern "C" void func_004A1638(s32);
extern "C" void func_004A19B0(s32);
extern "C" void pglFrontFace(s32);
extern "C" void func_004AB040(s32);

extern "C" void mModelSetPS2__virtual_10(Self *self, Handle *h, s32 arg2) {
    char buf[0x10];
    s32 s0;
    Item *it;
    f32 f20;
    s0 = h->obj->h8;
    if (self->unk8 == 0 || s0 == 0) {
        func_0021B340(h, 2);
        return;
    }
    func_00427698(s0);
    func_00427820(buf);
    GT4_Motion__MotionSetPlayer__set(buf, self->unk8, s0);
    it = (Item *)((char *)h->obj + 0x10);
    f20 = func_0042A100(buf, it->i8);
    func_0021B528(it, f20, func_0042A190(buf, it->i8));
    func_00456918(1.0f);
    ModelSet2__texLOD(1);
    ModelSet2__texLevel(0);
    func_004A1638(0xF);
    pglFrontFace(arg2 != 0);
    func_004A19B0(2);
    func_00428AD8(buf, it->i8, 0, 0, it->f4, 0.0f);
    func_004AB040(0xF);
    func_0021B340(h, 2);
}
