/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { char p[0x70]; void *race; };
struct Obj { char p[0x6c]; Info *info; char q[0xd68-0x70]; int mode; };
extern "C" int RaceBase__getLicenseSubNumber(int);
extern "C" int SPEC_DATABASE__RaceSpec__getRaceLabel(void *);
extern "C" int RaceMission__getRaceMode(Obj *o, int *p) {
 *p=-1;
 *p=RaceBase__getLicenseSubNumber(SPEC_DATABASE__RaceSpec__getRaceLabel(o->info->race));
 return o->mode;
}
