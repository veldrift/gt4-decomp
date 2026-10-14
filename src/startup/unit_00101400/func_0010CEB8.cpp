typedef int s32;
struct Obj { char pad0[0x10]; s32 f10; };

extern "C" char D_00645570[];
extern "C" char D_00645440[];
extern "C" void func_004F0848(void *self);
extern "C" void func_004EF1F0(void *s);
extern "C" void func_004F0098(void);
extern "C" void func_001DC8F0(void *out);
extern "C" void func_001DC5F8(void *arg0, int arg1);

extern "C" void func_0010CEB8(void) {
    func_004F0848(D_00645570);
    func_004EF1F0(D_00645440);
    func_004F0098();
    void *buf[2];
    func_001DC8F0(buf);
    Obj *o = (Obj *)buf[0];
    o->f10 = 0;
    func_001DC5F8(buf, 2);
}
