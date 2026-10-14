/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };

extern Rep D_00659FA8;
extern char D_00697A60[];
extern "C" s32 func_00206868(s32);
extern "C" void func_00206B80(s32, s32);
extern "C" void func_00212A68(s32, s32, void *) throw();
extern "C" s32 func_0025C300(s32);
extern "C" void func_00265F80(s32, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_005C2630(void *, s32, s32, const char *, s32);

static inline void setp(char **d, char *p) { *d = p; }
static inline void str_release(char **pp) {
    Rep *q = (Rep *)(*pp - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_00212ED0(s32 arg0, s32 *arg1) {
    char *s[4];
    s32 s5 = *arg1;
    s32 s3 = func_00206868(s5);
    if (s3 != 0) {
        const char *str = D_00697A60;
        char **ps = s;
        while (s3 != 0) {
            s32 s2 = s3;
            s3 = func_0025C300(s2);
            func_00265F80(s2, 0);
            char *p;
            if (D_00659FA8.sel != 0) {
                p = func_005C2560(&D_00659FA8);
            } else {
                p = (char *)&D_00659FA8 + 0x10;
                D_00659FA8.ref = D_00659FA8.ref + 1;
            }
            setp(ps, p);
            func_005C2630(ps, 0, -1, str, func_0057F260(str));
            func_00212A68(arg0, s2, s);
            str_release(s);
            func_00206B80(s5, s2);
        }
    }
}
