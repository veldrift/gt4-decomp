/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct V3 { f32 x, y, z; };

struct Obj {
    char pad0[4];
    void *vt;
    char pad8[0xC0 - 8];
    s32 fC0, fC4, fC8, fCC, fD0, fD4, fD8, fDC, fE0;
    char fE4[0xE8 - 0xE4];
    s32 fE8, fEC, fF0;
    f32 fF4;
    s32 fF8;
    s32 fFC[2];
    s32 f104[2];
    s32 pad10C_[0];
    s32 f10C;
    s32 f110;
    f32 f114;
    f32 f118;
    f32 f11C;
    s32 f120;
    f32 f124;
    s32 f128, f12C, f130;
    V3 v134;
    V3 v140;
    V3 v14C;
    V3 v158;
};

extern char mPhotoMapWindow__vtable[];
extern "C" Obj *mBox__structor_0(Obj *);
extern "C" void func_002F9B08(void *, s32 *);
extern "C" void func_005A48D8(void *, int, unsigned int);

extern "C" void mPhotoMapWindow__structor_0(Obj *self) {
    s32 loc;
    mBox__structor_0(self);
    self->fC0 = 0;
    self->fC4 = 0;
    self->vt = mPhotoMapWindow__vtable;
    self->fC8 = 0;
    self->fCC = 0;
    self->fD0 = 0;
    self->fD4 = 0;
    self->fD8 = 0;
    self->fDC = 0;
    self->fE0 = 0;
    loc = 0;
    func_002F9B08(self->fE4, &loc);
    self->fE8 = 0;
    self->fEC = 0;
    self->fF4 = 70.0f;
    self->fF0 = 0;
    self->fF8 = 0;
    func_005A48D8(self->fFC, 0, 8);
    func_005A48D8(self->f104, 0, 8);
    self->f10C = 1;
    self->f110 = 0;
    V3 *q0 = &self->v134;
    V3 *q1 = &self->v140;
    V3 *q2 = &self->v14C;
    V3 *q3 = &self->v158;
    f32 z = *(f32 *)&self->f110;
    self->f114 = 7.5f;
    self->f11C = 10.0f;
    self->f118 = z;
    self->f120 = 0;
    self->f124 = z;
    self->f128 = 0;
    self->f12C = 0;
    self->f130 = 0;
    q0->x = z;
    q0->y = z;
    q0->z = z;
    q1->x = z;
    q1->y = z;
    q1->z = z;
    q2->x = z;
    q2->y = z;
    q2->z = z;
    q3->x = z;
    q3->y = z;
    q3->z = z;
    for (s32 i = 0; i < 2; i++) {
        self->fFC[i] = 0;
        self->f104[i] = 0;
    }
}
