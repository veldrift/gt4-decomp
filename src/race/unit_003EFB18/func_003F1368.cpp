/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
struct Car { char pad[0x104]; };
struct Par { char pad[0x441]; u8 f441; char pad2[0x466 - 0x441 - 1]; signed char f466; };
struct S { void *unk0; char pad[0xF8A0 - 4]; s32 count; };
extern "C" char D_00645570[];
struct T { char pad[2]; u8 f2; };
extern "C" T D_00621FF8;
extern "C" Car *func_0034C190(S *, s32) ;
extern "C" s32 func_004FB1B0(char *, s32);
extern "C" s32 func_003C0EC0(void *, s32, void *);
extern "C" s32 func_003F12A0(S *) throw();
extern "C" void func_003F0498(Car *, void *, s32) throw();
extern "C" void func_003F0E18(Car *, s32, s32) throw();
extern "C" void func_003F1368(S *self) {
    s32 i = 0;
    s32 n = self->count;
    void *h = self->unk0;
    char buf[0x30];
    if (n > 0) {
        do {
            Car *c = func_0034C190(self, i);
            Par *p = (Par *)((char *)c + 0x104);
            if (p->f466 == 4) {
                if (func_004FB1B0(D_00645570, i) == 0) {
                    p->f441 = 1;
                } else {
                    if (func_003C0EC0(h, i, buf) != 0)
                        func_003F0498(c, buf, func_003F12A0(self));
                    func_003F0E18(c, func_003F12A0(self), D_00621FF8.f2 * 300);
                }
            }
            i++;
        } while (i < n);
    }
}
