typedef int s32;

struct Resource;

extern "C" void func_004A5688(void *self);
extern "C" void func_001055C0(Resource *self);
extern "C" void func_004AA4A0(void);
extern "C" void func_00497EF8(char *self, s32 arg1);

extern "C" void func_003B8848(char *arg0) {
    func_004A5688(arg0);
    func_001055C0((Resource *)(arg0 + 0xC8));
    s32 v = *(s32 *)(arg0 + 0x8);
    *(s32 *)(arg0 + 0xA08) = v;
    if (v == 0 && *(s32 *)(arg0 + 0xA34) == 0 && *(s32 *)(arg0 + 0x1848) == 0) {
        return func_001055C0((Resource *)(arg0 + 0x8C));
    }
    func_004AA4A0();
    func_00497EF8(arg0, *(s32 *)(arg0 + 0x104));
    func_001055C0((Resource *)(arg0 + 0x8C));
}
