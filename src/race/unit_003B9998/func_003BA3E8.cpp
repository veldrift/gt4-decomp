/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct Ent { char pad[0x18]; void *f18; };
struct Info { u32 n; s32 pad; Ent **tbl; };
struct Mid { char pad[0x60]; Info *info; };
struct Obj {
    char pad0[0x64]; char *vt; char pad68[4]; Mid *mid;
    char padCC8[0xCC8 - 0x70]; u32 cc8;
    char pad2[0x24694 - 0xCCC]; s32 f24694;
};
extern "C" {
int Automobile__GetExplicitCurrentLap(void *);
void func_00343D78(void *, s32);
void AutomobileControlRecord__Recorder__finish(void *);
void func_003B76F0(void *, int, int, int);
char *RaceSolitaire__getInput(void *);
void func_00426C78(void *);
void func_003BA3E8(Obj *self) {
    Mid *s1 = self->mid;
    void *s2 = s1->info->tbl[0]->f18;
    if (self->f24694 != 0 || self->cc8 >= 2 || Automobile__GetExplicitCurrentLap(s2) < 2) {
        VE *e = (VE *)(self->vt + 0x2B8);
        ((void (*)(void *, s32, float, float))e->fn)((char *)self + e->delta, 2, 0.0f, 0.0f);
        return;
    }
    self->f24694 = 1;
    func_003B76F0((char *)s1 + 0xF4, 5, 0, 2);
    func_00343D78(s2, 4);
    AutomobileControlRecord__Recorder__finish(RaceSolitaire__getInput(self) + 0xDC);
    func_00426C78(RaceSolitaire__getInput(self));
    VE *e = (VE *)(self->vt + 0x2B8);
    ((void (*)(void *, s32, float, float))e->fn)((char *)self + e->delta, 2, 0.0f, 0.0f);
}
}
