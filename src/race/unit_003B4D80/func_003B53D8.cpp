typedef int s32;
typedef long s64;

struct Ent { short delta; short pad; void (*fn)(char *, char *); };

extern "C" s64 func_004454D0(char *arg0);
extern "C" char *GT4Model__CarModel__getModelFileName(s64 arg0, char *arg1, s32 arg2, s32 arg3);

extern "C" void func_003B53D8(char *arg0) {
    char buf[0x50];
    GT4Model__CarModel__getModelFileName(func_004454D0(arg0 + 0x20), buf, 1, 0);
    char *a = *(char **)(arg0 + 0x2880);
    Ent *e = (Ent *)(*(char **)(a + 8) + 0x78);
    e->fn(a + e->delta, buf);
}
