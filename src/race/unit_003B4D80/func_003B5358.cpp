typedef int s32;
typedef long s64;

struct Ent { short delta; short pad; void (*fn)(char *, char *); };

extern "C" s64 func_004454D0(char *arg0);
extern "C" char *GT4Model__CarModel__getModelFileName(s64 arg0, char *arg1, s32 arg2, s32 arg3);

extern "C" void func_003B5358(char *arg0, s32 arg1, s32 arg2) {
    char buf[0x50];
    *(s32 *)(arg0 + 0x288C) = arg2;
    GT4Model__CarModel__getModelFileName(func_004454D0(arg0 + 0x20), buf, arg1 == 2, arg2);
    char *a = *(char **)(arg0 + 0x2880);
    Ent *e = (Ent *)(*(char **)(a + 8) + 0x60);
    e->fn(a + e->delta, buf);
}
