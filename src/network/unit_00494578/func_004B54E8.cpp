/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Record { signed char type; char pad[7]; };
struct Block { char pad[0x214]; int count; Record items[64]; int done; };
struct Obj { char pad[0x20]; Block blocks[2]; int current; };
extern "C" void func_004B5B38(Obj *,Record *);
extern "C" void func_004B54E8(Obj *self) {
 Block *b=&self->blocks[1-self->current];
 int finished;
 do {
  int n=b->count;
  finished=1;
  int i=0;
  if (n>0) {
   do {
    Record *r=&b->items[i];
    int type=r->type;
    if(type==2) goto handle;
    if(type==3) goto handle;
    if(type==4) goto handle;
    if(type==5) {
     handle: func_004B5B38(self,r); finished=0; break;
    }
    ++i;
   } while(i<n);
  }
 } while(!finished);
 b->done=1;
}
