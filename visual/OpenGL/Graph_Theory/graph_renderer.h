#include "../../../graph_theory.h"
#include "../OpenGL_Utils.h"

void render_graph(graph G, std::string animation_type, std::string vertex_type, float &dphi) {

    if (animation_type != "static" && animation_type != "dynamic") {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1, 0, 0);

        glutSwapBuffers();

    }

    if (animation_type == "static") {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1, 0, 0);

        if (G.size() > 0) {

            glBegin(GL_LINES);

                for (int i = 0; i < G.order()-1; ++i) {
                    for(int j = i+1; j < G.order(); ++j) {
                        
                        if(G.adjacency_tensor(i, j, 0) == 1) {
                            //colorNodes("white");
                            colorNodes(G.v[i]->sid+1);
                            glVertex2f(G.v[i]->x(0), G.v[i]->x(1));
                            glVertex2f(G.v[j]->x(0), G.v[j]->x(1));
                        }

                    }
                }

            glEnd();

        }

        if (G.order() > 0) {

            glBegin(GL_POINTS);

                for (int i = 0; i < G.order(); ++i) {
                    colorNodes(G.v[i]->sid+1);
                    if (vertex_type == "dot") {
                        glVertex2f(G.v[i]->x(0), G.v[i]->x(1));
                    }
                    else if (vertex_type == "ball") {
                        filled_polygon(G.v[i]->x, G.v[i]->r, 0, 100);
                    }
                }

            glEnd();

        }

        glutSwapBuffers();
        
    }

    if (animation_type == "dynamic") {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1, 0, 0);

        if (G.size() > 0) {

            glBegin(GL_LINES);

                for (int i = 0; i < G.order()-1; ++i) {
                    for(int j = i+1; j < G.order(); ++j) {
                        
                        if(G.adjacency_tensor(i, j, 0) == 1) {
                            //colorNodes("white");
                            colorNodes(G.v[i]->sid+1);
                            glVertex2f(G.v[i]->x(0), G.v[i]->x(1));
                            glVertex2f(G.v[j]->x(0), G.v[j]->x(1));
                        }

                    }
                }

            glEnd();

        }

        if (G.order() > 0) {

            glBegin(GL_POINTS);

                for (int i = 0; i < G.order(); ++i) {

                    colorNodes(G.v[i]->sid+1);
                    
                    if (vertex_type == "dot") {
                        glVertex2f(G.v[i]->x(0), G.v[i]->x(1));
                    }
                    else if (vertex_type == "ball") {
                        filled_polygon(G.v[i]->x, G.v[i]->r, 0, 100);
                    }

                }

            glEnd();

        }

        glFlush();

        if (dphi >= 0 ){
            dphi += sin(0.1/100)*0.1;
        }
        else {
            dphi -= 0.1/100;
        }


        glutPostRedisplay();

    }

}

void render_graphs(std::vector<graph*> G_vec, std::string animation_type, std::string vertex_type, float &dphi) {

    if (animation_type != "static" && animation_type != "dynamic") {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1, 0, 0);

        glutSwapBuffers();

    }

    if (animation_type == "static") {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1, 0, 0);

        for (int k = 0; k < G_vec.size(); ++k) {

            if (G_vec[k]->size() > 0) {

                glBegin(GL_LINES);

                    for (int i = 0; i < G_vec[k]->order()-1; ++i) {

                        for(int j = i+1; j < G_vec[k]->order(); ++j) {
                            
                            if(G_vec[k]->adjacency_tensor(i, j, 0) == 1) {
                                //colorNodes("white");
                                colorNodes(G_vec[k]->v[i]->sid+1);
                                glVertex2f(G_vec[k]->v[i]->x(0), G_vec[k]->v[i]->x(1));
                                glVertex2f(G_vec[k]->v[j]->x(0), G_vec[k]->v[j]->x(1));
                            }

                        }

                    }

                glEnd();

            }

        }

        for (int k = 0; k < G_vec.size(); ++k) {

            if (G_vec[k]->order() > 0) {

                glBegin(GL_POINTS);

                    for (int i = 0; i < G_vec[k]->order(); ++i) {

                        colorNodes(G_vec[k]->v[i]->sid+1);

                        if (vertex_type == "dot") {
                            glVertex2f(G_vec[k]->v[i]->x(0), G_vec[k]->v[i]->x(1));
                        }
                        else if (vertex_type == "ball") {
                            filled_polygon(G_vec[k]->v[i]->x, G_vec[k]->v[i]->r, 0, 100);
                        }

                    }

                glEnd();

            }

        }

        glutSwapBuffers();

    }

    if (animation_type == "dynamic") {
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glColor3f(1, 0, 0);

        for (int k = 0; k < G_vec.size(); ++k) {

            if (G_vec[k]->size() > 0) {

                glBegin(GL_LINES);

                    for (int i = 0; i < G_vec[k]->order()-1; ++i) {

                        for(int j = i+1; j < G_vec[k]->order(); ++j) {
                            
                            if(G_vec[k]->adjacency_tensor(i, j, 0) == 1) {
                                //colorNodes("white");
                                colorNodes(G_vec[k]->v[i]->sid+1);
                                glVertex2f(G_vec[k]->v[i]->x(0), G_vec[k]->v[i]->x(1));
                                glVertex2f(G_vec[k]->v[j]->x(0), G_vec[k]->v[j]->x(1));
                            }

                        }

                    }

                glEnd();

            }

        }

        for (int k = 0; k < G_vec.size(); ++k) {

            if (G_vec[k]->order() > 0) {

                glBegin(GL_POINTS);

                    for (int i = 0; i < G_vec[k]->order(); ++i) {

                        colorNodes(G_vec[k]->v[i]->sid+1);

                        if (vertex_type == "dot") {
                            glVertex2f(G_vec[k]->v[i]->x(0), G_vec[k]->v[i]->x(1));
                        }
                        else if (vertex_type == "ball") {
                            filled_polygon(G_vec[k]->v[i]->x, G_vec[k]->v[i]->r, 0, 100);
                        }

                    }

                glEnd();

            }

        }

        glFlush();

        if (dphi >= 0 ){
            dphi += sin(0.1/100)*0.1;
        }
        else {
            dphi -= 0.1/100;
        }


        glutPostRedisplay();

    }
}