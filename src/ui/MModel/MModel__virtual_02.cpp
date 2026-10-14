/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct S {
    s32 mode;
    char pad4[0xC];
    f32 m10;
    f32 m14;
    f32 m18;
    f32 m1C;
    f32 m20;
    f32 m24;
    char m28[1];
};

extern "C" S *func_0021A798(void *) throw();
extern "C" void func_004A7698(void *);
extern "C" void func_004A7844(f32, f32, f32);
extern "C" void func_004A7988(f32);
extern "C" void func_004A79B0(f32);
extern "C" void func_004A79D8(f32);

extern "C" void MModel__virtual_02(void *self) {
    S *s = func_0021A798(self);
    switch (s->mode) {
    case 0:
        func_004A79B0(-s->m20);
        func_004A7988(-s->m1C);
        func_004A79D8(-s->m24);
        func_004A7844(-s->m10, -s->m14, -s->m18);
        break;
    case 1:
        func_004A7988(-s->m1C);
        func_004A79B0(-s->m20);
        func_004A79D8(-s->m24);
        func_004A7844(-s->m10, -s->m14, -s->m18);
        break;
    case 2:
        func_004A7698(s->m28);
        break;
    }
}
