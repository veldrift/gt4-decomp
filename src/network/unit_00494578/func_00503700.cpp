/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { char p[0x38]; int flag; char p2[0xF94]; int x, y; };
extern "C" void func_004FB698(void *);
extern "C" void func_005035A8(void *) throw();
extern "C" void func_005035E0(void *) throw();
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_00503700(O *o) {
    char *lock = (char *)o + 8;
    while (o->flag) {
        func_005035E0(o);
        if (!o->flag) break;
        func_00576788(lock);
        func_004FB698(o);
        o->y = o->x;
        func_005767C0(lock);
    }
    func_005035A8(o);
}
