typedef int s32;

struct Obj {
    char pad0[0x14];
    s32 active;
    char pad18[0x60 - 0x18];
    void *map;
};

extern "C" s32 func_005657E0(void *o, s32 i, s32 *out);

extern "C" void func_00566F90(Obj *self, s32 value) {
    s32 index;
    if (self->active != 0 && func_005657E0(self->map, value, &index) == 0) {
        if (*(s32 *)(index * 8 + (int)self + 0x6C) == 2) {
            *(s32 *)(index * 8 + (int)self + 0x6C) = 1;
        }
    }
}
