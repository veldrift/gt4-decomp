typedef int s32;

extern "C" void func_003C0D58(void *arg0, s32 arg1, s32 arg2);
extern "C" void func_003C0DB8(void *arg0, s32 arg1, s32 arg2);

extern s32 D_00622F4C;

extern "C" void func_0010F770(void *arg0) {
    s32 *g = &D_00622F4C;

    func_003C0D58(arg0, *(s32 *)((*g + 0x40000) - 0x6224), 0);
    func_003C0DB8(arg0, *(s32 *)((*g + 0x40000) - 0x621C), 0);
}
