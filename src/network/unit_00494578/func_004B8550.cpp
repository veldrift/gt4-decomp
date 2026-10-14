/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Entry { signed char flag; char pad[3]; unsigned short start,end; };
struct Row { int kind; int pad4; unsigned short *text; char pad[0x214-12]; int count; Entry entries[64]; char tail[4]; };
struct Obj { int pad; int size; char pad8[24]; Row rows[2]; int selected,index; };
extern "C" void *func_005C15B0(int);
extern "C" char *func_004B9820(char *,const unsigned short *);
extern "C" void func_005C1628(int) throw();
extern "C" signed char func_004B8550(Obj *obj,char *dst) {
 Row *r=&obj->rows[obj->selected];
 for (;;) {
  int index=obj->index;
  int next;
  char *base=(char *)r+index*8;
  if (index<r->count) {
  next = index+1;
  obj->index=next;
  Entry *e=(Entry *)(base+0x218);
  if (r->kind==2 && e->flag==1) continue;
  unsigned short *buf=(unsigned short *)func_005C15B0(obj->size*2);
  int i;
  for (i=0;i<(short)e->end-(short)e->start;i++) {
   buf[i]=r->text[(short)e->start+i];
  }
  buf[(short)e->end-(short)e->start]=0;
  func_004B9820(dst,buf);
  func_005C1628((int)buf);
  return e->flag;
  } else return 0;
 }
 return 0;
}
