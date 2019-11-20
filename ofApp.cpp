#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	auto len = 150;
	auto gap = 0.05;
	vector<glm::vec3> vertices;
	for (int i = 0; i < 100; i++) {

		if (i == 0) {

			vertices.push_back(glm::vec3(-len, len, -len));
			vertices.push_back(glm::vec3(len, len, -len));
			vertices.push_back(glm::vec3(len, len, len));
			vertices.push_back(glm::vec3(-len, len, len));

			vertices.push_back(glm::vec3(-len, -len, -len));
			vertices.push_back(glm::vec3(len, -len, -len));
			vertices.push_back(glm::vec3(len, -len, len));
			vertices.push_back(glm::vec3(-len, -len, len));
		}
		else {

			vector<glm::vec3> tmp;

			tmp.push_back((vertices[1] - vertices[0]) * gap + (vertices[4] - vertices[0]) * gap * 0.5 + vertices[0]);
			tmp.push_back((vertices[2] - vertices[1]) * gap + (vertices[5] - vertices[1]) * gap * 0.5 + vertices[1]);
			tmp.push_back((vertices[3] - vertices[2]) * gap + (vertices[6] - vertices[2]) * gap * 0.5 + vertices[2]);
			tmp.push_back((vertices[0] - vertices[3]) * gap + (vertices[7] - vertices[3]) * gap * 0.5 + vertices[3]);

			tmp.push_back((vertices[5] - vertices[4]) * gap + (vertices[0] - vertices[4]) * gap * 0.5 + vertices[4]);
			tmp.push_back((vertices[6] - vertices[5]) * gap + (vertices[1] - vertices[5]) * gap * 0.5 + vertices[5]);
			tmp.push_back((vertices[7] - vertices[6]) * gap + (vertices[2] - vertices[6]) * gap * 0.5 + vertices[6]);
			tmp.push_back((vertices[4] - vertices[7]) * gap + (vertices[3] - vertices[7]) * gap * 0.5 + vertices[7]);

			for (int i = 0; i < 8; i++) {

				ofDrawLine(vertices[i], tmp[i]);
			}

			vertices = tmp;
		}

		if (i == 0 || ofGetFrameNum() % 20 == i % 20) {

			ofSetLineWidth(2);

			ofDrawLine(vertices[0], vertices[1]);
			ofDrawLine(vertices[1], vertices[2]);
			ofDrawLine(vertices[2], vertices[3]);
			ofDrawLine(vertices[3], vertices[0]);

			ofDrawLine(vertices[4], vertices[5]);
			ofDrawLine(vertices[5], vertices[6]);
			ofDrawLine(vertices[6], vertices[7]);
			ofDrawLine(vertices[7], vertices[4]);

			ofDrawLine(vertices[0], vertices[4]);
			ofDrawLine(vertices[1], vertices[5]);
			ofDrawLine(vertices[2], vertices[6]);
			ofDrawLine(vertices[3], vertices[7]);

			for (auto& vertex : vertices) {

				ofDrawSphere(vertex, ofMap(i, 0, 100, 3, 0.5));
			}

			ofSetLineWidth(1);
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}