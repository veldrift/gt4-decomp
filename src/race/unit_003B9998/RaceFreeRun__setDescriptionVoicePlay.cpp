/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef long s64;
struct Info { u32 n; s32 pad; s32 *tbl; };
struct Mid { char pad[0x60]; Info *info; };
struct Obj { char pad0[0x6C]; Mid *mid; char pad70[0x24628]; s32 unk24698; u32 unk2469C; s32 unk246A0; s32 unk246A4; };
extern "C" {
void RaceCarSound__setNarration(s32);
s64 func_004454C0(s64 *);
int SPEC_DATABASE__GetCarNameInfo(long, void *);
void func_00460600(float);
int BGM__narrationEnable(void);
void func_004606D0(int);
void BGM__narrationPause(int);
void RaceFreeRun__setDescriptionVoicePlay(Obj *self, s32 arg1) {
    s32 sp[4];
    if (BGM__narrationEnable() != 0 && self->unk24698 != arg1) {
        self->unk24698 = arg1;
        RaceCarSound__setNarration(arg1);
        if (self->unk246A0 != 0) {
            s32 t = arg1 ^ 1;
            RaceCarSound__setNarration(t);
            BGM__narrationPause(t);
            self->unk246A4 = t;
            return;
        }
        if (arg1 != 0) {
            u32 i = self->unk2469C;
            Info *inf = self->mid->info;
            if (i < inf->n && SPEC_DATABASE__GetCarNameInfo(func_004454C0((s64 *)(inf->tbl[i] + 0x20)), sp) != 0) {
                s32 v = sp[3];
                func_00460600(1.0f);
                func_004606D0(v);
                self->unk246A0 = 1;
            }
        }
    }
}
}
