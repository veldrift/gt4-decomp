/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct Cam { char pad[0xD4]; float fD4; };
struct Obj {
    char pad0[0x64]; char *vt; char pad68[4]; Cam *u6C;
    char pad70[0xCC8 - 0x70]; u32 cc8; char padCCC[4]; s32 cd0; char padCD4[8]; s32 cdc;
    char padCE0[0xE400 - 0xCE0]; s32 e400; s32 e404;
};
extern "C" s32 RaceInput__getButtonDown(void *);
#define VENT(o, off) ((VE *)(*(char **)((char *)(o) + 0x64) + (off)))
static inline void *CALL0(Obj *o, int off) { VE *e = VENT(o, off); return ((void *(*)(void *))e->fn)((char *)o + e->delta); }
static inline s32 is13(u32 m) { s32 r = 0; if (m == 1 || m == 3) r = 1; return r; }
static inline s32 isPos(Obj *o) { return o->u6C->fD4 >= 0.0f; }
extern "C" void RaceBasic__updatePlayCheckPause(Obj *self) {
    if (self->cd0 == 0) {
        if (RaceInput__getButtonDown(CALL0(self, 0x230)) & 0x40) {
            if (CALL0(self, 0x4C0)) {
                VE *e = VENT(self, 0x2B8);
                ((void (*)(void *, s32, float, float))e->fn)((char *)self + e->delta, 1, 0.5f, 0.5f);
            } else if (self->cdc != 0 || CALL0(self, 0xB8)) {
                VE *e = VENT(self, 0x2B8);
                ((void (*)(void *, s32, float, float))e->fn)((char *)self + e->delta, 2, 0.5f, 0.5f);
            } else if (!isPos(self)) {
                VE *e = VENT(self, 0x4B0);
                ((void (*)(void *, s32))e->fn)((char *)self + e->delta, self->e400);
            }
        }
        if (RaceInput__getButtonDown(CALL0(self, 0x230)) & 0x80) {
            if (!isPos(self)) {
                u32 m = self->cc8;
                s32 big = m >= 2;
                if (big || is13(m)) {
                    VE *e = VENT(self, 0x4B0);
                    ((void (*)(void *, s32))e->fn)((char *)self + e->delta, self->e404);
                }
            }
        }
    }
}
