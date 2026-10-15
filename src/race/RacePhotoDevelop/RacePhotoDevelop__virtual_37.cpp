/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Info { char p[0x60]; int *count; };
struct Item { int x; char p[0x2e0]; };
struct Obj { char p[0x6c]; Info *info; char q[0x23450-0x70]; int x; char r[0x23734-0x23454]; Item items[8]; };
extern "C" void RaceSinglePlayer__initialize(Obj *);
extern "C" void RacePhotoDevelop__virtual_37(Obj *o) {
 RaceSinglePlayer__initialize(o);
 o->x=0;
 int i=0;
 Info *info=o->info;
 while (i<*info->count) {
  o->items[i].x=0;
  char *b=(char *)o+i*0xe20;
  *(int *)(b+0x253c4)=0;
  *(int *)(b+0x2a884)=0;
  i++;
  info=o->info;
 }
}
