typedef int s32;

struct S {
    char pad0[0x15C];
    s32 unk15C;
};

extern "C" void func_0021D978(void *arg0, int arg1);
extern "C" void func_0021D9D0(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" int func_002FE250(S *arg0);

extern "C" void MMovieFace__setUnUpdate(void *arg0, void *arg1, int count, void *name)
{
    s32 sp[4];
    s32 flag = 1;

    if (count > 0) {
        func_002FC8C8(sp, name);
        flag = func_002FE250((S *)sp[0]) != 0;
        func_002FC870(sp, 2);
    }
    func_0021D9D0(sp, arg1);
    ((S *)sp[0])->unk15C = flag;
    func_0021D978(sp, 2);
}
