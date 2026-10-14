typedef int s32;
typedef unsigned char u8;

extern char D_00697BC0[];
extern char D_00697BD8[];
extern char D_00697BE0[];
extern char D_00697BF8[];
extern char D_00697C10[];
extern char D_00697C28[];
extern char D_0082B570[];
extern char D_0082BBB8[];
extern char D_0082C200[];
extern char D_0082C848[];

extern "C" void HOutput__printf(void *arg0, const char *fmt, ...);
extern "C" void *ADHOC__PoolAllocator__GetDefault(void);
extern "C" void ADHOC__PoolAllocator__Report(s32 arg0, s32 arg1);

extern "C" void mManager__Report(s32 arg0) {
    HOutput__printf((void *)arg0, D_00697BC0);
    char *close = D_00697BD8;
    ADHOC__PoolAllocator__Report(arg0, (s32)&D_0082B570);
    HOutput__printf((void *)arg0, close);
    HOutput__printf((void *)arg0, D_00697BE0);
    ADHOC__PoolAllocator__Report(arg0, (s32)&D_0082BBB8);
    HOutput__printf((void *)arg0, close);
    HOutput__printf((void *)arg0, D_00697BF8);
    ADHOC__PoolAllocator__Report(arg0, (s32)&D_0082C200);
    HOutput__printf((void *)arg0, close);
    HOutput__printf((void *)arg0, D_00697C10);
    ADHOC__PoolAllocator__Report(arg0, (s32)&D_0082C848);
    HOutput__printf((void *)arg0, close);
    HOutput__printf((void *)arg0, D_00697C28);
    ADHOC__PoolAllocator__Report(arg0, (s32)ADHOC__PoolAllocator__GetDefault());
    HOutput__printf((void *)arg0, close);
}
