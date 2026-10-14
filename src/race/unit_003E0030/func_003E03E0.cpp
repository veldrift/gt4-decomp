/* func_003E03E0: formats a name into a buffer at arg0 + 4 (or + 0x24 when arg3 == 0),
 * optionally prefixed by a "%d +" string when arg4 >= 0, then sets this->flag = 1 when arg3 != 0.
 * Built from the m2c draft; the global at 0x621870 is a pointer whose +0x194 field is the format string. */
typedef unsigned int u32;

extern char D_006A37F0[];

struct G { char pad[0x194]; const char *fmt; };
extern G *DisplayRText__rtext_ptrs_;

extern "C" u32 func_0057F260(const char *s);
extern "C" void func_0057DA20(char *buf, const char *fmt, ...);

extern "C" void func_003E03E0(char *arg0, int arg1, int arg2, int arg3, int arg4) {
    char *s0 = arg0 + 4;
    char *alt = arg0 + 0x24;
    if (arg3 == 0)
        s0 = alt;
    int flag = arg2;
    if (arg4 >= 0) {
        flag = 0;
        func_0057DA20(s0, D_006A37F0, arg4);
        s0 = s0 + func_0057F260(s0);
    }
    int big = 0x20;
    int width = 0x2B;
    if (flag == 0)
        width = big;
    func_0057DA20(s0, DisplayRText__rtext_ptrs_->fmt, width, arg1);
    if (arg3 != 0) {
        *(int *)(arg0 + 0xB4) = 1;
    }
}
