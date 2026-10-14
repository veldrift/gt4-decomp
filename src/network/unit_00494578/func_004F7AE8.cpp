/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block { char data[128]; };
struct Queue { char pad[0x5318]; Block items[16]; char tail[0x24]; int read,count; };
struct Obj { char pad[8]; char mutex[0x5A8-8]; Queue *queue; };
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" int func_004F7AE8(Obj *self,Block *out) {
 if(!self->queue) return 0;
 {
  void *mutex=self->mutex;
  int ok=0;
  func_00576788(mutex);
  if(self->queue->count>0) {
   *out=self->queue->items[self->queue->read];
   if(++self->queue->read>=16) self->queue->read=0;
   self->queue->count--;
   ok=1;
  }
  func_005767C0(mutex);
  return ok;
 }

}
