#ifndef _UOIN_H_
#define _UOIN_H_

template <size_t N, typename T> struct Vector 
{
T m[N];
//-------------
public:
Vector()
{
for(size_t i=0;i<N;i++)
m[i]=T();
}
//~Vector();
Vector(const T *yy)
{
for(size_t i=0;i<N;i++)
//m[i] = yy();
m[i] = yy[i];
}
Vector(const std::initializer_list<T> &u)
{ 
auto it = u.begin(); 
for (size_t i = 0; i < N; i++) 
m[i] = *it++; 
}
//-------------
const T& operator[] (size_t i) const { assert(i < N); return m[i]; }
T& operator[] (size_t i) { assert(i < N); return m[i]; }

void load(const T *yy) { for (size_t i = 0; i < N; i++) m[i] = yy[i]; }
void save(T *yy) { for (size_t i = 0; i < N; i++) yy[i] = m[i]; }

};

#endif