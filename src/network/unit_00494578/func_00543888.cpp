struct Node { char pad[0x18]; int handle; };
extern "C" int func_00538830(int*) throw();
extern "C" void* func_00538988(int) throw();
extern "C" Node* func_00542A28(void*,unsigned) throw();
extern "C" int func_005428E8(int) throw();
extern "C" void func_00542DA8(int,int,void*,int) throw();
extern "C" void func_00546C28(void*,int,void*,int);
extern "C" int func_00543888(int id,unsigned key,int* data,int arg){
 int a[16],b[16];
 void* p; Node* node;
 if(!arg)goto fail;
 if(func_00538830(data))return -1;
 p=func_00538988(id);
 if(!p)return -1;
 node=func_00542A28(p,key);
 if(!node)return -1;
 if(func_005428E8(node->handle)) {
 fail: return -1;
 }
 func_00542DA8(node->handle,4,a,0x40);
 func_00546C28(data,arg,b,0x40);
 for(unsigned i=0;i<16;i++){
  if(a[i]!=b[i])goto fail;
 }
 return 0;
}
