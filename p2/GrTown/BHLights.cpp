#include "BHLights.h"

#include "SurfaceOfRevolution.h"
BHLights::BHLights()
{
}

BHLights::BHLights(GrObjectVBO* _BH, GrObjectVBO* _track){
  BH = _BH;
  track = track;
}


BHLights::~BHLights()
{
}

void BHLights::initializeAfter(){

  std::vector<glm::vec3> vertexList;
  //add the points;
  vertexList.push_back(glm::vec3(0, 0, 0));
  vertexList.push_back(glm::vec3(100, -1000, 0));
  std::vector<glm::vec3> normalList;
  std::vector<glm::vec2> uvList;

  surfaceOfRevolution(glm::vec3(0, 1, 0), rotation, vertexList, normalList, uvList);
  //drawCube(vertexList, normalList, uvList);
  

  bindToArrayBuffer(vertexBufferAfter, vertexList);
  bindToArrayBuffer(normalBufferAfter, normalList);
  bindToArrayBuffer(textureBufferAfter, uvList);
  vertexNumAfter = vertexList.size();
  onlyBack = true;
  shaderIDAfter = loadShader("BHLightVertex.glsl", "BHLightFragment.glsl");
}

void BHLights::draw(DrawingState*, glm::mat4 proj, glm::mat4 view, glm::mat4 model){

}


void BHLights::redoSOR(){
	std::vector<glm::vec3> vertexList;
	//add the points;
	vertexList.push_back(glm::vec3(0, 0, 0));
	vertexList.push_back(glm::vec3(100, -1000, 0));
	std::vector<glm::vec3> normalList;
	std::vector<glm::vec2> uvList;

	surfaceOfRevolution(glm::vec3(0, 1, 0), rotation, vertexList, normalList, uvList);

	rebindToArrayBuffer(vertexBufferAfter, vertexList);
	rebindToArrayBuffer(normalBufferAfter,normalList);
	rebindToArrayBuffer(textureBufferAfter, uvList);

	vertexNumAfter = vertexList.size();
}

#include "DrawingState.H"
void BHLights::preDraw(DrawingState* drst){
  transform = transform;

  //check whether setting changed
  static float lastRotation = 10;
  if ( lastRotation != drst->soRRotation){
	  rotation = drst->soRRotation;
	  lastRotation = drst->soRRotation;
	  redoSOR();
  }
}