typedef int s32;
struct Cur { s32 w0; s32 w4; s32 w8; };
struct S { char p0[0xBC]; Cur cur; };
extern "C" s32 func_00206868(S *arg0);
extern "C" void func_00235C80(char *self, void *value);
extern "C" S *func_0025C300(S *arg0);
extern "C" void func_00265F10(S *arg0, s32 arg1);

extern "C" void func_002DB300(S *arg0, s32 arg1) {
    s32 s3 = 0;
    S *s0 = (S *)func_00206868(arg0);
    if (s0 != 0) {
        Cur *c = &arg0->cur;
        do {
            if (s3 == c->w0) {
                func_00265F10(s0, 1);
                if (arg1 != 0) {
                    func_00235C80((char *)arg1, (void *)s0);
                }
            } else {
                func_00265F10(s0, 0);
            }
            s3 += 1;
            s0 = func_0025C300(s0);
        } while (s0 != 0);
    }
}
