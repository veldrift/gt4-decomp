/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef long s64;
struct Ent { short delta; short pad; void (*fn)(char *, char *, int); };
extern "C" s64 func_004454C0(char *);
extern "C" unsigned long long func_004454D0(char *);
extern "C" char *GT4Model__CarModel__getModelFileName(s64, char *, int, int);
extern "C" void func_005A5DC8(void *, void *);
extern char D_006A2570[];
extern "C" void func_003B5988(char *self, int arg) {
    char buf[0x50];
    char *model = self + 0x20;
    func_004454C0(model);
    GT4Model__CarModel__getModelFileName(func_004454D0(model), buf, arg == 2, *(int *)(self + 0x288C));
    func_005A5DC8(buf, D_006A2570);
    char *a = *(char **)(self + 0x2880);
    Ent *e = (Ent *)(*(char **)(a + 8) + 0x70);
    e->fn(a + e->delta, buf, arg);
}
