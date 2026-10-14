/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0xCC8]; int mode; };
extern "C" void RaceSinglePlayer__initialize(void *);
extern "C" void func_0038B8D8(void *, void *) throw();
extern "C" void func_003DF970(void *, int);
extern "C" void RaceNetRallyBattle__virtual_37(Obj *o) {
    RaceSinglePlayer__initialize(o);
    if ((unsigned int)(o->mode - 2) < 2U) {
        return func_0038B8D8(o, 0);
    }
    char *result = (char *)o + 0x22738;
    func_0038B8D8(o, result);
    func_003DF970(result, (int)((char *)o + 0x22708));
}
