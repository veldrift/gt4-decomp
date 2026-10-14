/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
struct Obj { char pad0[0x10]; u32 unk10; };
extern "C" void func_004C3DA0(Obj *, u32) throw();
extern "C" void func_004C3E50(Obj *arg0, u32 arg1) {
    if (arg1 != 0) {
        u32 d = arg1 - arg0->unk10;
        if ((d & 7) == 0) {
            return func_004C3DA0(arg0, ((d >> 3) - 1) & 0xFFFF);
        }
    }
}
