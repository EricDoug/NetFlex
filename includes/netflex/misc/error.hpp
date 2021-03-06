// The MIT License (MIT)
//
// Copyright (c) 2015-2017 Simon Ninon <simon.ninon@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include <stdexcept>
#include <string>

#include <netflex/misc/logger.hpp>

namespace netflex {

//!
//! specialized runtime_error used for netflex error
//!
class netflex_error : public std::runtime_error {
public:
  using std::runtime_error::runtime_error;
  using std::runtime_error::what;

  //! ctor (string)
  explicit netflex_error(const std::string& msg)
  : std::runtime_error(msg.c_str()) {
  }

  //! ctor(char*)
  explicit netflex_error(const char* msg)
  : std::runtime_error(msg) {
  }
};

//!
//! macro for convenience
//!
#define __NETFLEX_THROW(level, what)      \
  {                                       \
    __NETFLEX_LOG(level, (what));         \
    throw netflex::netflex_error((what)); \
  }

} // namespace netflex
