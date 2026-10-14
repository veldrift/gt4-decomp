struct Obj { char pad[0x18]; int value; char pad1C[8]; void *p24; void *p28; void *p2C; };
extern "C" Obj *func_00538988(int) throw();
extern "C" int func_005428E8(const void *) throw();
extern "C" int func_00538B08(void **, int) throw();
extern "C" void *func_005A4724(void *,const void *,unsigned int);
extern "C" void func_00546830(void *, const void *);
extern "C" int func_00543268(int arg0, int arg1, const void *arg2) {
    Obj *p = func_00538988(arg0);
    if (!p) return -1;
    if (func_005428E8(arg2)) return -1;
    if (!p->p2C) func_00538B08(&p->p2C,0x40);
    if (!p->p24) func_00538B08(&p->p24,0x10C);
    if (!p->p28) func_00538B08(&p->p28,0x10C);
    p->value = arg1;
    func_005A4724(p->p2C,arg2,0x40);
    func_00546830(p->p24,arg2);
    func_00546830(p->p28,arg2);
    return 0;
}
