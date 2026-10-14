/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry {short delta,index;void (*fn)(void *);};
struct Other {int gap;Entry *vt;};
struct Self {char p[0x64];Entry *vt;int gap[3];Other *other;};
extern "C" void RaceBase___setSignal(void *,int);
extern "C" void RaceBase___terminate(Self *self) {
 Entry *e=self->vt+90;
 e->fn((char *)self+e->delta);
 Other *o=self->other;
 Entry *f=o->vt+8;
 f->fn((char *)o+f->delta);
 Entry *g=self->vt+86;
 g->fn((char *)self+g->delta);
 RaceBase___setSignal(self,1);
}
