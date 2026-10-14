typedef int s32;
struct Obj {
    char pad0[4];
    s32 f4;
    char f8[0x1D8];
    void *f1E0;
    void *f1E4;
};
extern "C" void *exception__structor_0(s32);
extern "C" void func_00449B78(void *);
extern "C" s32 func_00449C08(void *, void *);
extern "C" s32 func_00449C58(void *, void *, s32, s32);
extern "C" int func_00575E60(int, int);
extern "C" void func_005A5DC8(void *, const char *);
extern "C" char *func_005A609C(char *, const char *);
extern "C" s32 func_00443CD0(Obj *, char *, const char *);
extern char D_006A6D68[];
extern char D_006A6D30[];
extern char *D_00623580[];

extern "C" s32 func_00443B50(Obj *self) {
    char buf[0x100];
    char *name = self->f8;
    void *p = exception__structor_0(12);
    func_00449B78(p);
    self->f1E0 = p;
    func_005A609C(buf, name);
    func_005A5DC8(buf, D_006A6D68);
    s32 r = func_00449C08(self->f1E0, buf);
    func_005A609C(buf, name);
    func_005A5DC8(buf, D_00623580[self->f4]);
    void *q = exception__structor_0(12);
    func_00449B78(q);
    self->f1E4 = q;
    func_005A5DC8(buf, D_006A6D30);
    s32 n = func_00443CD0(self, name, D_006A6D30);
    return r + func_00449C58(self->f1E4, buf, func_00575E60(0x40, n), n);
}
