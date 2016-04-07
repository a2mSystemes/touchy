#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofHideCursor();
	ofSetFrameRate(25);
	mouseRes = 16383;
	slideWidth = ofGetWidth();
	slideHeight = ofGetHeight();
	ofDirectory dir;
	dir.listDir("");
	dir.sort();
	for (std::size_t i = 0; i < dir.size(); i++) {
		ofLogNotice(dir.getPath((int) i));
		ofImage* img = new ofImage(dir.getPath((int) i));
		img->resize(slideWidth, slideHeight);
		images.push_back(img);
	}
//	ofDirectory dir2;
//	dir2.listDir("/media/usb0/");
//	for(int i = 0; i < dir2.size(); i++){
//	    ofLogNotice(dir2.getPath(i));
//	}

	/*images.push_back(new ofImage("flower1.jpg"));
	 images.push_back(new ofImage("flower2.jpg"));
	 images.push_back(new ofImage("flower3.jpg"));
	 images.push_back(new ofImage("flower4.jpg"));
	 images.push_back(new ofImage("flower5.jpg"));
	 images.push_back(new ofImage("flower6.jpg"));
	 images.push_back(new ofImage("flower7.jpg"));*/

	carousel.length = ofGetWidth() * images.size();
	carousel.pagingSize = carousel.length / images.size();
	carousel.velocity = 0;
	//current = images.front();
	position = 0;
	first = true;
}

//--------------------------------------------------------------
void ofApp::update() {
	carousel.update();
}

//--------------------------------------------------------------
void ofApp::draw() {

	for (std::size_t i = 0; i < images.size(); i++) {
		float x = 0;
		if (images.size() > 0) {
			x = carousel.positionForTile((int) i, images.size(), slideWidth);
			//ofLogNotice("ofApp::draw()") << "Tile n°" << i <<" position" << x;
			if (x >= -slideWidth && x < slideWidth) {
				//ofLogNotice("ofApp::draw()") << "drawing Tile n°" << i <<" position" << x << " - slideWidth : " << slideWidth;
				images[i]->draw(x, 0, slideWidth, slideHeight);
			}
		}
//    	else{
//
//            float x = carousel.positionForTile(i, 0 , slideWidth);
//            ofLogNotice("ofApp::draw()") << "Tile n°" << i <<" position" << x;
//    	}

//        ofImage image = *images[i];
//    	//ofLogNotice("ofApp::draw()") << "Tile n°" << i <<" position" << x;
//
//        image.draw(x, 0, slideWidth, slideHeight);

	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_LEFT) {
		carousel.drop(1);
	} else if (key == OF_KEY_RIGHT) {
		carousel.drop(-1);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	carousel.drag(-x);
	ofLogNotice("ofApp::mouseMoved") << " x:" << x << " y:" << y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

//	if (x == 1920 || y == 1080)
//		return;
	ofLogNotice("ofApp::mouseDragged") << " x:" << x << " y:" << y;
	//float xAxis = x / mouseRes;

//	float yAxis = y / mouseRes;
	if (first == false) {
		carousel.drag(-x);
		//first = false;
	} else {
		carousel.grab(-x);
		first = false;
	}
//	//ofLogNotice("ofApp::mouseDragged") << "ref : " << ref << " x:" << x << " y:" << y;

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	position = x;
	//ofLogNotice("ofApp::mousePressed") << "x : " << x <<" y : " << y << "button : " << button;
	//ofLogNotice("ofApp::mousePressed") << "position : " << position;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	carousel.drop();
	first = true;
	//ofLogNotice("ofApp::mouseReleased") << "x : " << x <<" y : " << y << "button : " << button;
	//ofLogNotice("ofApp::mouseReleased") << "position : " << position;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {
	//ofLogNotice("ofApp::dragEvent") ;
}

