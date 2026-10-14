/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;
struct O { char pad[0xC4]; f32 c4; char pad2[0xEC - 0xC8]; f32 ec; char pad3[0x100 - 0xF0]; s32 f100; s32 f104; };
extern "C" void func_002306D0(void *, int);
extern "C" s32 func_00231F60(void *, s32);
extern "C" void func_00238978(void *, void *) throw();
extern "C" void func_00238A10(void *, void *) throw();
extern "C" void func_00238FC0(void *, f32);
extern "C" void func_00238FF0(void *, f32);
extern "C" void func_0023DDF0(void *, int);
extern "C" void func_0023F8C8(s32, const char *);
extern "C" void func_0023FB80(void *);

extern "C" void func_00238C60(O *arg0, void *arg1) {
    s32 sp[4];
    func_0023FB80(sp);
    func_0023F8C8(sp[0], "cursor");
    func_0023DDF0(sp, 2);
    if (arg0->f104 != 0) {
        arg0->c4 = arg0->ec;
        func_00238FC0(arg0, arg0->c4);
        func_00238FF0(arg0, arg0->c4);
        func_00238978(arg0, arg1);
        func_00238A10(arg0, arg1);
    }
    arg0->f100 = 0;
    func_002306D0(arg1, 1);
    func_00231F60(arg1, 0);
}
