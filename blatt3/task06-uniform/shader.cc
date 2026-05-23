#include "shader.hh"

// ------------------------------------------------------------------------
Shader::Shader(const char* vertex_filepath, const char* fragment_filepath)
  : vertex_filepath(vertex_filepath)
  , fragment_filepath(fragment_filepath) {
  load();
}

// ------------------------------------------------------------------------
void
Shader::reload() {
  glDeleteProgram(program_ID);
  load();
}

// ------------------------------------------------------------------------
void
Shader::use() {
  glUseProgram(program_ID);
}

// ************************************************************************* //
// *`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`* //
// ToDo: Add code for the shader class below.
// *`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`*`* //
// ************************************************************************* //

// ------------------------------------------------------------------------
void
Shader::load() {
  // ToDo step 1: read the source code from the given filepaths.
    std::string vertex_code;
    std::string fragment_code;
    std::ifstream v_shader_file;
    std::ifstream f_shader_file;

    v_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    f_shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        v_shader_file.open(vertex_filepath);
        f_shader_file.open(fragment_filepath);
        std::stringstream vShaderStream, fShaderStream;

        vShaderStream << v_shader_file.rdbuf();
        fShaderStream << f_shader_file.rdbuf();

        v_shader_file.close();
        f_shader_file.close();

        vertex_code = vShaderStream.str();
        fragment_code = fShaderStream.str();
    } catch (std::ifstream::failure& e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char* v_shader_code = vertex_code.c_str();
    const char* f_shader_code = fragment_code.c_str();
  // ToDo step 2: create and compile the shaders
    unsigned int vertex = 0;
    unsigned int fragment = 0;
    int success = 0;
    char info_log[512];
    vertex = glCreateShader(GL_VERTEX_SHADER);
    fragment = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(vertex, 1, &v_shader_code, NULL);
    glShaderSource(fragment, 1, &f_shader_code, NULL);

    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, info_log);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << info_log << std::endl;
    };
    glCompileShader(fragment);
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, NULL, info_log);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << info_log << std::endl;
    };

    // ToDo step 3: create and link the shader program
    this->program_ID = glCreateProgram();
    glAttachShader(this->program_ID, vertex);
    glAttachShader(this->program_ID, fragment);
    glLinkProgram(this->program_ID);
    glGetProgramiv(this->program_ID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->program_ID, 512, NULL, info_log);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << info_log << std::endl;
    }
  // ToDo step 4: clean up unnecessary stuff
    glDeleteShader(vertex);
    glDeleteShader(fragment);

  // ToDo: always check if everyting went well
  // ToDo: handle excepetions if possible
  // ToDo: print out information when failures occured

}

// ------------------------------------------------------------------------
void
Shader::setBool(const std::string& name, bool value) const {
  // ToDo: update the correct unfiform
    glUniform1i(glGetUniformLocation(program_ID, name.c_str()), (int)value);
}
// ------------------------------------------------------------------------
void
Shader::setInt(const std::string& name, int value) const {
  // ToDo: update the correct unfiform
    glUniform1i(glGetUniformLocation(program_ID, name.c_str()), value);
}
// ------------------------------------------------------------------------
void
Shader::setFloat(const std::string& name, float value) const {
  // ToDo: update the correct unfiform
    glUniform1f(glGetUniformLocation(program_ID, name.c_str()), value);
}

//bearbeitet von Mehmet Duman und Mehmet Emin Daşdan
