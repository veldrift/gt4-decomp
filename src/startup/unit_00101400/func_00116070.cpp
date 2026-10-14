/* compiler: ee-gcc2.96-nogcse */
typedef int s32;
struct Car { char pad[0x20]; char body[0x3424]; s32 idx; };
struct List { s32 count; s32 pad4; s32 items; };
struct Src { char pad[0x60]; s32 list; char pad64[0xC]; s32 p70; };
struct Arg1 { char pad[0x6C]; Src *src; };
extern "C" {
char *func_00445450(char *);
s32 func_00445AE8(char *, char *);
s32 SPEC_DATABASE__RaceSpec__getRaceLabel(void *);
s32 func_004472A0(void *);
char *func_005A609C(char *, const char *);
}
#define LIST ((List *)s->list)
#define ITEMS ((Car **)LIST->items)
extern "C" void func_00116070(char *dst, Arg1 *a1) {
    Src *s = a1->src;
    s32 n = *(s32 *)*(s32 *)((char *)s + 0x60);
    s32 i = 0;
    if (n > 0) do {
        s32 off = i * 4;
        i++;
        char *o = *(char **)(off + LIST->items);
        s32 idx = *(s32 *)(o + 0x3444);
        func_005A609C(dst + (idx << 7) + 4, func_00445450(o + 0x20));
        char *p = dst + idx * 16;
        off += LIST->items;
        char *o2 = *(char **)off;
        func_00445AE8(o2 + 0x20, p + 0x304);
    } while (i < n);
    *(s32 *)(dst + 0x478) = n;
    *(s32 *)(dst + 0x4B4) = 1;
    *(s32 *)(dst + 0x498) = 0x157529FF;
    *(s32 *)(dst + 0x4B0) = 0;
    *(s32 *)(dst + 0x474) = 0;
    *(s32 *)(dst + 0x470) = 0;
    *(s32 *)(dst + 0x46C) = 0;
    *(s32 *)(dst + 0x4A0) = ITEMS[0]->idx;
    func_005A609C(dst + 0x3C8, (char *)SPEC_DATABASE__RaceSpec__getRaceLabel((void *)s->p70));
    func_005A609C(dst + 0x408, (char *)func_004472A0((void *)s->p70));
}
