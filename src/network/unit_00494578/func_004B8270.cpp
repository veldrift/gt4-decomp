/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { int x[128]; };
struct Entry { unsigned char a,b; unsigned short c,d,e; };
struct Rec { int a,b; void *p; int pad; Block block; int x,count; Entry entries[64]; int tail; };
struct Obj { int zero,size; char pad[0x18]; Rec rec[2]; int cur,unused,flag; };
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_004B8270(Obj *o) {
 if(o->flag == 0) {
  int next = 1-o->cur;
  o->cur=next;
  Rec *src = &o->rec[next];
  Rec *dst = &o->rec[1-next];
  dst->a=src->a;
  dst->b=src->b;
  func_005A4724(dst->p,src->p,o->size*2);
  dst->block=src->block;
  dst->x=src->x;
  dst->count=src->count;
  int i=0;
  if (i < dst->count) {
  Entry *s=src->entries;
  Entry *d=dst->entries;
  do {
   d->a=s->a;
   d->b=s->b;
   d->c=s->c;
   d->d=s->d;
   d->e=s->e;
   i++; s++; d++;
  } while(i < dst->count);
  }
  dst->tail=src->tail;
 }
}
