from conan import ConanFile
from conan.tools.cmake import cmake_layout


class TemplateRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("spdlog/[^1.0]")  # ty: ignore[call-non-callable]
        self.requires("gtest/[^1.0]")  # ty: ignore[call-non-callable]

    def build_requirements(self):
        pass

    def layout(self):
        cmake_layout(self)
