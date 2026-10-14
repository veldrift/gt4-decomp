/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short adj; short pad; int (*fn)(void *, int); };
struct VT { char pad[0x18]; VE e18; };
struct Obj { VT *vt; };
extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" int GranTurismo4__OptionRaceInputPortPS2__getDevice(Obj *o, const char *name) {
    if (!func_0057F238("CONTROLLER", name) || !func_0057F238("JOYSTICK", name) ||
        !func_0057F238("SINGLESHOCK", name) || !func_0057F238("DUALSHOCK", name) ||
        !func_0057F238("DUALSHOCK 2", name)) {
        VE *e = &o->vt->e18;
        return e->fn((char *)o + e->adj, 0);
    } else if (!func_0057F238("COUGAR", name)) {
        VE *e = &o->vt->e18;
        return e->fn((char *)o + e->adj, 1);
    } else if (!func_0057F238("JAGUAR", name)) {
        VE *e = &o->vt->e18;
        return e->fn((char *)o + e->adj, 2);
    } else if (!func_0057F238("CHEETAH", name)) {
        VE *e = &o->vt->e18;
        return e->fn((char *)o + e->adj, 3);
    }
    return 0;
}
