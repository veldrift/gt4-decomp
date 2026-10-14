struct Node { void *data; int pad; Node *next; };
struct Bucket { int pad; Node *head; };
struct S { char pad[0x3c]; unsigned count; int size; int p44; Bucket *buckets; char p4c[12]; unsigned entries; };
struct Args { unsigned capacity; char *dst; unsigned (*callback)(char *, void *, void *); void *context; };
extern "C" int func_005A4724(void *, const void *, unsigned);
extern "C" int func_00511150(S *s, Args *a) {
 unsigned used = 0;
 unsigned i;
 if (!s) goto invalid;
 if (!a) return 1;
 if (a->dst) goto valid;
invalid:
 return 1;
valid:;
 unsigned (*cb)(char *, void *, void *) = a->callback;
 char *dst = a->dst;
 if (cb) {
  for (i=0; i < s->count; ++i) {
   for (Node *n=s->buckets[i].head; n; n=n->next) {
    if (used >= a->capacity) return 8;
    unsigned size = cb(dst,n->data,a->context);
    used += size;
    dst += size;
   }
  }
 } else {
  unsigned size;
  unsigned total = s->entries;
  size = s->size;
  if (a->capacity < total * size) return 8;
  for (i=0; i < s->count; ++i) {
   for (Node *n=s->buckets[i].head; n; n=n->next) {
    size = s->size;
    func_005A4724(dst,n->data,size);
    dst += s->size;
   }
  }
 }
 return 0;
}
