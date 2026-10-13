typedef int s32;

struct func_003B4F18_arg1;

extern int D_00646450;
extern "C" void func_003B4F18(void *arg0, struct func_003B4F18_arg1 *arg1);
extern "C" void func_005F31C0(void *arg0, int arg1);

extern "C" void func_00338790(void *arg0, void *arg1)
{
    s32 t = *(s32 *)((char *)arg1 + 0x14);
    if (t >= 0 && t < D_00646450) {
        func_003B4F18(arg1, (struct func_003B4F18_arg1 *)((char *)arg0 + t * 0x190 + 0x130));
        *(s32 *)((char *)arg1 + 0x198) = ((t ^ *(s32 *)((char *)arg0 + 0xAB8)) != 0) ? 0 : 0x100;
        return;
    }
    func_005F31C0(arg0, t);
}
