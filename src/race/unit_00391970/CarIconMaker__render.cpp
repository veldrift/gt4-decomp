/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Pair { s32 a, b; };
struct Cnt { s32 count; };
struct Inner { char pad[0x60]; Cnt *f60; };
struct Obj {
    char pad0[0x6C]; s32 f6C; Pair *f70; Inner *f74; char pad78[4]; s32 f7C;
};
struct Local { char b[0x40]; };
extern "C" s32 func_001052E0(void *, s32, s32, s32);
extern "C" void func_001059F8(void *, s32, s32);
extern "C" void func_00105280(void *, s32);
extern "C" void func_00393D20(Obj *, s32, void *, s32, s32, s32);
extern "C" void CarIconMaker__render(Obj *self) {
    if (self->f7C == 0) {
        s32 i = 0;
        while (i < self->f74->f60->count && i < self->f6C) {
            Local loc;
            s32 off = i * 8;
            func_001052E0(&loc, 2, 0x60, 0x40);
            func_00393D20(self, i, &loc, 0x80, 0x40, 0);
            func_001059F8(&loc, ((Pair *)((char *)self->f70 + off))->a, 2);
            func_00105280(&loc, 2);
            func_001052E0(&loc, 2, 0x40, 0x20);
            func_00393D20(self, i, &loc, 0x40, 0x20, 1);
            func_001059F8(&loc, ((Pair *)((char *)self->f70 + off))->b, 2);
            func_00105280(&loc, 2);
            i++;
        }
        self->f7C = self->f7C + 1;
    }
}
