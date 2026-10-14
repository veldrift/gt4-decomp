/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { int x; unsigned int value; };
struct Node { Node *next; Data *data; };
extern Node *D_00621314;
extern unsigned int D_00621310;
static inline void insert(Node *&head, Node *node) { node->next=head; head=node; }
static inline void maximize(unsigned int &max, Data *data) { unsigned int value=data->value; if(max<value) max=value; }
extern "C" void func_00387B30(Node *node, Data *data) {
    node->data=data;
    insert(D_00621314,node);
    maximize(D_00621310,data);
}
