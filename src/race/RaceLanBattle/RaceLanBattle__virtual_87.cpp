/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xe468]; int mode; };
extern "C" void RaceBasic__cleanup(Obj *);
extern "C" void func_004FAFD0(void *);
extern "C" void func_004FB030(void *);
extern "C" void func_00335990() throw();
extern char D_00645570[];
extern "C" void RaceLanBattle__virtual_87(Obj *self) {
    RaceBasic__cleanup(self);
    if (self->mode == 0) func_004FAFD0(D_00645570);
    else func_004FB030(D_00645570);
    func_00335990();
}
