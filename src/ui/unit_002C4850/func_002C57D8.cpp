typedef int s32;
typedef short s16;
typedef float f32;

struct VE2C57D8 { s16 delta; s16 index; void *fn; };
struct Obj2C57D8 { char p0[4]; char *vt; };
struct Arg2C57D8 { char p0[8]; s32 w8; char p1[8]; void *w14; void *w18; };

extern "C" void func_00231508(s32 arg0, void *arg1);
extern "C" void func_00231798(s32 arg0, void *arg1);
extern "C" void func_0025BA68(void *arg0, f32 arg1, f32 arg2);
extern "C" void func_00266830(void *arg0, s32 arg1);

extern "C" void func_002C57D8(void *arg0, s32 arg1, f32 fparg0, f32 fparg1) {
    struct Arg2C57D8 *s = (struct Arg2C57D8 *)arg0;
    struct Obj2C57D8 *o;
    struct VE2C57D8 *e;
    if (s->w8 != 0) {
        if (arg1 != 0) {
            o = (struct Obj2C57D8 *)s->w18;
        } else {
            o = (struct Obj2C57D8 *)s->w14;
        }
        func_00266830(o, 0);
        func_0025BA68(o, fparg0, fparg1);
        func_00231508(s->w8, o);
        e = (struct VE2C57D8 *)(o->vt + 0x2E8);
        ((void (*)(void *, s32))e->fn)((char *)o + e->delta, s->w8);
        func_00231798(s->w8, o);
    }
}
