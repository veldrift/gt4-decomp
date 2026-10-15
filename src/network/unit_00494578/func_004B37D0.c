/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

typedef struct Self { char *vtbl; s32 m4; s32 m8; char *mC; char m10[20]; } Self;
extern char D_00689418[];
extern char D_00851188[];
void *func_004B3B88(void *);
void func_004B3840(Self *, s32, s32);

void func_004B37D0(Self *self, s32 a, s32 b) {
    self->vtbl = D_00689418;
    self->m4 = 0;
    self->m8 = 0;
    self->mC = D_00851188;
    func_004B3B88(self->m10);
    func_004B3840(self, a, b);
}
