/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj {
    char pad0[0x64];
    char *vt;
    char pad68[4];
    s32 *p6C;
    char pad70[4];
    f32 f74;
    s32 n78;
    s32 n7C;
    s32 n80;
    s32 n84;
    s32 n88;
};
extern "C" void func_00101538(int);
extern "C" void func_00109048(Obj *, s32, f32) throw();
extern "C" s32 func_004A7C60(void);
extern s32 D_006186F4;

extern "C" void func_00109080(Obj *self) {
    if (func_004A7C60() == 4) {
        if (self->n7C != 0) {
            self->n7C--;
            self->f74 = 1.0f - (f32)self->n7C / (f32)self->n78;
            return;
        }
        if (self->n80 != 0) {
            self->n80--;
            self->f74 = 1.0f;
            return;
        }
        s32 a1 = *self->p6C;
        if (a1 != -1 || D_006186F4 == 0) {
            if (self->n88 != 0) {
                self->n88--;
                self->f74 = (f32)self->n88 / (f32)self->n84 + 0.0f;
                return;
            }
            if (a1 != -1) {
                func_00109048(self, a1, 3.0f);
                self->p6C = self->p6C + 1;
            } else {
                VEntry *e = (VEntry *)(self->vt + 0x48);
                e->fn((char *)self + e->delta);
                func_00101538(0);
            }
        }
    }
}
