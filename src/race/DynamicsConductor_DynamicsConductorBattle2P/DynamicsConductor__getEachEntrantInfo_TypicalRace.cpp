/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { char pad[0x1cc]; int active; };
struct Entrant { char pad[0x343c]; Info *info; char pad3440[8]; int value; };
struct Entries { char pad[8]; Entrant **items; };
struct Race { char pad[0x60]; Entries *entries; };
struct Self { Race *race; char pad[0xcbd8]; unsigned char mode; };
extern "C" int DynamicsConductor__IsBSpecRace(Self *);
extern "C" int func_003C0E78(Race *);
extern "C" void DynamicsConductor__getEachEntrantInfo_TypicalRace(Self *self, int index, int *a, int *b, unsigned int *kind, int *c) {
    Race *race = self->race;
    Entrant *entrant = race->entries->items[index];
    if (entrant->info->active) {
        *kind = 0;
        if (self->mode == 4) *kind = 2;
        else if (DynamicsConductor__IsBSpecRace(self)) *kind = 1;
    } else {
        *kind = 2;
        if (func_003C0E78(race)) *kind = 4;
    }
    int typical = *kind < 2U;
    if (typical) { *a = 0; *b = entrant->value; }
    else { *a = 0; *b = 0; }
    *c = 0;
}
