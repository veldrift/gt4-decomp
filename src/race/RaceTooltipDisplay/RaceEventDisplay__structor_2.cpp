/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;

struct VEntry { s16 delta; s16 index; void (*fn)(void *, s32); };
struct ElemV { char pad[0x14]; char *vtbl; char pad2[0x150 - 0x18]; };

extern char RaceTooltipDisplay__vtable[];
extern char RaceEventDisplay__vtable[];
extern char RaceMessageDisplay__vtable[];

extern "C" void RaceDisplayObjectBase__structor_1(void *, s32);
extern "C" void func_005C1628(void *) throw();

struct Base { char pad[0x14]; virtual ~Base(); };
struct Elem : Base { char rest[0x138]; virtual ~Elem(); };
struct Sub { char pad[0x50]; Elem elems[8]; ~Sub() { *(char **)(pad + 0x14) = RaceEventDisplay__vtable; } };
static inline void destroy_sub(char *sub) {
    ((Sub *)sub)->~Sub();
    RaceDisplayObjectBase__structor_1(sub, 0);
}
extern "C" void RaceEventDisplay__structor_2(char *self, s32 flags) {
    *(char **)(self + 0x14) = RaceTooltipDisplay__vtable;
    destroy_sub(self + 0x18C);
    char *m = self + 0x3C;
    *(char **)(m + 0x14) = RaceMessageDisplay__vtable;
    RaceDisplayObjectBase__structor_1(m, 0);
    RaceDisplayObjectBase__structor_1(self, 0);
    if (flags & 1) return func_005C1628(self);
}
