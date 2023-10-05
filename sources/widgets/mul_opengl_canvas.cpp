#include "widgets/mul_opengl_canvas.h"
#include "mul_opengl.h"
/*
static void DrawCallback(const ImDrawList* parent_list, const ImDrawCmd* cmd) {
    //glBindFramebuffer(GL_FRAMEBUFFER, *static_cast<GLuint*>(cmd->UserCallbackData));
    //glViewport(0,0,1024,768);
}
*/
void MulOpenglCanvas::onDraw() {
    glBindFramebuffer(GL_FRAMEBUFFER, frameBufferId);
    glDraw();
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    //ImGui::Image(reinterpret_cast<void*>(renderedTexture), {300.0f, 300.0f});
    //ImGui::GetWindowDrawList()->AddCallback(&DrawCallback, &frameBufferId);
}

void MulOpenglCanvas::onInit() {

        // The texture we're going to render to
    glGenTextures(1, &renderedTexture);

    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, renderedTexture);

    // Give an empty image to OpenGL ( the last "0" )
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGBA, 1024, 768, 0,GL_RGBA, GL_UNSIGNED_BYTE, 0);

    // Poor filtering. Needed !
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

    glBindTexture(GL_TEXTURE_2D, 0);

    GLuint depthTexture;
    glGenTextures(1, &depthTexture);
    glBindTexture(GL_TEXTURE_2D, depthTexture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, 1024, 768, 0, GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glGenFramebuffers(1, &frameBufferId);
    glBindFramebuffer(GL_FRAMEBUFFER, frameBufferId);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthTexture, 0);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, renderedTexture, 0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void MulOpenglCanvas::glDraw() {
    if(drawFunction) {
        drawFunction();
    }
}

void MulOpenglCanvas::setDrawFunction(const std::function<void()>& value) {
    drawFunction = value;
}