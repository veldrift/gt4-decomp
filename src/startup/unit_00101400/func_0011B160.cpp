typedef int s32;

struct V { short delta; short index; void *fn; };
struct S { char pad[0x12C]; V *table; };

extern "C" char *D_00622F4C;
extern "C" char D_0068DA18[];
extern "C" void func_003BB440(S *arg0, char *arg1);
extern "C" s32 func_0057F260(void *arg0);
extern "C" void func_004471E0(void *arg0, void *arg1);
extern "C" void func_003EDD80(void *arg0, void *arg1);
extern "C" void *func_00441248(void *arg0);

extern "C" void func_0011B160(S *arg0) {
    func_003BB440(arg0, D_0068DA18);
    char **g = &D_00622F4C;
    char *s0 = *g + 4;
    if (func_0057F260(s0) != 0) {
        V *e = (V *)((char *)arg0->table + 0x98);
        void *r = ((void *(*)(void *))e->fn)((char *)arg0 + e->delta);
        func_004471E0(r, s0);
    }
    V *e2 = (V *)((char *)arg0->table + 0x50);
    ((void (*)(void *, s32))e2->fn)((char *)arg0 + e2->delta, 1);
    char *p = *g + 0x13938;
    s32 same = *(long long *)func_00441248(p) == -1;
    if (!same) {
        func_003EDD80(arg0, func_00441248(p));
    }
}
