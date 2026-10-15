typedef struct Entry { char pad[12]; int state; char pad10[12]; unsigned int value; } Entry;
typedef struct Event { void *object; int index; struct CallbackData *data; } Event;
typedef struct Global { char pad[0x130]; void (*callback)(Event *); struct CallbackData *data; } Global;
extern Global *D_0064B4B4;
Entry *func_00535C88(void *, unsigned int);
int func_00518B58(void *, int);
int func_00519748(void *object, unsigned int skip, int *out) {
    unsigned int best = 0x0fffffff;
    int i;
    Entry *p;
    int index;
    Global *g;
    void (*cb)(Event *);
    if (skip >= 64) return 0x17;
    if (!out) return 0x17;
    *out = 0x100;
    if (!object) return 0x17;
    for (i = 0; i < 64; i++) {
        if (skip != i) {
            p = func_00535C88(object, i);
            if (p && p->state == 4) {
                unsigned int v = p->value;
                if (v != 0 && v < best) {
                    *out = i;
                    best = v;
                }
            }
        }
    }
    if (*out != 0x100) {
        p = func_00535C88(object, *out);
        if (!p) return 0x17;
        index = *out;
        p->state = 5;
        func_00518B58(object, index);
        g = D_0064B4B4;
        cb = g->callback;
        if (cb) {
            Event e;
            e.object = object;
            e.index = *out;
            e.data = g->data;
            cb(&e);
        }
    }
    return 0;
}
