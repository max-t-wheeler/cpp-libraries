#define GLEW_STATIC
#include <GL/glew.h>

#include <GL/freeglut.h>

#include <GL/glut.h>
#include <GL/glext.h>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

void keyboard(unsigned char c, int x, int y) {

    if ( c == 27){
        glutLeaveMainLoop();
    }

}

void mouse(int button, int state, int x, int y){

    switch (button) {

        case GLUT_LEFT_BUTTON :

            if (state == GLUT_DOWN) {
                glutIdleFunc(NULL);
            }

            break;

        case GLUT_RIGHT_BUTTON :
            
            glutLeaveMainLoop();
            
            break;

        default : 

            break;
    
    }

}

void colorNodes(int n) {

    int mod = n%7;

    if (mod == 0) {
        glColor3f(1, 0, 0);
    }
    else if (mod == 1) {
        glColor3f(0, 1, 0);
    }
    else if (mod == 2) {
        glColor3f(0, 0, 1);
    }
    else if (mod == 3) {
        glColor3f(1, 1, 0);
    }
    else if (mod == 4) {
        glColor3f(0, 1, 1);
    }
    else if (mod == 5) {
        glColor3f(1, 0, 1);
    }
    else if (mod == 6) {
        glColor3f(1, 1, 1);
    }

}

void colorNodes(std::string col) {

    if (col == "red") {
        glColor3f(1, 0, 0);
    }
    else if (col == "green") {
        glColor3f(0, 1, 0);
    }
    else if (col == "blue") {
        glColor3f(0, 0, 1);
    }
    else if (col == "yellow") {
        glColor3f(1, 1, 0);
    }
    else if (col == "aqua") {
        glColor3f(0, 1, 1);
    }
    else if (col == "purple") {
        glColor3f(1, 0, 1);
    }
    else if (col == "white") {
        glColor3f(1, 1, 1);
    }
    else {
        glColor3f(0,0,0);
    }

}

double phi(int t, unsigned int num_nodes) {

    float p = 2*M_PI*t/num_nodes;
    
    return p;

}

double mag(arma::vec r) {

    double sum = 0;

    for (int i = 0; i < r.size(); ++i) {
        sum += pow(r(i), 2);
    }

    return sqrt(sum);

}

template <class S>
void line(S x[], S y[]) {

    glBegin(GL_LINE_STRIP);

        glVertex2f(x[0], x[1]);
        glVertex2f(y[0], y[1]);
    
    glEnd();

}

void polygon(double r[], double rad, double angle, int num_nodes) {

    for (int i = 1; i <= num_nodes; ++i) {

            glBegin(GL_LINE_STRIP);

                glVertex2f((rad*sin(phi(i, num_nodes) + angle) + r[0]), (rad*cos(phi(i, num_nodes) + angle)+ r[1]));
                glVertex2f((rad*sin(phi(i+1, num_nodes) + angle)+ r[0]), (rad*cos(phi(i+1, num_nodes)+ angle)+ r[1]));
                
            glEnd();

    }

}

template <class S>
void polygon(std::vector<S> r, double rad, double angle, int num_nodes) {

    for (int i = 1; i <= num_nodes; ++i) {

            glBegin(GL_LINE_STRIP);

                glVertex2f((rad*sin(phi(i, num_nodes) + angle) + r[0]), (rad*cos(phi(i, num_nodes) + angle)+ r[1]));
                glVertex2f((rad*sin(phi(i+1, num_nodes) + angle)+ r[0]), (rad*cos(phi(i+1, num_nodes)+ angle)+ r[1]));
                
            glEnd();

    }

}

template <class set, typename ... Types>

void poly_by_points(std::vector<set>& O, Types& ... args) {
    std::vector<set> coords[] = {(args)...};
}

void filled_polygon(double r[], double rad, int num_nodes) {

 glBegin(GL_POLYGON);

    for (int i = 1; i <= num_nodes; ++i) {

        glVertex2f(rad*sin(phi(i, num_nodes)) + r[0], rad*cos(phi(i, num_nodes))+ r[1]);

    }

  glEnd();

}

template <class S>
void filled_polygon(std::vector<S> r, double rad, double angle, int num_nodes) {

 glBegin(GL_POLYGON);

    for (int i = 1; i <= num_nodes; ++i) {
        glVertex2f(rad*sin(phi(i, num_nodes) + angle) + r[0], rad*cos(phi(i, num_nodes) + angle)+ r[1]);
    }

  glEnd();

}

void filled_polygon(arma::vec r, double rad, double angle, int num_nodes) {

 glBegin(GL_POLYGON);

    for (int i = 1; i <= num_nodes; ++i) {
        glVertex2f(rad*sin(phi(i, num_nodes) + angle) + r[0], rad*cos(phi(i, num_nodes) + angle)+ r[1]);
    }

  glEnd();

}


void poly_at_r(double r[], double dr[], double rad, int num_nodes, int number) {

    double dummy[2];

    for (int i = 1; i <= number; ++i) {

        dummy[0] = r[0]*sin(phi(i, number)) + dr[0];
        dummy[1] = r[1]*cos(phi(i, number)) + dr[1];
        
        polygon(dummy, rad, 0, num_nodes);
        //filled_polygon(dummy, rad, num_nodes);
    }

}

void skewed_star(double O[], int stems, int splits, double r_init, std::string color) {

    colorNodes(color);

    double tol = 1e-2;
    double r;


    double node[2];
    double new_node[2];

    for (int i = 0; i < stems; ++i) {

        r = r_init;
        node[0] = r*sin(phi(i, stems)) + O[0];
        node[1] = r*cos(phi(i, stems)) + O[1];
        line(O, node);

        r /= 2;

        for (int j = 0; j <= splits; ++j) {

            new_node[0] = r*sin(phi(i, stems) + (j+2)*M_PI/4) + O[0];
            new_node[1] = r*cos(phi(i, stems) + (j+2)*M_PI/4) + O[1];

            line(node, new_node);

        }

    }

}