typedef int s32;

struct V { short delta; short index; void *fn; };
struct S { char pad[0x12C]; V *table; char member[1]; };

extern "C" char *D_00622F4C;
extern "C" char D_0068D7C8[];
extern "C" void func_003BB440(S *arg0, char *arg1);
extern "C" long long func_00447C78(const char *arg0);
extern "C" void *func_00441248(void *arg0);
extern "C" void func_004452F8(void *arg0, void *arg1);

extern "C" void func_001175B0(S *arg0) {
    char **g = &D_00622F4C;
    char *s2 = (char *)arg0 + 0x130;
    func_003BB440(arg0, D_0068D7C8);
    long long key = func_00447C78(*g + 4);
    V *e = (V *)((char *)arg0->table + 0x20);
    ((void (*)(void *, long long))e->fn)((char *)arg0 + e->delta, key);
    char *p = *g + 0x13938;
    s32 same = *(long long *)func_00441248(p) == -1;
    if (!same) {
        func_004452F8(s2, func_00441248(p));
    }
}
