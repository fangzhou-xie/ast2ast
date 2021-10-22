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

You should have received a copy of the GNU General Public License along with ast2ast
If not see: https://www.gnu.org/licenses/old-licenses/gpl-2.0.html#SEC4
*/

#ifndef SPAN_H
#define SPAN_H

#include "util.hpp"

template< typename T>
class SPAN {

  T* sp;
  int sz;

  public:
  SPAN(T* p, int size_) : sz(size_), sp(p) {}

  T& operator[](int i) {
    return sp[i];
  }

  int size() {
    return sz;
  }

};






/*
Vector module
*/
template< typename T, typename R = SPAN<T> >
class VECSPAN {

public:

  // Constructors
  // ================================================================
  R d;
  bool subsetted;
  std::vector<int> indices;

  VECSPAN(const int n) : d(n), subsetted(0) {}
  VECSPAN(const int n, const double value) : d(n, value), subsetted(0) {}
  VECSPAN(const R& other_vec) : d(other_vec), subsetted(0) {}
  VECSPAN() :d(1) {}
  // ================================================================


  // Operator=
  // ================================================================
  T& operator=(const T &other_vec) {

    while(other_vec.size() >= d.size()) {
      d.push_back(0);
    }

    if(subsetted == false) {
      for(int i = 0; i < d.size(); i++) {
        d[i] = other_vec[i];
      }
    } else {
      for(int i = 0; i < indices.size(); i++) {
        d[indices[i]] = other_vec[indices[i]];
      }
    }

    subsetted = false;
    return *this;
  }

  template<typename T2, typename R2>
  VECSPAN& operator=(const VEC<T2, R2> &other_vec) {

    while(other_vec.size() > d.size()) {
      d.push_back(0);
    }

    if(subsetted == false) {
      for(int i = 0; i < d.size(); i++) {
        d[i] = other_vec[i];
      }
    } else {
      for(int i = 0; i < indices.size(); i++) {
        d[indices[i]] = other_vec[i];
      }
    }

    subsetted = false;

    return *this;
  }
  // ================================================================


  // getter methods
  // ================================================================
  int size() const {
   return d.size();
 }

 T operator[](int i) const {
   return d[i];
 }

 T& operator[](int i) {
   return d[i];
 }

 T operator()(int i) const {
   return d[i];
 }

 T& operator()(int i) {
   return d[i];
 }

 // access as R user
 T& ui_g(int i) {
   return d[i-1];
 }

 T& ui_g(int i) const {
   return d[i-1];
 }

 int ui_length() {
   return d.size();
 }

 const R& data() const {
   return d;
 }

 R& data() {
   return d;
 }

 T* pointer() {
   return d.data();
 }
// ================================================================


// subsetting
// ================================================================
 void data_sub(std::vector<double>& temp) const{
    temp.resize(indices.size());
    for(int i = 0; i < temp.size(); i++) {
      temp[indices[i]] = d[indices[i]];
    }
}


VECSPAN& subset(std::vector<int> inp) {
   subsetted = true;
   indices.resize(inp.size());
   for(int i = 0; i < inp.size(); i++) {
     indices[i] = inp[i];
   }
   return *this;
}

VECSPAN& subset(int start, int end) {
  subsetted = true;
  indices.resize(end - start + 1);
  for(int i = 0; i < indices.size(); i++) {
    indices[i] = start + i;
  }
  return *this;
}

// called by R User --> index start at 1 --> correct?
VECSPAN& ui_subset(std::vector<int> inp) {
   subsetted = true;
   indices.resize(inp.size());
   for(int i = 0; i < inp.size(); i++) {
     indices[i] = inp[i] - 1;
   }
   return *this;
}

// called by R User --> index start at 1
VECSPAN& ui_subset(int start, int end) {
  subsetted = true;
  indices.resize((end -1) - (start -1) + 1);
  for(int i = 0; i < indices.size(); i++) {
    indices[i] = start + i -1;
  }
  return *this;
}

bool is_subsetted() const {
  return subsetted;
}

// ================================================================

// plotting
// ================================================================
friend std::ostream& operator<<(std::ostream& os, const VEC& v) {
  if(v.subsetted == true) {
    for(int i = 0; i < v.indices.size(); i++) {
      os << v[v.indices[i]] << std::endl;
    }
  } else {
    for(int i = 0; i < v.size(); i++) {
      os << v[i] << std::endl;
    }
  }
      return os;
};
// ================================================================

};


#endif