from OpenGL.GLUT import *
from OpenGL.GLU import *
from OpenGL.GL import *
import sys
import numpy

name = 'SnowMan'

def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
    glutInitWindowSize(800, 800)
    glutInitWindowPosition(350, 200)
    glutCreateWindow(name)
    glClearColor(0., 0., 0., 1.)
    glShadeModel(GL_SMOOTH)
    glEnable(GL_CULL_FACE)
    glEnable(GL_DEPTH_TEST)
    
    glutDisplayFunc(display_scene)
    glMatrixMode(GL_PROJECTION)
    gluPerspective(40., 1., 1., 40.)
    glMatrixMode(GL_MODELVIEW)
    gluLookAt(0, 0, 10,
              0, 0, 0,
              0, 1, 0)
    glPushMatrix()
    glutMainLoop()
    return

def display_scene():
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glPushMatrix()
    # Textured thing 
    
    qobj = gluNewQuadric()

   
    # Left sphere
    color = [1.5, 1.5, 1.5, 1.5]
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color)
    glTranslatef(0, -2, 0)
    glutSolidSphere(1, 100, 20)
    # Right sphere
    color = [1.0, 1.0, 1.0, 1.0]
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color)
    glTranslatef(0, 2, 0)
    glutSolidSphere(1, 100, 20)

    color = [1.0, 1.0, 1.0, 1.0]
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color)
    glTranslatef(0, 6, 0)
    glutSolidSphere(1, 100, 20)

    glPopMatrix()
    glutSwapBuffers()
    return


if __name__ == '__main__':
    main()