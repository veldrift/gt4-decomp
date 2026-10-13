typedef int s32;

struct S004EF708;

extern "C" s32 func_004EF898(struct S004EF708 *arg0, s32 arg1, s32 arg2);

extern "C" s32 func_004EEB88(s32 *arg0, s32 arg1, s32 arg2) {
    if (*arg0 == 0) return -1;
    return func_004EF898((struct S004EF708 *)arg0, arg1, arg2);
}
