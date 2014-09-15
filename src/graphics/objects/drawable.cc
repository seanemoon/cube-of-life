#include "graphics/objects/drawable.h"

#include "util/math.h"

namespace chaos {

Drawable::Drawable()
  : model_{math::Matrix4f::Identity()},
    rotate_{math::Matrix4f::Identity()},
    translate_{math::Matrix4f::Identity()},
    scale_{math::Matrix4f::Identity()},
    dirty_model_{false}
{
}

void Drawable::Rotate(math::Matrix4f const &rotate)
{
  dirty_model_ = true;
  rotate_ = rotate_ * rotate;
}

void Drawable::Translate(math::Matrix4f const &translate)
{
  dirty_model_ = true;
  translate_ = translate_ * translate;
}

void Drawable::Scale(math::Matrix4f const &scale)
{
  dirty_model_ = true;
  scale_ = scale_ * scale;
}

math::Matrix4f const &Drawable::Model()
{
  if (dirty_model_) {
    model_ = translate_ * rotate_ * scale_;
    dirty_model_ = false;
  }
  return model_;
}

}  // namespace chaos
