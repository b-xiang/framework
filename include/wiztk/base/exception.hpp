/*
 * Copyright 2016 Freeman Zhang <zhanggyb@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WIZTK_BASE_EXCEPTIONS_HPP_
#define WIZTK_BASE_EXCEPTIONS_HPP_

#include <stdexcept>

namespace wiztk {
namespace base {

/**
 * @ingroup base
 * @brief The basic exception class.
 */
class Exception : public std::exception {
 public:

  explicit Exception(const std::string &what_arg)
      : msg_(what_arg) {}

  explicit Exception(const char *what_arg)
      : msg_(what_arg) {}

  const char *what() const noexcept override {
    return msg_.c_str();
  };

 private:

  std::string msg_;

};

} // namespace base
} // namespace wiztk

#endif // WIZTK_BASE_EXCEPTIONS_HPP_
