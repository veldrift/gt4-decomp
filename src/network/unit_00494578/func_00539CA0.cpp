extern "C" void *func_005A4724(void *, const void *, unsigned);
struct State { unsigned unused, end, current, unusedC; int error; };
extern "C" void func_00539CA0(int mode, State *s, void *buffer, unsigned size) {
 if (s->error == 0) {
  unsigned end = s->end;
  unsigned current = s->current;
  if (current >= end) goto invalid;
  if (current == 0) { s->error = 2; return; }
  if (buffer == 0) {
invalid:
   s->error = 2; return;
  }
  if (end - current < size) { s->error = 8; return; }
  if (mode == 1) func_005A4724((void *)current, buffer, size);
  else if (mode == 2) func_005A4724(buffer, (void *)current, size);
  s->current += size;
 }
}
