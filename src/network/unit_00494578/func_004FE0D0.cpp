/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Ev {
    s32 d[0x1FC / 4];
};

struct Work {
    char pad0[0x1D8];
    Ev ev;
};

struct Sess {
    char pad0[0x5A8];
    char *work;
    char pad1[0xAF0 - 0x5AC];
    char *buf;
    s32 limit;
};

extern "C" {
s32 func_004F0B08(void *, const char *) throw();
s32 func_004F0C38(void *, const char *) throw();
void func_004F87E8(void *, s32) throw();
void *func_005A4724(void *, const void *, unsigned);
}

#define NAME "FileDownloadCallback"
extern char D_00645570[];

extern "C" void func_004FE0D0(char *arg0, Sess *s)
{
    if (s == 0) {
        s = (Sess *)D_00645570;
    }
    if (func_004F0C38(s, NAME) != 0) {
        func_004F0B08(s, arg0 + 0x1E4);
        return;
    }
    s32 done = 0;
    s32 a = *(s32 *)(arg0 + 0x1E0);
    if (a < 0 || a == 1) {
        func_004F87E8(s, a);
        done = 1;
    }
    if (done) {
        func_004F0B08(s, arg0 + 0x1E4);
        return;
    }
    ((Work *)s->work)->ev = *(Ev *)arg0;
    func_004F87E8(s, *(s32 *)(arg0 + 0x1E0));
    func_005A4724(s->buf + *(s32 *)(arg0 + 0x1D0), arg0, *(s32 *)(arg0 + 0x1D4));
    if (!(*(s32 *)(arg0 + 0x1D0) + *(s32 *)(arg0 + 0x1D4) < s->limit)) {
        func_004F0B08(s, arg0 + 0x1E4);
    }
}
