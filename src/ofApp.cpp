#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);

	// Enable or disable audio for video sources globally
	// Set this to false to save resources on the Raspberry Pi
	ofx::piMapper::VideoSource::enableAudio = true;
	ofx::piMapper::VideoSource::useHDMIForAudio = false;

	// Add our CustomSource to list of fbo sources of the piMapper
	// FBO sources should be added before piMapper.setup() so the
	// piMapper is able to load the source if it is assigned to
	// a surface in XML settings.
    
	//crossSource = new CrossSource();
	//piMapper.registerFboSource(crossSource);
    
    // specify 12 colors
    vector<ofColor> colors = {
        ofColor(0, 255, 0, 255),
        ofColor(0, 225, 166, 255),
        ofColor(0, 186, 250, 255),
        ofColor(0, 139, 255, 255),
        ofColor(0, 78, 204, 255),
        ofColor(119, 69, 202, 255),
        ofColor(176, 53, 192, 255),
        ofColor(220, 30, 174, 255),
        ofColor(255, 0, 151, 255),
        ofColor(255, 46, 113, 255),
        ofColor(255, 91, 77, 255),
        ofColor(255, 132, 43, 255),
        ofColor(255, 169, 0, 255)
    };
    
    // create 12 custom sources and register them
    for (int i=0; i<NUM_SOURCES; i++) {
        customSource[i].setName("Custom"+ofToString(i+1));
        customSource[i].colour = colors[i];
        
        piMapper.registerFboSource(&customSource[i]);
    }
	piMapper.setup();

	// The info layer is hidden by default, press <i> to toggle
	// piMapper.showInfo();
}

void ofApp::update(){
	piMapper.update();
    
    int numFrames = 30;
    int numVisible = (NUM_SOURCES/2 + 3);
    if (ofGetFrameNum() % numFrames == 0) {
        customSource[currentSource].alpha = customSource[currentSource].step * numFrames * numVisible;
        currentSource++;
        if (currentSource == NUM_SOURCES) {
            currentSource = 0;
        }
    }
}

void ofApp::draw(){
	piMapper.draw();
}

void ofApp::keyPressed(int key){
	piMapper.keyPressed(key);
}

void ofApp::keyReleased(int key){
	piMapper.keyReleased(key);
}

void ofApp::mousePressed(int x, int y, int button){
	piMapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
	piMapper.mouseReleased(x, y, button);
}

void ofApp::mouseDragged(int x, int y, int button){
	piMapper.mouseDragged(x, y, button);
}
