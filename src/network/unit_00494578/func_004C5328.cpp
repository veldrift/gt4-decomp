/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned u32;
extern "C" s32 func_004C9330(u8 *);
extern "C" u16 D_006B9980[];
extern "C" u16 D_006B9998[];
extern "C" void func_004C5328(u16 *arg0, u8 *arg1, s32 arg2, u32 arg3) {
    u8 *p;
    u16 *table;
    if (arg3 >= (u32)((func_004C9330(arg1) * 2) + 2)) {
        if (arg2 == 12) table = D_006B9980;
        else table = D_006B9998;
        p = arg1;
        if (*p != 0) {
            do {
                u8 c = *p;
                p++;
                s32 index = c - 0x30;
                *arg0 = *(u16 *)(index * 2 + (u32)table);
                arg0++;
            } while (*p != 0);
        }
    }
    *arg0 = 0;
}
