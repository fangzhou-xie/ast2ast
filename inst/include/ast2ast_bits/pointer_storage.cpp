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

#include <iostream>
#include <iterator>
#include <memory>
#include <vector>

/*
class iterator
*/
template<typename T>
class It {
public:
 T* p;
 T& operator*() { return *p; }

 bool operator != (const It& rhs) {
   return p != rhs.p;
 }
 void operator ++() { ++p; }
};

/*
class which is only a copy of a pointer or used as vector storing data via pointer
*/
template<typename T>
class STORE {

public:
  T* p;
  int sz; // size
  int capacity;
  bool todelete;

  // Constructors
  STORE(const int n) {
    sz = n;
    capacity = sz;
    p = new T[n];
    todelete = true;
  }

  STORE(const int n, const double value) {
    sz = n;
    capacity = sz;
    p = new T[n];
    for(int i = 0; i < sz; i++) {
      p[i] = value;
    }
    todelete = true;
  }

  STORE(std::vector<double> inp) {
    sz = inp.size();
    capacity = sz;
    p = new T[sz];
    for(int i = 0; i < sz; i++) {
      p[i] = inp[i];
    }
    todelete = true;
  }

  STORE(const int n, T* pinp, bool copy) {
    if(copy == false) {
      sz = n;
      capacity = sz;
      p = pinp;
      todelete = false;
    } else if(copy == true) {
      sz = n;
      capacity = sz;
      p = new T[n];
      for(int i = 0; i < sz; i++) {
        p[i] = pinp[i];
      }
      todelete = true;
    }
  }

  // Destructors
  ~STORE() {
    if(todelete == true) {
        delete [] p;
    }
  }

  int size() {
    return sz;
  }

  T* data() {
    return p;
  }

  // 1 indexed array
  T operator[](int pos) {
    pos--;
    if(pos < 1) {
      //Rcpp::stop("Error: out of boundaries --> value below 1");
    } else if(pos >= sz) {
      //Rcpp::stop("Error: out of boundaries --> value beyond size of vector");
    }
    return p[pos];
  }

  // 1 indexed array
  T operator()(int pos) {
    pos--;
    if(pos < 1) {
      //Rcpp::stop("Error: out of boundaries --> value below 1");
    } else if(pos >= sz) {
      //Rcpp::stop("Error: out of boundaries --> value beyond size of vector");
    }
    return p[pos];
  }

  void resize(int new_size) {
    delete [] p;
    p = new T[new_size*2];
    sz = new_size;
    capacity = new_size*2;
  }

  void realloc(int new_size) {
    T* temp;
    int temp_size;
    temp = new T[sz];
    for(int i = 0; i < sz; i++) {
      temp[i] = p[i];
    }

    delete [] p;
    p = new T[new_size];
    for(int i = 0; i < sz; i++) {
      p[i] = temp[i];
    }

    sz = new_size;
  }

  void push_back(T input) {
    if(sz == capacity) {
      realloc(sz*2);
      capacity = sz;
    } else if(sz < capacity) {
      p[sz] = input; //p starts counting at 0!!!
    }
  }

  //https://www.nextptr.com/tutorial/ta1208652092/how-cplusplus-rangebased-for-loop-works
  auto begin() const {
    return It<T>{p};
  }

  auto end() const {
    return It<T>{p + sz};
  }


};




int main() {

  STORE<double> s(10, 4.);

  double counter = 0.0;
  for(auto& i: s) {
    i = counter;
    counter++;
  }

  for(auto i: s) {
    std::cout << i << std::endl;
  }

  std::cout << "s[1] = " << s[1] << std::endl;
  s.push_back(100.);
  std::cout << "s[11] = " << s[11] << std::endl;

}
