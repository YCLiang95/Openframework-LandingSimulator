#pragma once

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "Util.h"
#include "box.h"
#include "ray.h"
#include "Octree.h"
#include "Force.h"
#include "ofxGui.h"
#include "ParticleEmitter.h"



class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void drawAxis(ofVec3f);
	void initLightingAndMaterials();
	void savePicture();
	void toggleWireframeMode();
	void togglePointsDisplay();
	void toggleSelectTerrain();
	void setCameraTarget();
	int current_camera;
	void height_detection();
	void loadVbo();

	bool mouseIntersectPlane(ofVec3f planePoint, ofVec3f planeNorm, ofVec3f &point);

	ofEasyCam cam;
	ofEasyCam cam2;
	ofEasyCam cam3;
	ofEasyCam cam4;
	vector<ofCamera*> cameras;
	ofxAssimpModelLoader mars, rocket;
	GameObject oRocket;
	ofLight light;
	//Box boundingBox;
	vector<Box> level1, level2, level3;
	Octree octree;
	ImpulseForce gravity;
	ImpulseForce rocket_up;
	ImpulseForce rocket_hor;

	ofPolyline height_line;

	ofxPanel gui;
	ofxLabel guispeed;
	ofxLabel guiheight;
	ofxLabel guispeed_warning;

	bool bAltKeyDown;
	bool bCtrlKeyDown;
	bool bWireframe;
	bool bDisplayPoints;
	bool bPointSelected;
	bool bLanded = false;

	bool bRocketLoaded;
	bool bTerrainSelected;

	ofVec3f selectedPoint;
	ofVec3f intersectPoint;

	const float selectionRange = 4.0;
	float timeLastOctree = 0;

	ParticleSystem ps;
	ParticleEmitter emitter;

	ofLight sunLight;
	ofLight spotLight;
	ofLight keyLight;

	glm::vec3 landingArea1;
	glm::vec3 landingArea2;
	glm::vec3 landingArea3;

	ofShader particle_shader;

	ofImage surface;
	ofPoint points[4];

	ofTexture texture;
	ofTexture shader;

	ofVbo vbo;
};
