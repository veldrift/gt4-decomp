/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct Obj;
struct Sub { char pad[0x7C]; s32 f7C; };
struct Obj {
    char pad0[0x64]; char *vt; char pad68[4]; void *u6C;
    char pad70[0xE418 - 0x70]; char *e418; char padE41C[8]; Sub *e424;
};
extern "C" void RaceBasic__setPause(void *, s32);
extern "C" s32 RaceBasic__handle_command_in_pause(void *);
extern "C" void func_003BA3E8(void *);
extern "C" void RaceFreeRun__setDescriptionVoicePause(void *, s32);
#define VENT(o, off) ((VE *)(*(char **)((char *)(o) + 0x64) + (off)))
extern "C" void RaceFreeRun__updatePause(Obj *self) {
    VE *e = VENT(self, 0x238);
    s32 r = ((s32 (*)(void *))e->fn)((char *)self + e->delta);
    VE *e2 = (VE *)(*(char **)(self->e418 + 8) + 0x20);
    s32 k = ((s32 (*)(void *, s32, void *))e2->fn)(self->e418 + e2->delta, r, self->u6C);
    switch (k) {
    case 2: {
        VE *e3 = VENT(self, 0x2B8);
        ((void (*)(void *, s32, float, float))e3->fn)((char *)self + e3->delta, 3, 0.0f, 0.0f);
        break;
    }
    case 4: {
        func_003BA3E8(self);
        RaceBasic__setPause(self, 0);
        VE *e3 = VENT(self, 0x2C8);
        ((void (*)(void *))e3->fn)((char *)self + e3->delta);
        RaceFreeRun__setDescriptionVoicePause(self, 0);
        break;
    }
    case 3: {
        RaceBasic__setPause(self, 0);
        VE *e3 = VENT(self, 0x2C8);
        ((void (*)(void *))e3->fn)((char *)self + e3->delta);
        RaceFreeRun__setDescriptionVoicePause(self, 0);
        break;
    }
    case 5: {
        VE *e3 = VENT(self, 0x2B8);
        ((void (*)(void *, s32, float, float))e3->fn)((char *)self + e3->delta, 4, 0.0f, 0.0f);
        break;
    }
    }
    Sub *p = self->e424;
    if (p) {
        p->f7C = 1;
        VE *e3 = VENT(self, 0x470);
        ((void (*)(void *, s32))e3->fn)((char *)self + e3->delta, 1);
    }
    RaceBasic__handle_command_in_pause(self);
}
