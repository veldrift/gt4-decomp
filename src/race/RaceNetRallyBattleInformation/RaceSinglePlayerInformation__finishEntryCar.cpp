/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VE { short delta; short idx; void (*fn)(void *, void *, int, int); };
struct Info { char p[0x60]; int *cnt; };
struct Race { char p[0x12C]; char *vt; };

extern "C" void RaceOrganization__defaultPosition(void *s);
extern "C" void RaceOrganization__movePosition(void *s, int from, int to);

extern "C" void RaceSinglePlayerInformation__finishEntryCar(Race *self, Info *info) {
    VE *e = (VE *)(self->vt + 0x80);
    int *cnt = info->cnt;
    e->fn((char *)self + e->delta, info, 1, *cnt);
    RaceOrganization__defaultPosition(info);
    RaceOrganization__movePosition(info, 0, *cnt - 1);
}
