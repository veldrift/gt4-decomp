struct Obj { char p0[4]; void *f4; char p8[0x14]; int f1C; char p20[0x5C - 0x20]; float f5C[1]; };
extern "C" void func_001D5588(Obj *self, int arg1, float fparg0);

extern "C" void func_001D5B08(Obj *self) {
    int i;
    for (i = 0; i < self->f1C; i++) {
        if (self->f5C[i] != 0.0f) {
            func_001D5588((Obj *)self->f4, i, self->f5C[i]);
        }
    }
}
