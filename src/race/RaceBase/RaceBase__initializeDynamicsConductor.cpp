/* compiler: ee-gcc2.96-nogcse */
struct Entry {short delta,index; void *fn;};
struct CarRecord {char p[0x18];void *car;};
struct Cars {int count;int gap;CarRecord **list;};
struct Org {char p[0x60];Cars *cars;};
struct Dynamics {char p[0x10140];char *vt;};
struct Controller {char p[0x1d4];int manual;};
struct Self {char p[0x64];char *vt;int gap;Org *org;Dynamics *dyn;char q[0xc54];int value;};
extern "C" int Automobile__isFullManualTransmission(void *);
extern "C" void RaceDisplayLapDiffEvent__structor_2(void *);
extern "C" void RaceOrganization__inputInitialize(void *, void *);
extern "C" void RaceBase__initializeDynamicsConductor(Self *self) {
 int i=0;
 Org *org=self->org;
 RaceOrganization__inputInitialize(org,self);
 Dynamics *dyn=self->dyn;
 Entry *e=(Entry *)(dyn->vt+0xe0);
 ((void (*)(void *,int))e->fn)((char *)dyn+e->delta,self->value);
 RaceDisplayLapDiffEvent__structor_2(org);
 int count=org->cars->count;
 if (i<count) do {
  CarRecord *rec=org->cars->list[i];
  void *car=rec->car;
  Entry *f=(Entry *)(self->vt+0x240);
  Controller *c=((Controller *(*)(void *,int))f->fn)((char *)self+f->delta,i+0x100);
  i++;
  c->manual=Automobile__isFullManualTransmission(car)!=0;
 } while (i<count);
}
