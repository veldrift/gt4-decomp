/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *, void *, int, int); };
struct Vt { void *f0; };
struct GT { char pad[0x12C]; char *vt; };
struct Entry { char pad[0x60]; int *p; };
extern "C" void RaceOrganization__defaultPosition(void *);
extern "C" void RaceOrganization__movePosition(void *, int, int);

extern "C" void RaceGTmodeInformation__finishEntryCar(GT *self, Entry *e) {
    int *p = e->p;
    VEntry *v = (VEntry *)(self->vt + 0x80);
    v->fn((char *)self + v->delta, e, 1, *p);
    RaceOrganization__defaultPosition(e);
    RaceOrganization__movePosition(e, 0, *p - 1);
}
