struct Ent {unsigned int key;int val;};
struct Inner {char pad[8];int count;char pad2[4];struct Ent ents[1];};
extern "C" int SPEC_DATABASE__DatabaseTable__searchNumber(void**,unsigned int);
extern "C" int func_00449210(void**arg0,unsigned int key){int idx=SPEC_DATABASE__DatabaseTable__searchNumber(arg0,key);if(idx==-1)return idx;for(;;){int prev=idx-1;int k=-1;if(prev>=0){struct Inner *t=(struct Inner*)*arg0;if(prev<t->count)k=*(int*)((char*)t+(prev<<3)+0x10);}if((int)key!=k)break;if(idx==0)break;idx=prev;}return idx;}
