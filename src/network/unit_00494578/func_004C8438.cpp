/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[0x10]; unsigned char start, end; char pad12[6]; int value; Node *next; };
extern unsigned char D_006B9C10[];
extern "C" {
int func_004C2758(int,int,int,Node *) throw();
int func_004C57A8(unsigned short *,int) throw();
Node *func_004C8C20(void *,int);
void func_004C8C38(void *,Node *);
int func_004C8ED0(unsigned short *);
int func_004C9580(void *,int);
}
static inline Node *next_node(Node *p) { return p->next; }
extern "C" int func_004C8438(void *ctx, Node **list, unsigned short *str, unsigned char *arg3) {
    Node *tail = 0;
    Node *head = 0;
    if (arg3 && func_004C9580(arg3+4,8) != 1) return 0;
    int end = func_004C8ED0(str);
    Node *first = func_004C8C20(ctx,0x20);
    if (!first) return 0x80000303;
    first->end = end;
    first->start = 0;
    first->value = 0;
    func_004C2758(1,end,0,first);
    int start;
    if (!arg3) {
        Node *node = func_004C8C20(ctx,0x20);
        if (!node) { func_004C8C38(ctx,first); return 0x80000303; }
        func_004C2758(0,end,0,node);
        node->end = end;
        node->start = 0;
        start = 0;
        node->value = 0;
        node->next = *list;
        first->next = node;
    } else {
        first->start = *arg3;
        first->end += *arg3;
        start = *arg3;
        first->next = *list;
    }
    *list = first;
    int type = func_004C57A8(str,end);
    if (type >= 0) {
        int total = end + start;
        unsigned char *p = D_006B9C10 + type*6;
        for (int i=0; i<6; i++) {
            Node *node = func_004C8C20(ctx,0x20);
            if (!node) return 0x80000303;
            int code = *p++;
            func_004C2758(code,end,0,node);
            node->end = total;
            node->start = start;
            node->value = 0;
            node->next = 0;
            if (i == 0) { head = node; tail = head; }
            else { tail->next = node; tail = node; }
        }
        if (type == 2) {
            tail = head;
            while (tail->next) { tail = tail->next; }
            tail->next = *list;
            *list = head;
        } else {
            tail = *list;
            Node *next = next_node(tail);
            if (next) {
                do { next = next_node(tail); tail = next; } while (next_node(tail));
            }
            tail->next = head;
        }
    }
    return 0;
}
