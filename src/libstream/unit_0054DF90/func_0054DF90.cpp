/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self {
 char pad0[0x80]; unsigned int size; void *entry; char p88[8]; char name[0x80]; char *str; char p114[0x190-0x114]; char *base; char *cur; char p198[0x3F4-0x198]; int mode;
};
struct Block { char bytes[0xA000]; };
extern "C" int func_005ADB90();
extern "C" int func_00575E60(int,int);
extern "C" int func_0054E290(void*,void*,void*,void*,void*);
extern "C" int func_005A6AB0(void*,void*,int) throw();
extern "C" int func_005ADB30(int,int);
extern "C" void func_0054F388(int*,void*,int,char**);
extern "C" int func_00563408(int);
extern "C" void func_0054F420(void*,int);
extern "C" int func_0054EFF8(void*,int*,int*,long*,long*);
extern "C" void func_0054F648();
extern "C" void func_0054DF90(Self *self,void *name,int size) {
 int x,y; long z,w; int old;
 int state=func_005ADB90();
 self->base=(char*)func_00575E60(0x40,size);
 func_0054E290(self,name,&self->entry,&self->size,&self->str);
 func_005A6AB0(self->name,name,0x80);
 char *end=self->base+size;
 old=func_005ADB30(state,self->mode);
 self->cur=self->base;
 func_0054F388(0,self->entry,(self->size+0x7FF)>>11,&self->str);
 char *buf=(char*)func_00563408(0);
 do {
  func_0054F420(buf,0xA000);
  *(Block*)self->cur=*(Block*)buf;
  int i; char *p;
  for(i=0,p=buf;i<8;i++,p+=0x1400) {
   if(func_0054EFF8(p,&x,&y,&z,&w)) goto done;
  }
  self->cur+=0xA000;
 } while((unsigned int)self->cur<(unsigned int)end);
 done:
 func_005ADB30(state,old);
 func_0054F648();
 self->cur=self->base;
}
