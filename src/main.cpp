#include "ofMain.h"
#include "ofApp.h"

int main(int argc, char * argv[]){
    bool fullscreen = false;
    ofSetupOpenGL(800, 450, fullscreen ? OF_FULLSCREEN : OF_WINDOW);
	ofRunApp(new ofApp());
}
