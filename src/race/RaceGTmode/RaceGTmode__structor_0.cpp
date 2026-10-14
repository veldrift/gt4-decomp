/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Z { char pad[0x2C]; s32 f2C; };
struct Obj {
    char pad0[0x64]; void *vt; char pad68[8]; void *f70;
    char pad74[0xD68 - 0x74]; s32 d68;
    char padD6C[0xE408 - 0xD6C]; void *e408; char pad40C[4]; void *e410;
};
struct E { char b[8]; };
extern char RaceGTmode__vtable[];
extern "C" s32 RaceSinglePlayer__structor_0(Obj *);
extern "C" void DynamicsConductorSinglePlayer__structor_1(void *);
extern "C" void func_00393700(void *);
extern "C" void RacePause__structor_0(void *);
extern "C" void func_003D7700(void *);
extern "C" void func_003DCA28(void *);
extern "C" void func_003BAB90(void *);
extern "C" void ResultArcade__structor_0(void *);
extern "C" s32 func_0033CF48(void);
extern "C" void func_003C31C8(void *, void *);
extern "C" void func_003D8490(void *, void *);
extern "C" void func_003DD4B8(void *, void *);
extern "C" void func_003DF898(void *, void *);
extern "C" int RaceGTmode__structor_0(Obj *self) {
    RaceSinglePlayer__structor_0(self);
    self->vt = RaceGTmode__vtable;
    DynamicsConductorSinglePlayer__structor_1((char *)self + 0x125C0);
    E *arr = (E *)((char *)self + 0x22708);
    for (s32 i = 5; i != -1; i--) func_00393700(arr++);
    Z *s2 = (Z *)((char *)self + 0x22738);
    char *s5 = (char *)self + 0x22770;
    char *s3 = (char *)self + 0x23AB0;
    RacePause__structor_0(s2);
    func_003D7700(s5);
    char *s0 = (char *)self + 0x23BB8;
    func_003DCA28(s3);
    char *s4 = (char *)self + 0x23BCC;
    func_003BAB90(s0);
    ResultArcade__structor_0(s4);
    self->e408 = s3;
    self->e410 = s0;
    self->f70 = (char *)self + 0x125C0;
    if (func_0033CF48() == 0) {
        char *t = (char *)self + 0xE350;
        s2->f2C = 1;
        func_003C31C8(s2, t);
        func_003D8490(s5, t);
        func_003DD4B8(s3, t);
        func_003DF898(s4, t);
    }
    self->d68 = 0xD;
}
