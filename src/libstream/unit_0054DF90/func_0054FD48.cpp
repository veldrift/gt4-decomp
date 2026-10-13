typedef int s32;

struct func_00564988_a0;
extern "C" s32 func_00564990(struct func_00564988_a0 *a0);

extern "C" s32 D_0064C4C4;

struct func_0054FD48_a0 {
    char pad[0xC];
    struct func_00564988_a0 *child;
};

extern "C" s32 func_0054FD48(struct func_0054FD48_a0 *a0) {
    if (D_0064C4C4 == 0) return 0;
    return func_00564990(a0->child);
}
