struct Object{virtual float d0(float);virtual float d1(float);virtual float d2(float);virtual float x(float);virtual float y(float);virtual float z(float);};
extern "C" void** VisionList__getVoronoi(void*,float,float,float);extern "C" void CourseData__render_course_2(void*,void*,int);
static inline void* convert(void* source,float x,float y,float z){void* result=0;if(source)result=*VisionList__getVoronoi(source,x,y,z);return result;}
extern "C" void CourseData__render_course(void* self,void* source,Object* object,int mode){float x=object->x(0.0f);float y=object->y(0.0f);float z=object->z(0.0f);CourseData__render_course_2(self,convert(source,x,y,z),mode);}
