/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Event { int a[6]; int type; int b[3]; signed char flag; char pad[3]; };
struct Queue { char pad[0x1d8]; Event events[16]; char rest[0x5b30-0x1d8-16*44]; int count; };
struct Obj { char pad[0x5a8]; Queue *queue; };
extern Obj D_00645570;
extern char D_006C06C8[];
extern "C" int func_004F0C38(Obj *,const char *) throw();
extern "C" void func_004F0B08(Obj *,Event *) throw();
extern "C" void func_004F87E8(Obj *,int);
extern "C" void func_004F5B78(Event *event,Obj *obj) {
 if(obj==0) obj=&D_00645570;
 if(func_004F0C38(obj,D_006C06C8)) return func_004F0B08(obj,event);
 int type=event->type;
 int handled=0;
 if(type<0 || type==1) {
  func_004F87E8(obj,type);
  handled=1;
 }
 if(handled) return func_004F0B08(obj,event);
 int *count=&obj->queue->count;
 int n=(*count)++;
 if(n<16) obj->queue->events[n]=*event;
 if(event->flag) {
  func_004F87E8(obj,event->type);
  if(event->flag) {
   func_004F87E8(obj,event->type);
   func_004F0B08(obj,event);
  }
 }
}
