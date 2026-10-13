typedef int s32;

struct S001C4BA8 {
    char pad[0x68];
    void *f68;
};

extern char D_006550F8[];
extern char D_00689C88[];

extern "C" void func_00565D60(void *a0);
extern "C" void func_005659F8(struct S001C4BA8 *arg0, s32 arg1);

extern "C" void func_00566268(s32 arg0, s32 arg1)
{
    if (arg1 == 0xFFFF) {
        if (arg0 == 1) {
            func_00565D60(D_006550F8);
        }
        if (arg0 == 0) {
            struct S001C4BA8 *w = (struct S001C4BA8 *)D_006550F8;
            w->f68 = D_00689C88;
            func_005659F8(w, 0);
        }
    }
}
