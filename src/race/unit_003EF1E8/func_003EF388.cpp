/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct S { char pad[0x130]; char name[0x20]; char buf[0x20]; s32 n; };
extern "C" void func_003BB440(void *, char *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" char *func_005A609C(char *, const char *);

extern "C" void func_003EF388(S *s) {
    char *buf = s->buf;
    func_005A609C(buf, s->name);
    s32 len = func_0057F260(buf);
    s->buf[len-1] = (s->n + 1) % 10 + 0x30;
    s->buf[len-2] = (s->n + 1) / 10 + 0x30;
    func_003BB440(s, buf);
}
