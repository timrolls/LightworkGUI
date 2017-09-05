#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//Video Devices
	vector <ofVideoDevice> devices;
	devices = cam.listDevices();
	vector <string> deviceStrings;
	
	for (std::vector<ofVideoDevice>::iterator it = devices.begin(); it != devices.end(); ++it) {
		ofVideoDevice device = *it;
		string name = device.deviceName;
		int id = device.id;
		cout << "Device Name: " << id << name << endl;
		deviceStrings.push_back(name);
	}

	// Input
	cam.setDeviceID(0); // External webcam
	cam.setup(1280, 720);
	cam.setDesiredFrameRate(30); // This gets overridden by ofSetFrameRate

	ofxDatGui* gui = new ofxDatGui(100, 100);
	gui->setTheme(new ofxDatGuiThemeCharcoal());

	gui->addDropdown("Select Camera", deviceStrings);
	gui->addBreak();

	// add a dropdown menu //
	vector<string> opts = { "PixelPusher", "Fadecandy/Octo"};
	gui->addDropdown("Select Driver Type", opts);
	gui->addBreak();
	
	gui->addTextInput("IP", "127.0.0.1");
	gui->addTextInput("LEDS", "150");
	gui->addBreak();

	gui->addButton("Test LEDS");
	gui->addButton("Map LEDS");
	gui->addButton("Save Layout");
	gui->addBreak();

	gui->addFRM();


	// adding the optional header allows you to drag the gui around //
	gui->addHeader(":: drag me to reposition ::");

	// adding the optional footer allows you to collapse/expand the gui //
	gui->addFooter();
	
	// once the gui has been assembled, register callbacks to listen for component specific events //
	gui->onButtonEvent(this, &ofApp::onButtonEvent);
	//gui->onToggleEvent(this, &ofApp::onToggleEvent);
	//gui->onSliderEvent(this, &ofApp::onSliderEvent);
	gui->onTextInputEvent(this, &ofApp::onTextInputEvent);
	//gui->on2dPadEvent(this, &ofApp::on2dPadEvent);
	gui->onDropdownEvent(this, &ofApp::onDropdownEvent);
	//gui->onColorPickerEvent(this, &ofApp::onColorPickerEvent);
	//gui->onMatrixEvent(this, &ofApp::onMatrixEvent);



}

//--------------------------------------------------------------
void ofApp::update(){
	cam.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//Dropdown Handler
void ofApp::onDropdownEvent(ofxDatGuiDropdownEvent e)
{
	cout << "the option at index # " << e.child << " was selected " << endl;

	if (e.target->is("Select Camera")) {
		switchCamera(e.child);
	}
	
	if (e.target->is("Select Driver Type")) {
		if (e.child==0) {
			cout << "Pixel Pusher was selected" << endl;
		}
		else if (e.child==1) {
			cout << "Fadecandy/Octo was selected" << endl;
		}
	}
}


void ofApp::onTextInputEvent(ofxDatGuiTextInputEvent e)
{
	cout << "onTextInputEvent: " << e.target->getLabel() << " " << e.target->getText() << endl;
}

void ofApp::onButtonEvent(ofxDatGuiButtonEvent e)
{
	cout << "onButtonEvent: " << e.target->getLabel() << endl;
}


void ofApp::switchCamera(int num)
{
	cam.close();
	cam.setDeviceID(num);
	cam.setup(1280, 720);
}