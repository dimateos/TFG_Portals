#include "Material.h"
#include <glad\glad.h>

Material::Material(Shader* shader) : shader_(shader) {}
Material::~Material() {}

Shader SolidMaterial::SOLID_MAT_SHADER = Shader();
unsigned int SolidMaterial::UNIFORM_COLOR = 0;
unsigned int SolidMaterial::UNIFORM_OPTION = 0;
unsigned int SolidMaterial::UNIFORM_CLIP_PLANE = 0;

SolidMaterial::SolidMaterial(glm::vec3 const & color, Texture* tex)
	: Material(&SOLID_MAT_SHADER), color_(color), tex_(tex) {
}
SolidMaterial::~SolidMaterial() {
}

void SolidMaterial::bind() {
	glUniform3f(UNIFORM_COLOR, color_.x, color_.y, color_.z);
	glUniform1i(UNIFORM_OPTION, option_);
	tex_->bind();

	if (option_ == 2) {
		glEnable(GL_CLIP_DISTANCE0);
		glUniform4f(UNIFORM_CLIP_PLANE, clipPlane_.x, clipPlane_.y, clipPlane_.z, clipPlane_.w);
	}
}

void SolidMaterial::unbind() {
	if (option_ == 2) glDisable(GL_CLIP_DISTANCE0);
}
