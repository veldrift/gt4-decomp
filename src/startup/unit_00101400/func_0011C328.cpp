typedef int s32;
typedef long s64;
typedef unsigned char u8;
struct Item { char pad[0x18]; void *p18; };
struct List { s32 count; s32 pad4; Item **items; };
struct Src { char pad[0x60]; List *list; char pad64[0xC]; void *p70; };
struct Arg1 { char pad[0x6C]; Src *src; };
struct Ctx { s64 pad[9]; s64 f48; };
extern "C" {
s32 func_00110570(void *, s32);
s32 func_0035E3F0(void *);
void RaceEntryBase__sortByRank(void *);
s32 RaceOrganization__getScore(void *, s32);
void func_0042F350(void *, s32, s32, s32, s32);
s32 func_00430A20(void *, s32);
void func_00430A58(void *, s32, s32);
void *func_00430D20(void *, s32);
s32 SPEC_DATABASE__RaceSpec__getRaceLabel(void *);
s32 func_004475A8(void *, s32);
}
extern char *D_00622F4C;
extern "C" void func_0011C328(char *self, Arg1 *a1) {
    Src *s = a1->src;
    s32 nm = SPEC_DATABASE__RaceSpec__getRaceLabel(s->p70);
    char *g = D_00622F4C;
    Ctx *c = (Ctx *)(g + 0x348);
    void *slot = func_00430D20(g + 0x13E28, nm);
    RaceEntryBase__sortByRank(s->list);
    g += 0x568;
    s32 r = func_00110570(s, 0);
    s32 cnt = func_004475A8(s->p70, r);
    u8 kind = r;
    s32 v = func_0035E3F0(s->list->items[0]->p18);
    c->f48 = cnt + c->f48;
    func_00430A58(slot, 3, kind);
    func_00430A20(slot, RaceOrganization__getScore(s, 0));
    func_0042F350(g, nm, kind, 0xF, v);
    *(s32 *)(self + 0x4A4) = cnt;
}
