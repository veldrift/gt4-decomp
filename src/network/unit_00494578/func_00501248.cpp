struct Item{char pad[20];char name[1];};struct Node{Item* item;int a;Node* next;};extern "C" int func_0057F238(const char*,const char*);
extern "C" Node* func_00501248(Node** list,const char* name){Node* node=*list;while(node){if(!func_0057F238(node->item->name,name))return node;node=node->next;}return 0;}
