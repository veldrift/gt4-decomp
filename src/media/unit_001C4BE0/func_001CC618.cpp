/* compiler: ee-gcc2.96-no-strict-aliasing */
struct PEntry { short delta,index; void (*fn)(void*,float); };
struct PTable { char pad[0x10]; PEntry e; };
struct Progress { PTable *vt;int arg;char pad[8]; };
struct Entry { short delta,index; int (*fn)(void*,char*); };
struct File { Entry *vt; };
struct Ent { long words[8]; };
extern PTable D_00661718,D_0065CE00;
extern char D_00694DA8[];
extern "C" int func_001CC230(char*,File*,Ent*) throw();
extern "C" void func_0057DA20(char*,const char*,...);
extern "C" char *func_005A609C(char*,const char*);
static inline void progress(Progress *p,float f) { PEntry *e=&p->vt->e;e->fn((char*)p+e->delta,f); }
static inline int run(File *o,char *name) { Entry *e=o->vt+11;return e->fn((char*)o+e->delta,name); }
extern "C" int func_001CC618(char *self,File *file,int arg2) {
 Progress p;char path[0x50];Ent entries[18];
 p.arg=arg2;p.vt=&D_00661718;
 PTable *fin=&D_0065CE00;
 float start=0x1.999998p-3f;
 progress(&p,start);
 int n=func_001CC230(self,file,entries);
 if(n<0){p.vt=fin;return 0;}
 int i=0;
 if(n>0) {
  float total=(float)n;float step=0x1.333332p-1f;
  self+=0x24;
  do {char *buf=path;char *old=(char*)&entries[i]+0x1c;
   func_0057DA20(buf,D_00694DA8,self,old);
   float f=(float)i;i++;
   progress(&p,f*step/total+start);
   if(run(file,buf)) {p.vt=&D_0065CE00;return 0;}
  }while(i<n);
 } else self+=0x24;
 path[0]='/';func_005A609C(path+1,self);
 progress(&p,1.0f);
 if(run(file,path)) {p.vt=&D_0065CE00;return 0;}
 progress(&p,1.0f);p.vt=&D_0065CE00;return 1;
}
