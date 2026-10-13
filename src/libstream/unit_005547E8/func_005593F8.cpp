typedef int s32;
typedef short s16;

extern "C" void func_00576100(s32 a0);
extern "C" void func_00576140(s32 a0);
extern char D_00655340[];

struct Obj {
    char pad[0x3C];
    s32 f3C;
    s32 f40;
    s32 f44;
    s32 f48;
    s16 f4C;
    s16 f4E;
    s32 f50;
};

extern "C" void func_005593F8(Obj *arg0, s32 arg1) {
    s32 lock = (s32)D_00655340;
    func_00576100(lock);
    arg0->f3C = arg1;
    arg0->f40 = 0x1000;
    arg0->f44 = 0x3FFF;
    arg0->f48 = 0xC8;
    arg0->f4C = 0;
    arg0->f4E = 0;
    arg0->f50 = 0;
    func_00576140(lock);
}
