/*
 * Copyright 2017 - 2018 The WizTK Authors.
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

#ifndef WIZTK_MATRIX_PRIVATE_HPP
#define WIZTK_MATRIX_PRIVATE_HPP

#include "wiztk/graphics/matrix.hpp"

#include "SkMatrix.h"

namespace wiztk {
namespace graphics {

struct Matrix::Private {

  static const Private &Get(const Matrix &matrix) {
    return *matrix.p_;
  }

  Private() = default;

  Private(const Private &orig) = default;

  ~Private() = default;

  SkMatrix sk_matrix;

};

} // namespace graphics
} // namespace wiztk

#endif //WIZTK_MATRIX_PRIVATE_HPP
