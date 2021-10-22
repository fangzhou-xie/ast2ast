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
#ifndef VEC_H
#define VEC_H

#include "util.hpp"

/*
Vector module
*/
template< typename T, typename R = std::vector<T> >
class VEC {

private:

public:

  // Constructors
  // ================================================================
  R d;
  bool subsetted;
  std::vector<int> indices;

  // for Matrix
  int ncols;
  int nrows;

  VEC(const int n) : d(n), subsetted(0) {}
  VEC(const int n, const double value) : d(n, value), subsetted(0) {}
  VEC(const R& other_vec) : d(other_vec), subsetted(0) {}
  VEC(const R& mat, int nrows_, int ncols_) : d(mat), subsetted(0), ncols(ncols_), nrows(nrows_) {}
  VEC() : subsetted(0) {}
  //VEC(SUBSET<T>& inp) : d(inp.sub), subsetted(0) {}
  VEC(SUBSET<T>&& inp) : d(inp.sub), subsetted(0) {}

  void vecinit(std::vector<T>& input) {
    d.resize(input.size());
    for(int i = 0; i < d.size(); i++) {
      d[i] = input[i];
    }
    subsetted = false;
  }

  // ================================================================
  VEC& operator=(const T &dob) {
      d.resize(1);
      d[0] = dob;
    subsetted = false;
    return *this;
  }

  VEC& operator=(const SUBSET<T> other_vec) {

    while(other_vec.sub.size() > d.size()) { // >=
      d.push_back(0);
    }

    if(subsetted == false) {
      for(int i = 0; i < d.size(); i++) {
        d[i] = other_vec.sub[i];
      }
    } else {

      for(int i = 0; i < indices.size(); i++) {
        d[indices[i]] = other_vec.sub[indices[i]];
      }
    }

    subsetted = false;
    return *this;
  }

  template<typename T2, typename R2>
  VEC& operator=(const VEC<T2, R2> &other_vec) {

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