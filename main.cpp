#include <iostream>
#include </home/dave/CLionProjects/untitled/glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

}

int main(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //MacOS compatibility

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    //initialize glad handler for glfw
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, 800, 600);

    // Start buffering a triangle
    float vertices[] = {
             0.0f, 0.5f, 0.0f,
            -0.5f, 0.0f, 0.0f,
             0.5f, 0.0f, 0.0f
    };

    // VBO generation
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // pag 31

    while(!glfwWindowShouldClose(window)){
        // Events
        processInput(window);

        // Rendering goes here
        glClearColor(0.3f, 0.0f, 0.0f, 1.0f); // RGBA?
        glClear(GL_COLOR_BUFFER_BIT);

        // Buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();

        return 0;
    }
