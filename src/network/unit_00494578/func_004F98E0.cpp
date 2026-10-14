/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Item { u8 u0; char pad1[7]; s32 w8; char pad0C[0x10]; s32 u1C; };
extern "C" void func_004F8820(void *, s32) throw();
extern "C" void func_004F9BD8(void *, s32, s32, s32, s32);
extern "C" s32 func_005157D0(s32 *, s32, s32, s32, s32, s32, s32, s32, char *, s32);
extern "C" s32 func_00515998(Item **, s32);
extern "C" s32 func_00515A08(s32);
extern "C" void func_00515A68(s32);
extern "C" s32 func_004F98E0(char *self, char *arg1, int arg2, int arg3) {
    Item *item;
    s32 id;
    s32 r = func_005157D0(&id, 1, 3, 0, 0, 0, 0, 0, arg1, *(int *)(self + arg2 * 4 + 0xCCC));
    if (r) {
        func_004F8820(self, r);
        return 0;
    }
    r = func_00515A08(id);
    if (r) {
        func_004F8820(self, r);
        func_00515A68(id);
        return 0;
    }
    r = func_00515998(&item, id);
    if (r) {
        func_00515A68(id);
        return 0;
    }
    if (item == 0) {
        func_00515A68(id);
        return 0;
    }
    *(int *)(self + arg3 * 4 + 0xCC0) = id;
    func_004F9BD8(self, id, item->w8, item->u0, item->u1C);
    return 1;
}
