typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

extern char D_00520968[];
extern "C" s32 func_00520970(s32 arg0, s32 arg1, s32 *arg2);
extern "C" s32 func_005AD980(s32 arg0, char *arg1, s32 arg2);

extern "C" s32 func_005202F0(s32 *arg0) {
    s32 v;
    char *tbl;

    v = 2;
    if (arg0 != 0) {
        tbl = D_00520968;
        func_00520970(0, func_005AD980(0, tbl, -1), arg0);
        func_00520970(1, func_005AD980(1, tbl, -1), arg0);
        func_00520970(2, func_005AD980(2, tbl, -1), arg0);
        func_00520970(3, func_005AD980(3, tbl, -1), arg0);
        func_00520970(4, func_005AD980(4, tbl, -1), arg0);
        func_00520970(5, func_005AD980(5, tbl, -1), arg0);
        func_00520970(6, func_005AD980(6, tbl, -1), arg0);
        func_00520970(7, func_005AD980(7, tbl, -1), arg0);
        func_00520970(8, func_005AD980(8, tbl, -1), arg0);
        func_00520970(9, func_005AD980(9, tbl, -1), arg0);
        func_00520970(0xA, func_005AD980(0xA, tbl, -1), arg0);
        v = 0;
    }
    return v;
}
