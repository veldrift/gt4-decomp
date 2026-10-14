/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void (*fn)(void *); };
struct Self { int x0; void *data; int size; int xc; int key; int value; int x18; VEntry *vt; };
struct Src { int x0, x4, size, xc, value; };
extern "C" void func_005595C8(void *, int);
extern "C" void free(void *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_004625A8(Self *self, Src *src, int flag) {
 int size, value;
 if (flag == 0) {
  size = src->size;
  value = src->value;
  func_005A4724(self->data, src, size);
 } else {
  func_005595C8(src, self->key);
  size = src->size;
  void *data = self->data;
  value = src->value;
  func_005A4724(data, src, size);
  func_005595C8(data, self->key);
 }
 self->size = size;
 self->value = value;
 free(src);
 VEntry *e = self->vt + 2;
 e->fn((char *)self + e->delta);
}
