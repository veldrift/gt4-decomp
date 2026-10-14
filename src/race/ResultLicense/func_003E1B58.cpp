typedef int s32;

extern "C" char D_006A38F8[];
extern "C" void func_00454410(void *self);
extern "C" s32 func_00454580(void *arg0);
extern "C" void func_004AE230(char *self, const char *path, int mode);

extern "C" void func_003E1B58(char *arg0) {
    char loc[0x14];
    void *res;

    if (*(void **)(arg0 + 0x578) == 0) {
        func_004AE230(loc, D_006A38F8, 1);
        res = *(void **)(loc + 0x10);
        *(void **)(arg0 + 0x578) = res;
        if (res != 0) {
            if (func_00454580(res) != 0) {
                func_00454410(*(void **)(arg0 + 0x578));
            }
        }
    }
}
