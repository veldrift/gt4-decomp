/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Item { char pad[0x1C]; s32 u1C; };
struct Obj {
    char pad0[0x30C0];
    s32 u30C0;
    s32 flags[0x30];
    struct { char b[0x80]; } ents[1];
};
extern "C" s32 func_00515998(void *, s32);
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" int func_005A4724(void *, s32, s32);
extern "C" void func_004FAAF8(struct Obj *self, s32 idx, s32 key) {
    Item *item = 0;
    if (func_00515998(&item, key) == 0 && item != 0 && item->u1C != 0) {
        func_00576100(self);
        func_005A4724((void *)((idx << 7) + (s32)self + 0x3184), item->u1C, self->u30C0);
        *(s32 *)((idx << 2) + (s32)self + 0x30C4) = 1;
        func_00576140(self);
    }
}
