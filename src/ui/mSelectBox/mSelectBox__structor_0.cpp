/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
extern "C" void func_00206858(void *, s32);
extern "C" void mScrollable__structor_0(void *);
extern "C" void func_002F9B08(void *, s32 *);
extern char mSelectBox__vtable[];
struct Sub {
    s32 a0, a4, a8, aC, a10;
};
struct SB {
    char pad0[4];
    char *vt;
    char pad8[0xBC - 8];
    Sub sub;
    f32 unkD0;
    f32 unkD4;
    s32 unkD8;
    s32 unkDC;
    s32 unkE0;
    f32 unkE4;
    f32 unkE8;
    s32 unkEC;
    s32 unkF0;
    char unkF4[4];
};
extern "C" void mSelectBox__structor_0(SB *self) {
    mScrollable__structor_0(self);
    self->vt = mSelectBox__vtable;
    Sub *p = &self->sub;
    p->a0 = 0;
    p->a4 = 0;
    p->a8 = 1;
    p->aC = 1;
    p->a10 = 0;
    self->unkD0 = 0.2f;
    self->unkD4 = 1.0f;
    self->unkD8 = 0;
    self->unkDC = 0;
    self->unkE0 = 0;
    self->unkE4 = 16.0f;
    self->unkE8 = 16.0f;
    self->unkEC = 0;
    self->unkF0 = 0;
    s32 loc = 0;
    func_002F9B08(self->unkF4, &loc);
    func_00206858(self, 1);
}
