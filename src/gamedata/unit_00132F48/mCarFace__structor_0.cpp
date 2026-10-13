typedef int s32;
extern "C" void *mWidget__structor_0(void *);
extern "C" void *func_0021B6F0(void*);
extern "C" void func_00210810(void*);
extern "C" void func_00201EC8(void*);
extern "C" void func_00210830(void*);
extern "C" void func_00151800(void*, void*);
extern "C" void func_0013BD38(void*, s32*);
extern "C" void func_0021CA08(void*);
extern char mCarFace__vtable[];
struct mCarFace {
    char pad0[4]; void *vtable; char pad8[0x98];
    char fieldA0[0x2C]; char fieldCC[4]; char fieldD0[0x68];
    char field138[0x164];
    mCarFace() __asm__("func_00137F40");
};
mCarFace::mCarFace() {
    s32 one = 1;
    mWidget__structor_0(this);
    vtable = mCarFace__vtable;
    func_0021B6F0((char *)this + 0xA0);
    func_00210810((char *)this + 0xCC);
    func_00201EC8((char *)this + 0xD0);
    func_00210830((char *)this + 0x138);
    *(s32 *)((char *)this + 0x29C) = one;
    *(s32 *)((char *)this + 0x2A0) = one;
    s32 temp[2];
    temp[0] = 0;
    func_00151800((char *)this + 0x2A4, &temp[0]);
    temp[1] = 0;
    func_0013BD38((char *)this + 0x2A8, &temp[1]);
    func_0021CA08((char *)this + 0x2AC);
    *(s32 *)((char *)this + 0x2B0) = 0;
    *(s32 *)((char *)this + 0x2B4) = one;
    *(s32 *)((char *)this + 0x2B8) = 0;
}
