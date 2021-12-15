#include <include/glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main(){
    //init glfw
    glfwInit();

    //Set OpenGL 3.3 Core, Forward compatible
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    

    //Create Window named test with a size of 800x600
    GLFWwindow* window = glfwCreateWindow(800,600, "Simple Window", NULL, NULL);

    // Set context to window
    glfwMakeContextCurrent(window);

    //init glad
    gladLoadGL();

    // Print openGL version
    std::cout << "OPENGL ver: " << glGetString(GL_VERSION) << std::endl;

    // Frame Buffer size call back
    glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    });

    // render loop
    while(!glfwWindowShouldClose(window)){
        //clear color buffer
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        //swap buffers
        glfwSwapBuffers(window);
        //poll events
        glfwPollEvents();
    }
    //clean up :)
    glfwTerminate();
    return 0;
}
