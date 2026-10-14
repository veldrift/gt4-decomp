/* compiler: ee-gcc2.96-nogcse */
typedef long long s64;
struct Big { s64 b[0x2f]; };
struct Raw32 { char b[0x20]; };
struct Snapshot { Big big; Raw32 raw; int fa8, fac, fb0, fb4, fb8, fbc; };
struct Item {
 char pad0[0x20]; Big big;
 char pad1[0x3448-0x198];
 int fa8, fac, fb0, fb4, fb8, fbc;
 char pad2[8]; Raw32 raw;
};
struct N2 { char pad[8]; Item **p; };
struct N1 { char pad[0x60]; N2 *p; };
struct Self { char pad[0x6c]; N1 *p; char gap[0xec10-0x70]; Snapshot prev, next; };
extern "C" void func_003EA410(Self *self) {
 Item *d = *self->p->p->p;
 self->prev.big = d->big;
 Raw32 *raw = &d->raw;
 self->prev.raw = *raw;
 self->prev.fa8 = d->fa8;
 self->prev.fac = d->fac;
 self->prev.fb0 = d->fb0;
 self->prev.fb4 = d->fb4;
 self->prev.fb8 = d->fb8;
 self->prev.fbc = d->fbc;
 int empty = 1;
 char *bytes = (char *)&self->next;
 for (unsigned int i=0; i<0x1b0; i++) {
  if (bytes[i] != 0) { empty=0; break; }
 }
 if (empty) self->next = self->prev;
 d->big = self->next.big;
 *raw = self->next.raw;
 d->fa8 = self->next.fa8 != 0;
 d->fac = self->next.fac;
 d->fb0 = self->next.fb0 != 0;
 d->fb4 = self->next.fb4 != 0;
 d->fb8 = self->next.fb8 != 0;
 d->fbc = self->next.fbc;
}
