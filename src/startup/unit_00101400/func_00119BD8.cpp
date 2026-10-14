typedef int s32;
typedef long s64;
typedef signed char s8;
struct Src { char pad[0x170]; s32 f170, f174, f178; };
struct Sx { char pad[0x130]; char p130[0x40]; s32 f170, f174; };
struct Ent { s64 a; s32 b; s32 c; };
struct Blk { char pad[0x28]; s8 f28, f29, f2a; };
extern "C" {
Src *func_003EEC70(void *, s32);
void func_0042F860(void *, void *);
s64 func_004454C0(void *);
s64 func_004454C8(void *);
s8 SPEC_DATABASE__CarEquipments__getVariationOrder(void *);
}
extern char *D_00622F4C;
extern "C" void func_00119BD8(Sx *selfp, s32 a1) {
    char *self = (char *)selfp;
    char *g = D_00622F4C;
    Blk *blk = (Blk *)(g + 0x38BF8);
    blk->f28 = a1;
    if (a1 != 0) {
        Ent *e = (Ent *)(g + 0x38C28);
        s32 v1 = selfp->f170;
        blk->f29 = v1;
        s32 i = 0;
        s32 v2 = selfp->f174;
        blk->f2a = v2;
        func_0042F860(blk, self + 0x130);
        do {
            Src *s = func_003EEC70(self, i);
            if (i == 0) e->a = func_004454C0(s);
            else e->a = func_004454C8(s);
            i++;
            e->b = SPEC_DATABASE__CarEquipments__getVariationOrder(s);
            e->c = s->f178;
            e++;
        } while (i < 6);
    }
}
