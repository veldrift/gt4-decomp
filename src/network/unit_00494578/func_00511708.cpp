struct Node { void *value; Node *prev,*next; };
struct Bucket { Node *a,*head; };
struct Table { char pad[0x3c]; int count; int p40; void *context; Bucket *buckets; int (*hash)(int,int,void *); int (*equal)(void *,int,void *); char p54[8]; Node *cache; };
extern "C" int func_00511708(Table *t,int key,void **out) {
    if (!t || !out) return 1;
    if (t->cache && t->equal(t->cache->value,key,t->context)) {
        *out = t->cache->value;
        return 0;
    }
    Node *n = t->buckets[t->hash(t->count,key,t->context)].head;
    while (n) {
        if (t->equal(n->value,key,t->context)) {
            t->cache = n;
            *out = n->value;
            return 0;
        }
        n = n->next;
    }
    return 3;
}
