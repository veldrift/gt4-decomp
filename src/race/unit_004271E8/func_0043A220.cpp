typedef int s32;
struct Obj { char pad[0x40]; char buf[0x40]; };
extern "C" void func_005A6AB0(void *, const void *, s32);
extern "C" void func_005A6900(void *, const void *, s32);
extern "C" s32 func_00447C50(s32);
extern char D_0068BB20[];
extern char D_006A6288[];
extern char D_006A6290[];

static inline void setName(Obj *self, char *name) {
    if (*name == 0) {
        self->buf[0] = 0;
        return;
    }
    char *b = self->buf;
    func_005A6AB0(b, name, 0x40);
    s32 a = func_00447C50((s32)b);
    if (a == -1) {
        func_005A6AB0(b, D_0068BB20, 0x40);
        func_005A6900(b, name, 0x40);
        s32 c = func_00447C50((s32)b);
        if (c == a) {
            func_005A6AB0(b, D_006A6288, 0x40);
            func_005A6900(b, name, 0x40);
            if (func_00447C50((s32)b) == c)
                func_005A6AB0(b, D_006A6290, 0x40);
        }
    }
}

extern "C" void func_0043A220(Obj *self, char *name) {
    setName(self, name);
}
