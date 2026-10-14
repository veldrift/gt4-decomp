struct Widget;
extern "C" int func_00207AB0(Widget*,float*,float*);
extern "C" Widget* func_00206868(Widget*),*func_0025C300(Widget*);
extern "C" int func_00265D98(Widget*);
extern "C" void mWidget__getWindowSize(Widget*,float*,float*),mWidget__setWindowPosition(Widget*,float,float),func_0025B4C8(Widget*,float,float);
extern "C" void func_00207B70(Widget* self,int horizontal,int count,float border,float gap){
 float width=0,height=0;
 int total=func_00207AB0(self,&width,&height);
 int columns,rows;
 if(horizontal){columns=count;rows=(total+columns-1)/columns;}
 else{rows=count;columns=(total+rows-1)/rows;}
 func_0025B4C8(self,width*columns+(border+border)+gap*(columns-1),height*rows+(border+border)+gap*(rows-1));
 float x=border+width*0.5f;
 float y=border+height*0.5f;
 int cell=0;
 Widget* child=func_00206868(self);
 while(child){
  if(!func_00265D98(child)){
   float childWidth,childHeight;
   mWidget__getWindowSize(child,&childWidth,&childHeight);
   mWidget__setWindowPosition(child,x-childWidth*0.5f,y-childHeight*0.5f);
   if(horizontal){
    ++cell;
    x+=width+gap;
    if(cell>=columns){cell=0;x=border+width*0.5f;y+=height+gap;}
   }else{
    ++cell;
    y+=height+gap;
    if(cell>=rows){cell=0;y=border+height*0.5f;x+=width+gap;}
   }
  }
  child=func_0025C300(child);
 }
}
