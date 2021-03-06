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

#include "output/private.hpp"
#include "display/private.hpp"

#include "wiztk/gui/display.hpp"
#include "wiztk/gui/application.hpp"

namespace wiztk {
namespace gui {

Output::Output(uint32_t id, uint32_t version) {
  p_ = std::make_unique<Private>(this);
  p_->id = id;
  p_->version = version;

  Display *display = Application::GetInstance()->GetDisplay();
  p_->wl_output =
      static_cast<struct wl_output *>(wl_registry_bind(Display::Private::Get(*display).wl_registry,
                                                       id,
                                                       &wl_output_interface,
                                                       version));
  wl_output_add_listener(p_->wl_output, &Private::kListener, this);
}

Output::~Output() {
  destroyed_.Emit(this);
}

int Output::GetSubPixel() const {
  return p_->subpixel;
}

int Output::GetTransform() const {
  return p_->transform;
}

int Output::GetScale() const {
  return p_->scale;
}

const std::string &Output::GetMake() const {
  return p_->make;
}

const std::string &Output::GetModel() const {
  return p_->model;
}

uint32_t Output::GetID() const {
  return p_->id;
}

uint32_t Output::GetVersion() const {
  return p_->version;
}

} // namespace gui
} // namespace wiztk
