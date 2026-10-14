/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VT { short adj; short pad2; int (*fn)(void *); };
struct Obj { VT *vt; };
struct Sentry { int pad0; int val; unsigned char *cur; char pad1[0x30 - 0xC - 0x10 + 0x10 - 0x10 - 0xC]; };
struct Sen { int pad0; int val; unsigned char *cur; char pad1[0x30 - 0xC - 0x20]; };
struct SI { int pad0; int val; unsigned char *cur; char pad2[0x14]; unsigned char flag; char pad3[0xF]; };
extern "C" void func_004B22D8(SI *, int) throw();
extern "C" void func_004B2388(SI *, Obj *, int) throw();
extern "C" void func_004B23F0(SI *, int) throw();
extern "C" int func_004B2518(SI *, char *, int) throw();
extern "C" void func_004B27D0(SI *, char *, int, int *) throw();
extern "C" void func_004B2CD0(void *) throw();
extern "C" void func_004B2CF8(void *, Obj *, int, int, int) throw();
extern "C" void func_004B3270(SI *, Obj *, int, char *);

extern "C" void *func_004B33D8(void *arg0, Obj *arg1, int arg2, char *arg3) {
    char buf[4];
    SI si;
    int cnt;
    int s2, s3;
    if (arg2 == 1 && (arg3 == 0 || *arg3 == 0)) {
        s3 = 1;
    } else {
        func_004B3270(&si, arg1, arg2, arg3);
        s3 = si.val;
        if ((unsigned char)(si.flag & 1) == 0) {
            func_004B2CD0(arg0);
            goto done;
        }
    }
    {
    VT *vt = (VT *)((char *)arg1->vt + 0x18);
    buf[0] = s3 >> 24;
    buf[1] = s3 >> 16;
    buf[2] = s3 >> 8;
    buf[3] = s3;
    s2 = 0;
    int r = vt->fn((char *)arg1 + vt->adj);
    func_004B2388(&si, arg1, r);
    while ((si.cur[0] | (si.cur[1] << 8)) == 1) {
        s2 = func_004B2518(&si, buf, 4);
        func_004B23F0(&si, s2);
    }
    cnt = 0;
    func_004B27D0(&si, buf, 4, &cnt);
    func_004B2CF8(arg0, arg1, s2, cnt, s3);
    func_004B22D8(&si, 2);
    }
done:
    return arg0;
}
