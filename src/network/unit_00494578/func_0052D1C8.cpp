struct Context { void *obj; char pad4[0x100]; int state; };
extern struct Context D_00867FF8;
extern "C" void func_00528E38(void *) throw();
extern "C" int func_0052D1C8() {
    if (D_00867FF8.state != 0) return 0xD2F4;
    func_00528E38(D_00867FF8.obj);
    return 0;
}
