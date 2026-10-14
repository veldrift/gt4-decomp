/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; int (*fn)(void *); };
struct Obj { char pad0[0x64]; char *vtbl; char pad68[0xC68]; int cd0; char padcd4[0x239C4]; int voice; };
extern "C" int BGM__narrationEnable(void);
extern "C" void RacePS2Base__soundToggle(void *);
extern "C" int RaceFreeRun__setDescriptionVoicePlay(void *, int);
extern "C" void RaceFreeRun__soundToggle(Obj *self) {
    if (BGM__narrationEnable() == 0) return RacePS2Base__soundToggle(self);
    VEntry *e = (VEntry *)(self->vtbl + 0x400);
    if (e->fn((char *)self + e->delta) == 0) {
        if (self->cd0 == 0) {
            if (self->voice == 0) {
                RaceFreeRun__setDescriptionVoicePlay(self, 1);
            } else {
                RaceFreeRun__setDescriptionVoicePlay(self, 0);
                RacePS2Base__soundToggle(self);
            }
        }
    } else {
        RacePS2Base__soundToggle(self);
    }
}
