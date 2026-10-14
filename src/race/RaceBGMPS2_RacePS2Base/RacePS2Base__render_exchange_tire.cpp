/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct VEntry { short delta; short index; void *fn; };
struct Obj { char pad[0x70]; s32 m70; };
struct O2 { char pad0[8]; char *vt; };
extern "C" s32 Pitmen__doRenderExchangeTire(void *, s32, s32, s32, s32);
extern "C" void Pitmen__applyExchangeTireMatrix(void *, s32, s32, s32, s32);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void RacePS2Base__render_exchange_tire(Obj *self, s32 a1, O2 *o2) {
    for (s32 i = 0; i < 4; i++) {
        for (s32 j = 0; j < 2; j++) {
            if (Pitmen__doRenderExchangeTire((char *)self + 0x3628, a1, self->m70, i, j)) {
                func_004A53F8();
                Pitmen__applyExchangeTireMatrix((char *)self + 0x3628, a1, self->m70, i, j);
                VEntry *e = (VEntry *)(o2->vt + 0xD8);
                ((void (*)(void *, s32))e->fn)((char *)o2 + e->delta, i);
                func_004A5400();
            }
        }
    }
}
