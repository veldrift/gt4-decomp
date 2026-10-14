/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(char *);
};

extern "C" void func_00456828(float);
extern "C" void func_004A2980(s32);
extern "C" void func_004A29A8(s32);
extern "C" void func_004AA4A0(void);

extern "C" void func_0033E8E0(char *arg0) {
    char *s0 = *(char **)(*(char **)(*(char **)(*(char **)(arg0 + 0x6C) + 0x80) + 4) + 0x80);
    *(s32 *)(arg0 + 0xE32C) = *(s32 *)(arg0 + 0xE32C) + 1;
    VEntry *e = (VEntry *)(*(char **)(arg0 + 0x64) + 0x3D0);
    e->fn(arg0 + e->delta);
    func_00456828(*(float *)(s0 + 0x50));
    func_004A2980(-1);
    func_004A29A8(1);
    func_004AA4A0();
}
