struct Node { int a; Node *next; };
struct Queue { int a; Node *cursor; Node *end; int d; int ready; Node *tail; };
extern "C" Node *func_0052DD60(Queue *);
extern "C" int func_0052D5A8(Queue *, Node *, int) throw();
extern "C" int func_0052D7E8(Queue *q, int arg) {
    if (!q || !q->ready || !q->tail || !q->end) return 2;
    Node *n = func_0052DD60(q);
    if (!n) return 300;
    int r = func_0052D5A8(q, n, arg);
    if (r) return r;
    n = func_0052DD60(q);
    if (!n) return 300;
    Node *next = n->next;
    if (next) {
        q->tail = next;
        n->next = next->next;
        next->next = n;
    }
    if (q->cursor == q->end) q->cursor = 0;
    return 0;
}
