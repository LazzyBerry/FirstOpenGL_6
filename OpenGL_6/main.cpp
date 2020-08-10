#include <gl/glut.h>

//各種パラメータ
//光源設定(環境、拡散、鏡面のみ）
GLfloat lightAmb[] = { 0.f,0.f,0.f,1.f };
GLfloat lightDiff[] = { 1.f,1.f,1.f,1.f };
GLfloat lightSpec[] = { 1.f,1.f,1.f,1.f };
GLfloat lightPos[] = { 1.f,1.f,1.f,0.f };//	平行光源

//材質を金に設定
GLfloat gold_amb[] = { 0.24725f,0.1995f,0.0745f,1.f };
GLfloat gold_diff[] = { 0.75164f,0.60648f,0.22648f,1.f };
GLfloat gold_spe[] = { 0.628281f,0.555802f,0.366065f,1.f };
const GLfloat gold_shin = 51.2f;

//頂点データ（8頂点,xyz3要素)
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

//立方体の描画
void drawCube()
{
	//top
	glNormal3f(0, 1, 0);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[0]);//頂点v0
	glVertex3fv(vertexes[3]);//頂点v3
	glVertex3fv(vertexes[7]);//頂点v7
	glVertex3fv(vertexes[4]);//頂点v4
	glEnd();

	//Buttom
	glNormal3f(0, -1, 0);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[5]);//頂点v5
	glVertex3fv(vertexes[6]);//頂点v6
	glVertex3fv(vertexes[2]);//頂点v2
	glVertex3fv(vertexes[1]);//頂点v1
	glEnd();

	//front
	glNormal3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[0]);//頂点v0
	glVertex3fv(vertexes[1]);//頂点v1
	glVertex3fv(vertexes[2]);//頂点v2
	glVertex3fv(vertexes[3]);//頂点v3
	glEnd();

	//back
	glNormal3f(0, 0, -1);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[4]);//頂点v4
	glVertex3fv(vertexes[7]);//頂点v7
	glVertex3fv(vertexes[6]);//頂点v6
	glVertex3fv(vertexes[5]);//頂点v5
	glEnd();

	//left
	glNormal3f(-1, 0, 0);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[0]);//頂点v0
	glVertex3fv(vertexes[4]);//頂点v4
	glVertex3fv(vertexes[5]);//頂点v5
	glVertex3fv(vertexes[1]);//頂点v1
	glEnd();

	//right
	glNormal3f(1, 0, 0);
	glBegin(GL_QUADS);
	glVertex3fv(vertexes[3]);//頂点v3
	glVertex3fv(vertexes[2]);//頂点v2
	glVertex3fv(vertexes[6]);//頂点v6
	glVertex3fv(vertexes[7]);//頂点v7
	glEnd();
}


//各種コールバック関数

//ディスプレイ
void display()
{
	static int angle = 0;

	//バッファの初期化
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(0.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	//光源の位置設定
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//材質設定と描画
	glEnable(GL_COLOR_MATERIAL);
	glPushMatrix();
	glRotated(float(angle), 0.f, 1.f, 0.f);

	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT);//環境光
	glColor4fv(gold_amb);

	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);//拡散光
	glColor4fv(gold_diff);

	glColorMaterial(GL_FRONT_AND_BACK, GL_SPECULAR);//鏡面光
	glColor4fv(gold_spe);

	glutSolidSphere(1, 60, 60);//描画

	glDisable(GL_COLOR_MATERIAL);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, gold_amb);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, gold_diff);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, gold_spe);
	//glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, gold_shin);
	//drawCube(); //立方体の描画
	//glutSolidTeapot(1.0);//描画
	glPopMatrix();

	glutSwapBuffers();

	if (++angle >= 360) {
		angle = 0; //回転角度のリセット
	}
	
	//球の描画
	//GLUquadricObj* sphere; //変数宣言
	//sphere = gluNewQuadric(); //オブジェクト生成
	//gluQuadricDrawStyle(sphere, GLU_FILL); // 描画スタイルの設定
	//gluSphere(sphere, 1.0, 30.0, 30.0); //球の描画
	//gluDeleteQuadric(sphere);//メモリ解放
}

//ウィンドウサイズを変更した際
void reshape(int w, int h)
{
	glViewport(0, 0, w, h);//ビューポートの設定

	glMatrixMode(GL_PROJECTION);//射影行列の設定
	glLoadIdentity();
	gluPerspective(30, (double)w / h, 1.0, 100.0);

	glMatrixMode(GL_MODELVIEW); //モデルビュー行列の設定
}

//再描画命令
void idle()
{
	glutPostRedisplay();
}

//その他各種設定
void otherInit()
{
	//カラーバッファの初期化
	glClearColor(1.f, 1.f, 1.f, 1.f);
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);

	//光源設定(環境、拡散、鏡面のみ）
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);

	//光源とライティングの有効化
	glEnable(GL_LIGHTING);//光源の設定を有効化
	glEnable(GL_LIGHT0);//0番目の光源を有効化
	glEnable(GL_NORMALIZE);//法線ベクトルの正規化

	//シェーディングモデルの設定
	glShadeModel(GL_SMOOTH);
}

//メイン関数
int main(int argc, char* argv[])
{
	glutInit(&argc, argv); //GLUTの初期化

	//Windowの作成
	glutInitWindowSize(640, 480);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE); //ディスプレイモード
	glutCreateWindow("Light	Material Vertex");


	//コールバック関数登録
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);
	
	otherInit();

	glutMainLoop(); //メインループへ

	return 0;
}