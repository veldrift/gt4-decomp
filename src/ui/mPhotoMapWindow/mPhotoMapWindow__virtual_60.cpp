/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta; short index; void (*fn)(void *); };
struct S { int pad0; VEntry *vt; };
extern "C" int func_00206868(S *) throw();
extern "C" int func_0025C300(S *);
extern "C" void mSceneViewFace__virtual_60(S *);
extern "C" void mPhotoMapWindow__virtual_60(S *self) {
 S *p = (S *)func_00206868(self);
 if (p != 0) {
  do {
   VEntry *e = &p->vt[61];
   e->fn((char *)p + e->delta);
   p = (S *)func_0025C300(p);
  } while (p != 0);
 }
 mSceneViewFace__virtual_60(self);
}
