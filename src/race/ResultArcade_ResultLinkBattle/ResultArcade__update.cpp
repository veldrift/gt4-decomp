/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;

struct Org { char pad[0xF4]; char q[0x814]; u8 f908; };
struct Self {
    s32 f0; char pad4[8]; void *vt;
    s32 f10; char pad14[0x18];
    s32 a2C[6]; char pad44[0x10];
    s32 f54; char pad58[4]; s32 f5C;
};

extern "C" void RaceResultBase__update(void *, void *, void *);
extern "C" int RaceEventQueue__check(void *, int, int *, int);
extern "C" void func_00475488(s32, float);
extern "C" s32 func_003EBF40(s32, s32, void *);
extern "C" void func_003DFAE0(void *, void *);

extern "C" void ResultArcade__update(Self *self, Org *org, void *input) {
    RaceResultBase__update(self, org, input);
    if (self->f10 != 0) {
        s32 n = org->f908;
        for (s32 i = 0; i < n; i++) {
            s32 out = 0;
            if (RaceEventQueue__check(org->q, 12, &out, i) != 0) {
                if (self->a2C[out] == 0) {
                    self->a2C[out] = 1;
                }
            }
        }
        if (self->f0 != 0) {
            if (self->f5C != 0) {
                func_00475488(self->f5C, 0x1.111110p-6f);
            }
            if (self->f54 != 0) {
                func_003EBF40(self->f54, self->f5C, input);
            }
            func_003DFAE0(self, org);
        }
    }
}
