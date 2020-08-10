#include <gl/glut.h>

//�e��p�����[�^
//�����ݒ�(���A�g�U�A���ʂ̂݁j
GLfloat lightAmb[] = { 0.f,0.f,0.f,1.f };
GLfloat lightDiff[] = { 1.f,1.f,1.f,1.f };
GLfloat lightSpec[] = { 1.f,1.f,1.f,1.f };
GLfloat lightPos[] = { 1.f,1.f,1.f,0.f };//	���s����

//�ގ������ɐݒ�
GLfloat gold_amb[] = { 0.24725f,0.1995f,0.0745f,1.f };
GLfloat gold_diff[] = { 0.75164f,0.60648f,0.22648f,1.f };
GLfloat gold_spe[] = { 0.628281f,0.555802f,0.366065f,1.f };
const GLfloat gold_shin = 51.2f;

//���_�f�[�^�i8���_,xyz3�v�f)
GLfloat vertexes[8][3] =
{
	{-0.5f,0.5f,0.5f},//v0
	{-0.5f,-0.5f,0.5f},//v1
	{0.5f,-0.5f,0.5f},//v2
	{0.5f,0.5f,0.5f},//v3

	{-0.5f,0.5f,-0.5f},//v4
	{-0.5f,-0.5f,-0.5f},//v5
	{0.5f,-0.5f,-0.5f},//v6
	{0.5f,0.5f,-0.5f},//v7
};

//�����̂̕`��
void drawCube()
{
	//top
	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[0]);//���_v0
	glVertex3fv(vertexes[3]);//���_v3
	glVertex3fv(vertexes[7]);//���_v7
	glVertex3fv(vertexes[4]);//���_v4
	glEnd();

	//Buttom
	glNormal3f(0, -1, 0);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[5]);//���_v5
	glVertex3fv(vertexes[6]);//���_v6
	glVertex3fv(vertexes[2]);//���_v2
	glVertex3fv(vertexes[1]);//���_v1
	glEnd();

	//front
	glNormal3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[0]);//���_v0
	glVertex3fv(vertexes[1]);//���_v1
	glVertex3fv(vertexes[2]);//���_v2
	glVertex3fv(vertexes[3]);//���_v3
	glEnd();

	//back
	glNormal3f(0, 0, -1);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[4]);//���_v4
	glVertex3fv(vertexes[7]);//���_v7
	glVertex3fv(vertexes[6]);//���_v6
	glVertex3fv(vertexes[5]);//���_v5
	glEnd();

	//left
	glNormal3f(-1, 0, 0);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[0]);//���_v0
	glVertex3fv(vertexes[4]);//���_v4
	glVertex3fv(vertexes[5]);//���_v5
	glVertex3fv(vertexes[1]);//���_v1
	glEnd();

	//right
	glNormal3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[3]);//���_v3
	glVertex3fv(vertexes[2]);//���_v2
	glVertex3fv(vertexes[6]);//���_v6
	glVertex3fv(vertexes[7]);//���_v7
	glEnd();
}


//�e��R�[���o�b�N�֐�

//�f�B�X�v���C
void display()
{
	static int angle = 0;

	//�o�b�t�@�̏�����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//�����̈ʒu�ݒ�
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//�ގ��ݒ�ƕ`��
	glEnable(GL_COLOR_MATERIAL);
	glPushMatrix();
	glRotated(float(angle), 0.f, 1.f, 0.f);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);//����
	glColor4fv(gold_amb);

	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);//�g�U��
	glColor4fv(gold_diff);

	glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);//���ʌ�
	glColor4fv(gold_spe);

	glutSolidSphere(1, 60, 60);//�`��

	glDisable(GL_COLOR_MATERIAL);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, gold_amb);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gold_diff);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, gold_spe);
	//glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, gold_shin);
	//drawCube(); //�����̂̕`��
	//glutSolidTeapot(1.0);//�`��
	glPopMatrix();

	glutSwapBuffers();

	if (++angle >= 360) {
		angle = 0; //��]�p�x�̃��Z�b�g
	}
	
	//���̕`��
	//GLUquadricObj* sphere; //�ϐ��錾
	//sphere = gluNewQuadric(); //�I�u�W�F�N�g����
	//gluQuadricDrawStyle(sphere, GLU_FILL); // �`��X�^�C���̐ݒ�
	//gluSphere(sphere, 1.0, 30.0, 30.0); //���̕`��
	//gluDeleteQuadric(sphere);//���������
}

//�E�B���h�E�T�C�Y��ύX������
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);//�r���[�|�[�g�̐ݒ�

	glMatrixMode(GL_PROJECTION);//�ˉe�s��̐ݒ�
	glLoadIdentity();
	gluPerspective(30, (double)w / h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW); //���f���r���[�s��̐ݒ�
}

//�ĕ`�施��
void idle()
{
	glutPostRedisplay();
}

//���̑��e��ݒ�
void otherInit()
{
	//�J���[�o�b�t�@�̏�����
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);

	//�����ݒ�(���A�g�U�A���ʂ̂݁j
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);

	//�����ƃ��C�e�B���O�̗L����
	glEnable(GL_LIGHTING);//�����̐ݒ��L����
	glEnable(GL_LIGHT0);//0�Ԗڂ̌�����L����
	glEnable(GL_NORMALIZE);//�@���x�N�g���̐��K��

	//�V�F�[�f�B���O���f���̐ݒ�
	glShadeModel(GL_SMOOTH);
}

//���C���֐�
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUT�̏�����

	//Window�̍쐬
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //�f�B�X�v���C���[�h
	glutCreateWindow("Light	Material Vertex");


	//�R�[���o�b�N�֐��o�^
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	
	otherInit();

	glutMainLoop(); //���C�����[�v��

	return 0;
}