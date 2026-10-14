typedef int s32;
typedef short s16;
typedef void (*VFn208160)(void *, void *);
struct VEntry208160 { s16 delta; s16 index; VFn208160 fn; };
struct Obj208160 { char p0[4]; char *vt; };
struct Arg208160 { char p0[0x10]; void *p10; };
extern "C" void func_003285A8(void *arg0);
extern "C" void func_00206B80(void *self, void *n);
extern "C" void func_003285F8(void *arg0);

static inline void vcall208160(void *obj, s32 off, void *a) {
    struct VEntry208160 *e = (struct VEntry208160 *)(((struct Obj208160 *)obj)->vt + off);
    VFn208160 fn = e->fn;
    fn((char *)obj + e->delta, a);
}

extern "C" void mPhotoMapWindow__virtual_102(void *arg0, void *arg1, void *arg2) {
    func_003285A8(arg2);
    func_00206B80(arg0, arg2);
    if (arg1 != 0) {
        vcall208160(arg2, 0x2D8, arg1);
        vcall208160(arg2, 0x2C8, ((struct Arg208160 *)arg1)->p10);
        vcall208160(arg2, 0x2B8, ((struct Arg208160 *)arg1)->p10);
    }
    func_003285F8(arg2);
}
