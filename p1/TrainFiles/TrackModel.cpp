#include "TrackModel.h"


TrackModel::TrackModel()
{
}


TrackModel::~TrackModel()
{
}

void drawSimpleTrack(Pnt3f p1, Pnt3f p2, bool shadow){
	//get difference between p2 and p1;
	Pnt3f diff = p2 - p1;
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	drawVertex(diff);
	glEnd();
}

void TrackModel::drawDual(Pnt3f p1, Pnt3f p2, Pnt3f orPt, bool shadow){

	//set thickness
	glLineWidth(2);

	if (!shadow){
		glColor3ub(142, 142, 142);
	}

	//get a directional vector
	Pnt3f dirPt = p2 - p1;
	dirPt.normalize();

	glPushMatrix();

	//get a perpendicular vector
	Pnt3f pVec = dirPt * orPt;

	pVec = pVec * 2;

	glTranslatef(pVec.x, pVec.y, pVec.z);
	draw(p1, p2, shadow);
	glPopMatrix();

	glPushMatrix();
	//reset the perpendicular vector
	pVec.normalize();
	pVec = pVec * -2;
	glTranslatef(pVec.x, pVec.y, pVec.z);
	draw(p1, p2, shadow);
	glPopMatrix();
}

void TrackModel::draw(Pnt3f p1, Pnt3f p2, bool shadow){

	//get difference between p2 and p1;
	Pnt3f diff = p2 - p1;
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	drawVertex(diff);
	glEnd();

	/*

	if (!shadow){
		glColor3b(0, 0, 0);
	}
	//drawCube(3, 0, 0, 1);

	if (!shadow){
		glColor3ub(0, 225, 225);
	}
	drawCube(15, 0, 0, 0.5);
	*/
}