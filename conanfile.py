from conan import ConanFile
from conan.tools.cmake import cmake_layout


class <PROJECT-NAME>Recipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeToolchain", "CMakeDeps"

    def requirements(self):
        self.requires("")  # ty: ignore[call-non-callable]

    def build_requirements(self):
        pass

    def layout(self):
        cmake_layout(self)
