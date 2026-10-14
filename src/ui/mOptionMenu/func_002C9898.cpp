typedef int s32;
struct S;
extern "C" void func_002C8198(S *arg0, s32 arg1);
extern "C" s32 func_002C9740(S *arg0, s32 arg1);
extern "C" void func_0057CE40(char *arg0, s32 arg1);

extern "C" void func_002C9898(S *arg0, s32 arg1, s32 arg2) {
    s32 r = func_002C9740(arg0, arg2);
    if (r >= 0) {
        func_0057CE40((char *)arg0 + 0xD8, r);
    }
    if (arg1 != 0) {
        func_002C8198(arg0, arg1);
    }
}
