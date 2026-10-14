/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { char pad[0x178]; int f178; };
struct GT { char pad[0x130]; char blk[1]; };
struct Entry { char pad[0x14]; int f14; char pad18[8]; Sub sub; };
extern "C" void RaceInformation__updateEntryCar(void);
extern "C" void func_004452F8(void *, void *);

extern "C" void RaceGTmodeInformation__updateEntryCar(GT *self, Entry *e) {
    RaceInformation__updateEntryCar();
    if (e->f14)
        return;
    Sub *s = &e->sub;
    func_004452F8(s, self->blk);
    s->f178 = 0x100;
}
