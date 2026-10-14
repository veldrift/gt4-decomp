/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VInt { short delta, index; int (*fn)(void *); };
struct VVoid { short delta, index; void (*fn)(void *); };
struct Settings { char pad[0xE0]; int mode; };
struct Obj { char pad0[0x64]; char *vtbl; int unk68; Settings *settings; char pad70[0xC58]; int type; };
extern "C" char *D_00622F4C;
extern "C" void RaceBase__raceStart(void *);
extern "C" int RaceFreeRun__setDescriptionVoicePlay(void *, int);
extern "C" void RacePS2Base__soundToggle(void *);
extern "C" void RaceFreeRun__raceStart(Obj *self) {
    RaceBase__raceStart(self);
    if (self->settings->mode == 0) {
        int type = self->type;
        if ((unsigned int)(type - 2) < 2 || (type ^ 4) == 0) {
            if (*(int *)(D_00622F4C + 0x39D64) != 0) {
                RaceFreeRun__setDescriptionVoicePlay(self, 1);
                VInt *e = (VInt *)(self->vtbl + 0x400);
                if (e->fn((char *)self + e->delta) != 0) RacePS2Base__soundToggle(self);
                VVoid *e2 = (VVoid *)(self->vtbl + 0x410);
                e2->fn((char *)self + e2->delta);
            }
        }
    }
}
