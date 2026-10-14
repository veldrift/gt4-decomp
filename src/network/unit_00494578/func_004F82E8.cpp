/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj {
    char pad0[0x3F44];
    s32 unk3F44;
    char a[0x20];
    s32 unk3F68;
    char b[0x30];
    s32 unk3F9C;
    s32 unk3FA0;
    s32 unk3FA4;
    s32 unk3FA8;
};
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_004F82E8(Obj *arg0) {
    arg0->unk3F44 = 0;
    arg0->unk3F68 = 0;
    arg0->unk3F9C = 0;
    arg0->unk3FA0 = -2;
    arg0->unk3FA4 = -2;
    arg0->unk3FA8 = -2;
    func_005A48D8(arg0->a, -1, 0x20);
    func_005A48D8(arg0->b, -1, 0x30);
}
