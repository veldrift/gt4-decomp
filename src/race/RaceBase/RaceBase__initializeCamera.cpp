/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry {short delta,index;void *fn;};
struct Monitor {Entry *vt;};
struct Self {char p[0x64];Entry *vt;int gap;void *org;int dyn;void *other;long (*seed)();};
extern "C" void CameraSys__CameraManager__initRandomSeed(void *,int);
extern "C" void RaceBase__initMonitor(Self *);
extern "C" void RaceBase__initializeCamera(Self *self) {
 Entry *e=self->vt+46;
 ((void (*)(void *))e->fn)((char *)self+e->delta);
 Entry *f=self->vt+26;
 Monitor *m=((Monitor *(*)(void *,int))f->fn)((char *)self+f->delta,0);
 CameraSys__CameraManager__initRandomSeed(m,(int)self->seed());
 Entry *g=m->vt+21;
 ((void (*)(void *,void *))g->fn)((char *)m+g->delta,self->org);
 RaceBase__initMonitor(self);
}
