/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Self { int active; char *data; int size, capacity, key, value, x18; };
extern char *D_00623A3C;
extern int D_00623A40, D_00623A38;
extern "C" void func_004625A8(Self *, void *, int) throw();
extern "C" void func_00462670(Self *self, void *src, int flag) {
 if (self->active != 0) return func_004625A8(self, src, flag);
 char **data = &D_00623A3C;
 int *capacity = &D_00623A40;
 int *key = &D_00623A38;
 self->data = *data;
 self->capacity = *capacity;
 self->key = *key;
 self->x18 = 0;
 func_004625A8(self, src, flag);
 *data = self->data + self->size;
 *capacity -= self->size;
 *key += self->value;
}
