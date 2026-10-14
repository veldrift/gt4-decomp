struct Race { char pad[0xCD0]; int visual; };
struct Root { char pad[0x84]; Race *race; };
struct Self { Root *root; char pad[0x10]; int active; };
extern "C" void func_0033D110(void *, float) throw();
extern "C" void func_00462200(void);
extern "C" void RaceBGMPS2__stop(Self *self) {
    if (self->root->race->visual == 0) func_00462200();
    self->active = 0;
    func_0033D110(self, 1.0f);
}
