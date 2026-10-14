/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { char *world; };
struct State { char pad[0x614]; int time; char pad2[0x65B-0x618]; unsigned char flag; };
struct Entrant { char pad[0x104]; State state; };
extern "C" Entrant *func_0034C190(Self *, int);
extern "C" int func_003F60E8(void *) throw();
extern "C" int func_00345228(Entrant *);
extern "C" void func_0035DF80(char *, int, int, int);
extern "C" void DynamicsConductorLicense__ProcessLap0ControlLine(Self *self, int index, int time) {
    Entrant *e = func_0034C190(self, index);
    State *s = &e->state;
    if (s->flag == 0 && func_003F60E8((char *)self + 0xF818) != 0) {
        s->time = time;
        func_00345228(e);
        if (index == 0) return func_0035DF80(self->world, 4, 0, 0);
    }
}
