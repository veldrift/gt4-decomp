typedef int s32;

struct Frame { union { char *p; s32 w; } u; s32 n; };

extern "C" s32 func_0057DD28(char *buf, s32 fmt, s32 ap);
extern "C" s32 func_004AF910(void *arg0, void *arg1);

extern "C" void func_002F7060(char *arg0, s32 fmt, s32 ap) {
    char buf[0x210];
    Frame f;
    s32 r = func_0057DD28(buf, fmt, ap);
    Frame *pf = &f;
    pf->u.p = buf;
    pf->n = r;
    func_004AF910(arg0 + 0x18, pf);
}
