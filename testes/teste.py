from OpenGL.GL import *
from OpenGL.GLUT import *

#Código gera um retangulo verde

def draw1():
    glClearColor(1.0, 1.0, 1.0, 1.0)
    glClear(GL_COLOR_BUFFER_BIT)
    glColor3d(0.0, 1.0, 0.0)
    glBegin(GL_POLYGON)
    glVertex2d(-0.5, -0.5)
    glVertex2d(0.5, -0.5)
    glVertex2d(0.5, 0.5)
    glVertex2d(-0.5, 0.5)
    glEnd()
    glFlush()

glutInit()
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
glutCreateWindow(b'teste')
glutInitWindowSize(500, 500)
glutDisplayFunc(draw1)
glutMainLoop()
