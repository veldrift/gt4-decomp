typedef int s32;

struct Encoder;
struct func_0046C9F8_arg1;

extern s32 D_006ABE14;
extern s32 D_006ABE18;
extern char D_006ABE20[];
extern char D_006ABE40[];
extern char D_006ABE60[];
extern char D_006ABF18[];
extern char D_00624060[];

extern "C" void func_0046C7A0(s32 arg0, s32 arg1);
extern "C" void func_0046C8D8(Encoder *e, const int *table, int id);
extern "C" void func_0046C970(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern "C" void func_0046C9F8(s32 *arg0, struct func_0046C9F8_arg1 *arg1, s32 arg2, char **arg3);
extern "C" void func_0046CB18(s32 *arg0);

extern "C" void func_0046C418(Encoder *arg0) {
    s32 n = *(s32 *)((char *)arg0 + 0x8A8);
    if (n > 0) {
        func_0046C7A0((s32)arg0, n);
    }
    func_0046C8D8(arg0, (const int *)((char *)arg0 + 0x140), 0);
    func_0046C8D8(arg0, (const int *)((char *)arg0 + 0x240), 1);
    {
        char *p1 = D_006ABE20;
        s32 v = D_006ABE14;
        func_0046C970((s32)arg0, (s32)p1, v, 0, 0);
        func_0046C970((s32)arg0, (s32)D_006ABE40, v, 0, 1);
    }
    {
        char *p2 = D_006ABE60;
        s32 w = D_006ABE18;
        func_0046C970((s32)arg0, (s32)p2, w, 1, 0);
        func_0046C970((s32)arg0, (s32)D_006ABF18, w, 1, 1);
    }
    func_0046C9F8((s32 *)arg0,
                  (struct func_0046C9F8_arg1 *)((char *)arg0 + 0x888),
                  (s32)((char *)arg0 + 0x8C4),
                  (char **)D_00624060);
    func_0046CB18((s32 *)arg0);
}
