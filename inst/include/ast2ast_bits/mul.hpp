/*
R package ast2ast
Copyright (C) 2021 Konrad Krämer

This file is part of R package ast2ast


ast2ast is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with pso
If not see: https://www.gnu.org/licenses/old-licenses/gpl-2.0.html#SEC4
*/

#ifndef MUL
#define MUL

#include "vec.hpp"


template<typename T, typename L, typename R>
class VVTIMES {

private:
  const L& l;
  const R& r;
  std::vector<int> indices1;
  std::vector<int> indices2;

public:
  VVTIMES(const L &a, const R &b ) :
     l(a), r(b) {
       if(l.size() > r.size()) {
         ass((l.size() % r.size()) == 0, "Vector is not multiple of other vector");
         indices1.resize(l.size());
         indices2.resize(l.size());
         for(int i = 0; i < indices2.size(); i++) {
           indices1[i] = i;

           int times = floor(i/r.size());
           indices2[i] =  i - times*r.size();
         }
       } else if(r.size() > l.size()) {
         ass((l.size() % r.size()) == 0, "Vector is not multiple of other vector");
         indices1.resize(r.size());
         indices2.resize(r.size());
         for(int i = 0; i < indices2.size(); i++) {
           indices2[i] = i;

           int times = floor(i/l.size());
           indices1[i] =  i - times*l.size();
         }
     } else if(r.size() == l.size()) {
       indices1.resize(l.size());
       indices2.resize(r.size());
       for(int i = 0; i < indices2.size(); i++) {
         indices1[i] = i;
         indices2[i] = i;
       }
     }
   }

   T operator[](const int i) const {
     return l[indices1[i]] * r[indices2[i]];
   }

   int size() const {
     return l.size();
   }

};


template<typename T, typename L, typename R>
VEC< T, VVTIMES< T, L, R > > operator*(const VEC<T, L>& a, const VEC<T, R>& b) {
    return VEC<T, VVTIMES<T, L, R> > (VVTIMES<T, L, R>(a.data(), b.data() ) );
}


template<typename T, typename L, typename R>
class VSTIMES {

private:
  const L& l;
  const R& r;

public:
  VSTIMES(const L &a, const R &b ) :
     l(a), r(b) {}

   T operator[](const int i) const {
     return l[i] * r;
   }

   int size() const {
     return l.size();
   }

};

template<typename T, typename L, typename R>
VEC< T, VSTIMES< T, L, R > > operator*(const VEC<T, L>& a, const R& b) {
    return VEC<T, VSTIMES<T, L, R> > (VSTIMES<T, L, R>(a.data(), b ) );
}

template<typename T, typename L, typename R>
VEC< T, VSTIMES< T, L, R > > operator*(const L& a, const VEC<T, R>&  b) {
    return VEC<T, VSTIMES<T, L, R> > (VSTIMES<T, L, R>(a, b.data() ) );
}




#endif
