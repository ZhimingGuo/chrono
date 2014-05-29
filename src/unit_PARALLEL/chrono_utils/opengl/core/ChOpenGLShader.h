#ifndef CHOPENGLSHADER_H
#define CHOPENGLSHADER_H

#include "chrono_utils/opengl/core/ChOpenGLBase.h"
    
    namespace chrono {
        namespace utils{

            class CH_UTILS_OPENGL_API ChOpenGLShader : public ChOpenGLBase
            {
            public:
                ChOpenGLShader();
                void TakeDown();
                void Use();
                virtual bool Initialize(std::string vertex_shader_file, std::string fragment_shader_file);
                virtual void CustomSetup();
                void CommonSetup(const GLfloat * projection, const GLfloat * modelview, const GLfloat * mvp, const GLfloat * nm);
                void SetTime(float _time);
                void SetCamera(glm::vec3 campos);
                GLuint GetUniformLocation(std::string name);
                GLuint modelview_matrix_handle;
                GLuint projection_matrix_handle;
                GLuint normal_matrix_handle;
                GLuint mvp_handle;
                GLuint time_handle,camera_handle;
                GLuint vertex_shader_id;
                GLuint fragment_shader_id;
                GLuint program_id;
                bool LoadShader(const std::string file_name, GLuint shader_id);
                std::string GetShaderLog(GLuint shader_id);
                void CheckGlProgram(GLuint prog);
                float time;
                glm::vec3 camera_pos;
            };

        }
    }
#endif  // END of CHOPENGLSHADER_H
