typedef int s32;

extern char D_001CA348[];
extern char D_0068BAE8[];

extern "C" s32 func_005C1CE0(void *);

struct Frame_001CA648 {
    void *m0;
    void *m4;
    char *m8;
    s32 mC;
    s32 m10;
    s32 m14;
};

struct Obj_001CA648 {
    char pad[0x54];
    s32 m54;
    s32 m58;
};

extern "C" void func_001CA648(void *arg0, s32 arg1, s32 arg2) {
    struct Obj_001CA648 *self = (struct Obj_001CA648 *)arg0;
    if (self->m54 == 0) {
        struct Frame_001CA648 f;
        f.m14 = arg1;
        f.m0 = D_001CA348;
        f.m8 = D_0068BAE8;
        f.m4 = arg0;
        f.mC = arg2;
        if (func_005C1CE0((void *)&f) == 0) {
            self->m58 = arg2;
            self->m54 = 1;
        }
    }
}
